/* MIT License - Copyright (c) 2019-2022 Francis Van Roie
   For full license information read the LICENSE file in the project folder */

#ifndef HASP_H
#define HASP_H

#ifdef ARDUINO
#include <Arduino.h>
#endif

#include "hasplib.h"

#if HASP_USE_DEBUG > 0
#include "../hasp_debug.h"
#include "dev/device.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#if HASP_USE_APP > 0

/*********************
 *      DEFINES
 *********************/
#define HASP_SLEEP_OFF 0
#define HASP_SLEEP_SHORT 1
#define HASP_SLEEP_LONG 2

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a hasp application
 */
void haspSetup(void);
IRAM_ATTR void haspLoop(void);
void haspEverySecond(void);

void haspReconnect(void);
void haspDisconnect(void);

// void haspBackground(uint16_t pageid, uint16_t imageid);

// void haspNewObject(const JsonObject & config, uint8_t & saved_page_id);

void haspProgressVal(uint8_t val);

#if HASP_USE_CONFIG > 0
bool haspGetConfig(const JsonObject& settings);
bool haspSetConfig(const JsonObject& settings);
#endif

// +AIRQ 1.3 - remove GUI
#if HASP_USE_GUI > 0
// -AIRQ 1.3 - remove GUI
lv_font_t* hasp_get_font(uint8_t fontid);
// +AIRQ 1.3 - remove GUI
#endif // HASP_USE_GUI > 0
// -AIRQ 1.3 - remove GUI

HASP_ATTRIBUTE_FAST_MEM void hasp_update_sleep_state();
void hasp_get_sleep_state(char* payload);
void hasp_set_sleep_state(uint8_t state);
void hasp_get_sleep_time(uint16_t& short_time, uint16_t& long_time);
void hasp_set_sleep_time(uint16_t short_time, uint16_t long_time);
// +AIRQ 1.3 - remove GUI
#if HASP_USE_GUI > 0
// -AIRQ 1.3 - remove GUI
void hasp_set_wakeup_touch(bool en);
void hasp_set_antiburn(int32_t repeat_count,uint32_t period);
hasp_event_t hasp_get_antiburn();

void hasp_init(void);
// +AIRQ 1.3 - remove GUI
#if HASP_USE_GUI > 0
// -AIRQ 1.3 - remove GUI
void hasp_load_json(void);
// +AIRQ 1.3 - remove GUI
#endif // HASP_USE_GUI > 0
// -AIRQ 1.3 - remove GUI

void hasp_get_info(JsonDocument& info);
void hasp_set_theme(uint8_t themeid);

/**********************
 *      MACROS
 **********************/

#endif /*HASP_USE_APP*/

#ifdef __cplusplus
} /* extern "C" */
#endif

// +AIRQ 1.3 - remove GUI
#if HASP_USE_GUI > 0
// -AIRQ 1.3 - remove GUI
void haspProgressMsg(const char* msg);
#ifdef ARDUINO
void haspProgressMsg(const __FlashStringHelper* msg);
#endif
// +AIRQ 1.3 - remove GUI
#endif // HASP_USE_GUI > 0
// -AIRQ 1.3 - remove GUI

#endif /*HASP_H*/
