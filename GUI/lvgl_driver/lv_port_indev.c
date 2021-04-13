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

 

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_indev_init(void)
{
    /* Here you will find example implementation of input devices supported by LittelvGL:
     *  - Touchpad
     *  - Mouse (with cursor support)
     *  - Keypad (supports GUI usage only with key)
     *  - Encoder (supports GUI usage only with: left, right, push)
     *  - Button (external buttons to press points on the screen)
     *
     *  The `..._read()` function are only examples.
     *  You should shape them according to your hardware
     */

    // lv_indev_drv_t indev_drv;

    // /*------------------
    //  * Touchpad
    //  * -----------------*/

    // /*Initialize your touchpad if you have*/
    // touchpad_init();

    // /*Register a touchpad input device*/
    // lv_indev_drv_init(&indev_drv);
    // indev_drv.type = LV_INDEV_TYPE_POINTER;
    // indev_drv.read_cb = touchpad_read;
    // indev_touchpad = lv_indev_drv_register(&indev_drv); 

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
    if(tp_dev.sta&TP_PRES_DOWN)//����������
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
