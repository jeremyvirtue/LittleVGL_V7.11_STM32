#include "../../../lv_examples.h"
#if LV_USE_IMG

/* Find the image here: https://github.com/lvgl/lv_examples/tree/master/assets */
LV_IMG_DECLARE(img_cogwheel_argb);
LV_IMG_DECLARE(photo);

lv_task_t* task1 = NULL;//任务句柄指针
lv_obj_t* img1;
void task1_cb(lv_task_t* task)  {
    static int angle = 0;
    angle += 1;
    if (angle >= 3600)
        angle = 0;
    lv_img_set_angle(img1, angle);

}
void lv_ex_img_1(void)
{
    img1 = lv_img_create(lv_scr_act(), NULL); 
    lv_img_set_src(img1, &photo);
    lv_obj_align(img1, NULL, LV_ALIGN_CENTER, 0, -20);

    //lv_img_set_angle(img1, 458);


    lv_obj_t * img2 = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img2, LV_SYMBOL_OK "Accept");
    lv_obj_align(img2, img1, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
    task1 = lv_task_create(task1_cb, 10, LV_TASK_PRIO_MID, NULL);
}

#endif
