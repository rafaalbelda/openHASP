/* MIT License - Copyright (c) 2019-2022 Francis Van Roie
   For full license information read the LICENSE file in the project folder */

#if !(defined(WINDOWS) || defined(POSIX))

#include "hasplib.h"
#include "hasp_oobe.h"
#include "sys/net/hasp_network.h"
#include "dev/device.h"
// #include "drv/old/hasp_drv_touch.h"
#include "ArduinoLog.h"

#if HASP_USE_CONFIG > 0
#include "hasp_debug.h"
#include "hasp_macro.h"
#endif

#if HASP_USE_CONFIG > 0
#include "hasp_config.h"
#include "hasp_gui.h"
#endif

#if defined(HASP_USE_CUSTOM)
#include "custom/my_custom.h"
#endif

bool isConnected;
uint8_t mainLoopCounter        = 0;
unsigned long mainLastLoopTime = 0;

#ifdef HASP_USE_STAT_COUNTER
uint16_t statLoopCounter = 0; // measures the average looptime
#endif

void setup()
{
    //   hal_setup();

    haspDevice.init();

    /****************************
     * Storage initializations
     ***************************/
#if HASP_USE_EEPROM > 0
    eepromSetup(); // Don't start at boot, only at write
#endif

    // #if HASP_USE_SPIFFS > 0 || HASP_USE_LITTLEFS > 0
    //     filesystemSetup();  // FS mount is done in configSetup()
    // #endif

    // #if HASP_USE_SDCARD > 0
    //     sdcardSetup();
    // #endif

    /****************************
     * Read & Apply User Configuration
     ***************************/
#if HASP_USE_CONFIG > 0
    configSetup(); // also runs  debugSetup(), debugStart() and consoleSetup()
#endif
// +AIRQ
    Log.setLevel(0, LOG_LEVEL_OUTPUT);


    dispatchSetup(); // before hasp and oobe, asap after logging starts
// +AIRQ 1.3 - remove GUI
#if HASP_USE_GUI > 0
// -AIRQ 1.3 - remove GUI
    guiSetup();
// +AIRQ 1.3 - remove GUI
#endif
// -AIRQ 1.3 - remove GUI

#if HASP_USE_CONFIG > 0
    if(!oobeSetup())
#endif
    {
        haspSetup();
    }

    /****************************
     * Apply User Configuration
     ***************************/

#if HASP_USE_MQTT > 0
    mqttSetup(); // Load Hostname before starting WiFi
#endif

#if HASP_USE_GPIO > 0
    gpioSetup();
#endif

#if HASP_USE_WIFI > 0 || HASP_USE_ETHERNET > 0
    networkSetup();
#endif

#if HASP_USE_MDNS > 0
    mdnsSetup();
#endif

#if HASP_USE_OTA > 0
    otaSetup();
#endif

#if HASP_USE_HTTP > 0 || HASP_USE_HTTP_ASYNC > 0
    httpSetup();
#endif

    // #if HASP_USE_CONSOLE > 0
    //     consoleSetup(); // the consoleSetup is called in debugSetup
    // #endif

#if HASP_USE_TELNET > 0
    telnetSetup();
#endif

#if HASP_USE_FTP > 0
    ftpSetup();
#endif

#if HASP_USE_TASMOTA_CLIENT > 0
    slaveSetup();
#endif

#if defined(HASP_USE_CUSTOM)
    custom_setup();
#endif

    mainLastLoopTime = -1000; // reset loop counter
    delay(20);
    // guiStart();
}

IRAM_ATTR void loop()
{
// +AIRQ 1.3 - remove GUI
#if HASP_USE_GUI > 0
// -AIRQ 1.3 - remove GUI
    guiLoop();
// +AIRQ 1.3 - remove GUI
#endif
// -AIRQ 1.3 - remove GUI
    // haspLoop();

    networkLoop();

#if HASP_USE_GPIO > 0
    //  gpioLoop();
    // Should be called every 4-5ms or faster, for the default debouncing time of ~20ms.
    for(uint8_t i = 0; i < HASP_NUM_GPIO_CONFIG; i++) {
        if(gpioConfig[i].btn) gpioConfig[i].btn->check();
    }
#endif // GPIO

#if HASP_USE_MQTT > 0
    mqttClient.loop(); // mqttLoop();
#endif

    // haspDevice.loop();

#if HASP_USE_CONSOLE > 0
    // debugLoop();
    consoleLoop();
#endif

#if defined(HASP_USE_CUSTOM)
    custom_loop();
#endif

#ifdef HASP_USE_STAT_COUNTER
    statLoopCounter++; // measures the average looptime
#endif

    /* Timer Loop */
    if(millis() - mainLastLoopTime >= 1000) {
        mainLastLoopTime += 1000;

        /* Runs Every Second */
        haspEverySecond(); // sleep timer & statusupdate

#if HASP_USE_FTP > 0
        ftpEverySecond();
#endif

#if HASP_USE_TELNET > 0
        telnetEverySecond();
#endif

#if defined(HASP_USE_CUSTOM)
        custom_every_second();
#endif
        // debugEverySecond();

        switch(++mainLoopCounter) {
            case 1:
                haspDevice.loop_5s();
                break;

            case 2:
#if HASP_USE_HTTP_ASYNC > 0
                httpEvery5Seconds();
#endif
                break;

            case 3:
#if HASP_USE_GPIO > 0
                //   gpioEvery5Seconds();
#endif

#if defined(HASP_USE_CUSTOM)
                custom_every_5seconds();
#endif
                break;

            case 4:
                isConnected = networkEvery5Seconds(); // Check connection

#if HASP_USE_MQTT > 0
                mqttEvery5Seconds(isConnected);
#endif
                break;

            case 5:
                mainLoopCounter = 0;
#ifdef HASP_USE_STAT_COUNTER
                if(statLoopCounter)
                    LOG_DEBUG(TAG_MAIN, F("%d millis per loop, %d counted"), 5000 / statLoopCounter, statLoopCounter);
                statLoopCounter = 0;
#endif
                break;
        }
    }

#ifdef ARDUINO_ARCH_ESP8266
    delay(2); // ms
#else
    delay(3); // ms
              // delay((lv_task_get_idle() >> 5) + 3); // 2..5 ms
#endif
}

#endif
