/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "player/player.h"
#include <stdbool.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
bool g_is_tick_update = false;
bool g_is_sr_update = false;
// GPIO_PinState g_gpio_buffer[NUM_AUDIO_CHANNEL] = { GPIO_PIN_SET,GPIO_PIN_SET,GPIO_PIN_SET,GPIO_PIN_SET };
uint32_t g_gpio_buffer = 0u;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim) {
    if (htim == &htim2) {
        g_is_sr_update = true;
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
    }
    else if (htim == &htim3) {
        g_is_tick_update = true;
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
    }
}

static void Keil_Play(void) {
    Player_t keil_player;
    Player_Init(&keil_player);

    while (true) {
        if (g_is_tick_update) {
            g_is_tick_update = false;
            Player_NextLine(&keil_player);
        }

        if (g_is_sr_update) {
            g_is_sr_update = false;

            // update gpio
            // HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, g_gpio_buffer[0]);
            // HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, g_gpio_buffer[1]);
            // HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, g_gpio_buffer[2]);
            // HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, g_gpio_buffer[3]);
            GPIOA->BSRR = g_gpio_buffer;

            Player_SampleTick(&keil_player);
            // g_gpio_buffer[0] = Player_ReadOutput(&keil_player, 0) == 0 ? GPIO_PIN_SET : GPIO_PIN_RESET;
            // g_gpio_buffer[1] = Player_ReadOutput(&keil_player, 1) == 0 ? GPIO_PIN_SET : GPIO_PIN_RESET;
            // g_gpio_buffer[2] = Player_ReadOutput(&keil_player, 2) == 0 ? GPIO_PIN_SET : GPIO_PIN_RESET;
            // g_gpio_buffer[3] = Player_ReadOutput(&keil_player, 3) == 0 ? GPIO_PIN_SET : GPIO_PIN_RESET;
            g_gpio_buffer = 0;
            g_gpio_buffer |= (Player_ReadOutput(&keil_player, 0) == 0 ? GPIO_PIN_1 << 16 : GPIO_PIN_1);
            g_gpio_buffer |= (Player_ReadOutput(&keil_player, 1) == 0 ? GPIO_PIN_2 << 16 : GPIO_PIN_2);
            g_gpio_buffer |= (Player_ReadOutput(&keil_player, 2) == 0 ? GPIO_PIN_3 << 16 : GPIO_PIN_3);
            g_gpio_buffer |= (Player_ReadOutput(&keil_player, 3) == 0 ? GPIO_PIN_4 << 16 : GPIO_PIN_4);
        }
    }
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  HAL_TIM_Base_Start_IT(&htim3);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
      Keil_Play();
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
