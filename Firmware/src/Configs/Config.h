#ifndef __CONFIG_H
#define __CONFIG_H

/*=========================
   Application configuration
 *=========================*/








/*=========================
   Hardware Configuration
 *=========================*/



/* Screen */

#define CONFIG_SCREEN_BLK_PIN       46

#define CONFIG_SCREEN_HOR_RES       240
#define CONFIG_SCREEN_VER_RES       240
#define CONFIG_SCREEN_BUFFER_SIZE   (CONFIG_SCREEN_HOR_RES * CONFIG_SCREEN_VER_RES /2)

/* Battery */
#define CONFIG_BAT_DET_PIN          37
#define CONFIG_BAT_CHG_DET_PIN      38

/* Buzzer */
#define CONFIG_BUZZ_PIN             25
#define CONFIG_BUZZ_CHANNEL         2
#define CONFIG_SOUND_ENABLE_DEFAULT true

/* IMU */
#define CONFIG_IMU_INT1_PIN         21
#define CONFIG_IMU_INT2_PIN         14

/* I2C */
#define CONFIG_MCU_SDA_PIN          21
#define CONFIG_MCU_SCL_PIN          14

/* Encoder */
#define CONFIG_ENCODER_B_PIN        34
#define CONFIG_ENCODER_A_PIN        35
#define CONFIG_ENCODER_PUSH_PIN     27

/* Power */
#define CONFIG_POWER_EN_PIN         21

/* Debug USART */
#define CONFIG_DEBUG_SERIAL         Serial

/* SD CARD */
#define CONFIG_SD_SPI               SPI_SD
#define CONFIG_SD_CD_PIN            -1
#define CONFIG_SD_MOSI_PIN          PB15
#define CONFIG_SD_MISO_PIN          PB14
#define CONFIG_SD_SCK_PIN           PB13
#define CONFIG_SD_CS_PIN            15
#define CONFIG_SD_DET_PIN           22

/* Stack Info */
#define CONFIG_USE_STACK_INFO       0

#endif
