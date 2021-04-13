#include "sys.h"
#include "delay.h"  
#include "usart.h"   
#include "led.h"
#include "lcd.h"
#include "key.h"  
#include "touch.h" 
#include "timer.h"
#include "sram.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"   
#include "lv_examples/lv_examples.h"
 
 
// #define TEST_NUM	1 
//LV_IMG_DECLARE(photo);

//lv_task_t* task1 = NULL;//������ָ��
//lv_obj_t* img1;
//void task1_cb(lv_task_t* task)  {
//    static int angle = 0;
//    angle += 50;
//    if (angle > 3600)
//        angle = 0;
//    lv_img_set_angle(img1, angle);

//}
//void lv_ex_img_1(void)
//{
//    img1 = lv_img_create(lv_scr_act(), NULL); 
//    lv_img_set_src(img1, &photo);
//    lv_obj_align(img1, NULL, LV_ALIGN_CENTER, 0, -20);

//    //lv_img_set_angle(img1, 458);


//    lv_obj_t * img2 = lv_img_create(lv_scr_act(), NULL);
//    lv_img_set_src(img2, LV_SYMBOL_OK "Accept");
//    lv_obj_align(img2, img1, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
//    task1 = lv_task_create(task1_cb, 10, LV_TASK_PRIO_MID, NULL);
//}

 
int main(void)
{ 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);  //��ʼ����ʱ����
	uart_init(115200);		//��ʼ�����ڲ�����Ϊ115200
	
	LED_Init();					//��ʼ��LED 
 	LCD_Init();					//LCD��ʼ�� 
	KEY_Init(); 				//������ʼ��  
	TIM3_Int_Init(999,83);	//��ʱ����ʼ��(1ms�ж�),���ڸ�lvgl�ṩ1ms����������
	
	FSMC_SRAM_Init();		//��ʼ���ⲿsram
	tp_dev.init();				//��������ʼ��
	
		lv_init();						//lvglϵͳ��ʼ��
	lv_port_disp_init();	//lvgl��ʾ�ӿڳ�ʼ��,����lv_init()�ĺ���
	lv_port_indev_init();	//lvgl����ӿڳ�ʼ��,����lv_init()�ĺ���
	
	//ͨ��TEST_NUM��ֵ��ѡ�����в�ͬ������
// lv_ex_img_1();
//	lv_demo_stress();
//	lv_ex_img_1();
// 	lv_demo_widgets(); 
lv_demo_keypad_encoder();
//lv_ex_cpicker_2();
	while(1){
		tp_dev.scan(0);
		lv_task_handler();
	}
}
