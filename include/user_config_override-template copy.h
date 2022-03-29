/* MIT License - Copyright (c) 2019-2021 Francis Van Roie
   For full license information read the LICENSE file in the project folder */

/***************************************************
// This file contains the default settings that are
// burned into the compiled firmware.
//
// These default settings can be changed at runtime
//
// To use: Save a copy as user_config_override.h
***************************************************/
#ifndef HASP_USER_CONFIG_OVERRIDE_H
#define HASP_USER_CONFIG_OVERRIDE_H

#define SERIAL_SPEED 115200

/***************************************************
          WiFi Settings
 **************************************************/
#define WIFI_SSID ""
#define WIFI_PASSW ""

/***************************************************
          MQTT Settings
 **************************************************/
#define MQTT_HOST ""
#define MQTT_PORT 1883
#define MQTT_USER ""
#define MQTT_PASSW ""
#define MQTT_PREFIX "hasp"
#define MQTT_NODENAME "plate01"
#define MQTT_GROUPNAME "plates"

#define MQTT_TELEPERIOD 60000
#define MQTT_STATEPERIOD 300000

/***************************************************
 *        Server Settings
 **************************************************/
#define OTA_HOSTNAME ""
#define OTA_SERVER ""
#define OTA_PORT 80
#define OTA_URL ""
#define OTA_PASSWORD ""

/***************************************************
 *        Syslog Settings
 **************************************************/
#define SYSLOG_SERVER ""
#define SYSLOG_PORT 514
#define APP_NAME "HASP"

/***************************************************
 *        Timezone Settings
 **************************************************/
#define MYTZ                                                                                                           \
    "CET-1CEST,M3.5.0,M10.5.0/3" // A full list with possible timezones can be found here
                                 // https://gist.github.com/alwynallan/24d96091655391107939

/***************************************************
 *        Interface Language Settings
 **************************************************/
#define HASP_LANGUAGE en_US // English
// #define HASP_LANGUAGE es_ES                       // Spanish
// #define HASP_LANGUAGE fr_FR                       // French
// #define HASP_LANGUAGE hu_HU                       // Hungarian
// #define HASP_LANGUAGE nl_NL                       // Dutch
// #define HASP_LANGUAGE pt_BR                       // Brazilian Portuguese
// #define HASP_LANGUAGE pt_PT                       // Portuguese
// #define HASP_LANGUAGE ro_RO                       // Romanian

/***************************************************
 *        Web interface coloring
 **************************************************/
// Light theme (default)
#define D_HTTP_COLOR_TEXT "#000"          // Global text color - Black
#define D_HTTP_COLOR_BACKGROUND "#fff"    // Global background color - White
#define D_HTTP_COLOR_INPUT_TEXT "#000"    // Input text color - Black
#define D_HTTP_COLOR_INPUT "#fff"         // Input background color - White
#define D_HTTP_COLOR_INPUT_WARNING "#f00" // Input warning border color - Red
#define D_HTTP_COLOR_BUTTON_TEXT "#fff"   // Button text color - White
#define D_HTTP_COLOR_BUTTON "#1fa3ec"     // Button color - Vivid blue
#define D_HTTP_COLOR_BUTTON_RESET "#f00"  // Restart/Reset button color - red

/*
// Dark theme
#define D_HTTP_COLOR_TEXT               "#eaeaea"    // Global text color - Very light gray
#define D_HTTP_COLOR_BACKGROUND         "#252525"    // Global background color - Very dark gray (mostly black)
#define D_HTTP_COLOR_INPUT_TEXT         "#000"       // Input text color - Black
#define D_HTTP_COLOR_INPUT              "#ddd"       // Input background color - Very light gray
#define D_HTTP_COLOR_INPUT_WARNING      "#ff5661"    // Warning text color - Brick Red
#define D_HTTP_COLOR_BUTTON_TEXT        "#faffff"    // Button text color - Very pale (mostly white) cyan
#define D_HTTP_COLOR_BUTTON             "#1fa3ec"    // Button color - Vivid blue
#define D_HTTP_COLOR_BUTTON_RESET       "#d43535"    // Restart/Reset/Delete button color - Strong red
*/

/***************************************************
 *        Font Settings
 **************************************************/
// #define HASP_FONT_1 robotocondensed_regular_16_latin1 // Use available fonts from src/fonts directory
// #define HASP_FONT_2 robotocondensed_regular_22_latin1
// #define HASP_FONT_3 robotocondensed_regular_40_latin1
// #define HASP_FONT_4 robotocondensed_regular_48_latin1

// #define ROBOTOCONDENSED_REGULAR_16_LATIN1 1           // Enable the selected fonts
// #define ROBOTOCONDENSED_REGULAR_22_LATIN1 1
// #define ROBOTOCONDENSED_REGULAR_40_LATIN1 1
// #define ROBOTOCONDENSED_REGULAR_48_LATIN1 1

// #define HASP_FONT_SIZE_1 16                           // Define used font sizes
// #define HASP_FONT_SIZE_2 22
// #define HASP_FONT_SIZE_3 40
// #define HASP_FONT_SIZE_4 48

#define LV_FONT_DEFAULT &HASP_FONT_1

/***************************************************
 *        GPIO Settings
 **************************************************/
//#define HASP_GPIO_TEMPLATE "[197658,263456,329249,655628,655886,656155,0,0]"  // Lanbon L8 3-gang GPIO config
//#define HASP_GPIO_TEMPLATE "[3214348,197658,263456,329249,94699520,0,0,0]" // Lanbon L8 Dimmer GPIO config

/***************************************************
 *        Other Settings
 **************************************************/
//#define HASP_USE_HA                                 // Enable Home Assistant auto-discovery

#endif