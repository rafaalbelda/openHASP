/**
 * @file indev.h
 * 
 */

#ifndef INDEV_H
#define INDEV_H

// +AIRQ 1.4 - remove TOUCH
#if HASP_USE_TOUCH > 0
// -AIRQ 1.4 - remove TOUCH
/*********************
 *      INCLUDES
 *********************/
#include <stdbool.h>
#include <stdint.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void touchpad_init(void);

/**********************
 *      MACROS
 **********************/

#endif
// +AIRQ 1.4 - remove TOUCH
#endif // HASP_USE_TOUCH > 0
// -AIRQ 1.4 - remove TOUCH
