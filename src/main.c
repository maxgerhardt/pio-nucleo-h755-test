#include <stm32h7xx_hal.h>

#define LED_GPIO_PORT                   GPIOK
#define LED_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOK_CLK_ENABLE()
#define LED_PIN                         GPIO_PIN_3
//LED1=K3, LED2 = K4, LED3=K5, LED4=K6.

int main() {
    /* STM32H7xx HAL library initialization */
    HAL_Init();

    LED_GPIO_CLK_ENABLE();    
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin = LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct); 
      /* Main loop to toggle LEDs */
    while (1)
    {
        HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);
        HAL_Delay(1000); // Adjusting the delay as a quick test
    }
}

void SysTick_Handler(void)
{
    HAL_IncTick();
}

