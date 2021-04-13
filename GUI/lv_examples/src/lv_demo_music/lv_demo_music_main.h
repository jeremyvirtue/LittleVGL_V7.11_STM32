/**
 * @file lv_demo_music_main.h
 *
 */

#ifndef LV_DEMO_MUSIC_MAIN_H
#define LV_DEMO_MUSIC_MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "lv_demo_music.h"
#if LV_USE_DEMO_MUSIC

/*********************
 *      DEFINES
 *********************/
LV_FONT_DECLARE(lv_font_montserrat_10);//申明字体
LV_FONT_DECLARE(lv_font_montserrat_12);//申明字体
LV_FONT_DECLARE(lv_font_montserrat_30);//申明字体 
/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
lv_obj_t * _lv_demo_music_main_create(lv_obj_t * parent);
void _lv_demo_music_play(uint32_t id);
void _lv_demo_music_resume(void);
void _lv_demo_music_pause(void);
void _lv_demo_music_album_next(bool next);

/**********************
 *      MACROS
 **********************/
#endif /*LV_USE_DEMO_MUSIC*/


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_DEMO_MUSIC_MAIN_H*/
