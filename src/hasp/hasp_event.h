/* MIT License - Copyright (c) 2019-2022 Francis Van Roie
   For full license information read the LICENSE file in the project folder */

#ifndef HASP_EVENT_H
#define HASP_EVENT_H

#include "lvgl.h"
#include "hasp_conf.h"
// +AIRQ 1.3 - remove GUI
#if HASP_USE_GUI > 0
// -AIRQ 1.3 - remove GUI

#define HASP_NUM_PAGE_PREV (HASP_NUM_PAGES + 1)
#define HASP_NUM_PAGE_BACK (HASP_NUM_PAGES + 2)
#define HASP_NUM_PAGE_NEXT (HASP_NUM_PAGES + 3)

// Timer event Handlers
void event_timer_calendar(lv_task_t* task);
void event_timer_clock(lv_task_t* task);

// Object event Handlers
void delete_event_handler(lv_obj_t* obj, lv_event_t event);
void first_touch_event_handler(lv_obj_t* obj, lv_event_t event);
void generic_event_handler(lv_obj_t* obj, lv_event_t event);
void toggle_event_handler(lv_obj_t* obj, lv_event_t event);
void slider_event_handler(lv_obj_t* obj, lv_event_t event);
void selector_event_handler(lv_obj_t* obj, lv_event_t event);
void btnmatrix_event_handler(lv_obj_t* obj, lv_event_t event);
void msgbox_event_handler(lv_obj_t* obj, lv_event_t event);
void cpicker_event_handler(lv_obj_t* obj, lv_event_t event);
void calendar_event_handler(lv_obj_t* obj, lv_event_t event);
void textarea_event_handler(lv_obj_t* obj, lv_event_t event);

<<<<<<< Updated upstream
// Other functions
void event_reset_last_value_sent();

=======
// +AIRQ 1.3 - remove GUI
#endif // HASP_USE_GUI > 0
// -AIRQ 1.3 - remove GUI
>>>>>>> Stashed changes
#endif // HASP_EVENT_H