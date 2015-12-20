/**
 * Test: Passed
 */
#ifndef _MY_LED_H
#define _MY_LED_H

#define LED_GREEN   ((uint16_t)0x1000)
#define LED_ORANGE  ((uint16_t)0x2000)  
#define LED_RED     ((uint16_t)0x4000)  
#define LED_BLUE    ((uint16_t)0x8000)  

/*-------------------------------- Prototype --------------------------------*/
void my_led_init(void);
void my_led_on(uint16_t leds);
void my_led_off(uint16_t leds);

#endif
