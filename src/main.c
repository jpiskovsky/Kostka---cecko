#include "main.h"
#include "daughterboard.h"
#include "milis.h"
#include "stm8s.h"

// #include "delay.h"
// #include <stdio.h>
// #include "uart1.h"

void setup(void) {
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);

    GPIO_Init(LED1_PORT, LED1_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED2_PORT, LED2_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED3_PORT, LED3_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED4_PORT, LED4_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED5_PORT, LED5_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED6_PORT, LED6_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED7_PORT, LED7_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED8_PORT, LED8_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);

    GPIO_Init(S1_PORT, S1_PIN, GPIO_MODE_IN_PU_NO_IT);

    init_milis();
    // init_uart1();
}

int main(void) {

    uint32_t time = 0;
    uint8_t i = 1;
    uint8_t cube[7] = {
        0b00000000, // 0
        0b00100000, // 1
        0b10000001, // 2
        0b10100001, // 3
        0b11000011, // 4
        0b11100011, // 5
        0b11011011, // 6
    };

    setup();

    while (1) {
        if (GPIO_ReadInputPin(S1_PORT, S1_PIN) == 0) {
            i += 1;
            if (i > 6) {
                i = 1;
            }
        } else {
            GPIO_Write(GPIOG, cube[i]);
        }
    }
}

/*uint32_t time = 0;
   uint8_t stisk = 0;
   uint8_t bagr = 0;
   uint8_t stisk2 = 0;
   int x = 1;

   setup();
   while (1) {

       if (milis() - time > 20) {
           time = milis();

           if (GPIO_ReadInputPin(S1_PORT, S1_PIN) == 0) {
               stisk = 1;
           } else {
               if (stisk == 1) {

                   switch (x) {
                   case 1:
                       REVERSE(LED6);
                       break;
                   case 2:
                       REVERSE(LED6);
                       break;
                   case 3:
                       REVERSE(LED7);
                       break;
                   case 4:
                       REVERSE(LED7);
                       break;
                   case 5:
                       REVERSE(LED8);
                       break;
                   case 6:
                       REVERSE(LED8);
                       break;
                   }
                   x++;
                   if (x == 7) {
                       x = 1;
                   }
               }

               stisk = 0;
           }
       }
   }*/



