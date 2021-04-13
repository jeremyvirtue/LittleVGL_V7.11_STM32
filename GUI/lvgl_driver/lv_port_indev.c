/**
 * @file lv_port_indev_templ.c
 *
 */

 /*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_indev.h"
#include "touch.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

//static void touchpad_init(void);
static bool touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data); 

/**********************
 *  STATIC VARIABLES
 **********************/
lv_indev_t * indev_touchpad;
// lv_indev_t * indev_mouse;
// lv_indev_t * indev_keypad;
// lv_indev_t * indev_encoder;
// lv_indev_t * indev_button;

// static int32_t encoder_diff;
// static lv_indev_state_t encoder_state;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_indev_init(void)
{ 
    lv_indev_drv_t indev_drv;

    /*------------------
     * Touchpad
     * -----------------*/

    /*Register a touchpad input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = touchpad_read;
    lv_indev_drv_register(&indev_drv);
    
}

/**********************
 *   STATIC FUNCTIONS
 **********************/



/*------------------
 * Touchpad
 * -----------------*/

/*Initialize your touchpad*/
//static void touchpad_init(void)
//{
//    /*Your code comes here*/
//}

/* Will be called by the library to read the touchpad */
static bool touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint16_t last_x = 0;
    static uint16_t last_y = 0;
    if(tp_dev.sta&TP_PRES_DOWN)//´¥Ãþ°´ÏÂÁË
    {
        last_x = tp_dev.x[0];
        last_y = tp_dev.y[0];
        data->point.x = last_x;
        data->point.y = last_y;
        data->state = LV_INDEV_STATE_PR;
    }else{
        data->point.x = last_x;
        data->point.y = last_y;
        data->state = LV_INDEV_STATE_REL;
    }
    /*Return `false` because we are not buffering and no more data to read*/
    return false;
}

 
  

#else /* Enable this file at the top */

/* This dummy typedef exists purely to silence -Wpedantic. */
typedef int keep_pedantic_happy;
#endif
