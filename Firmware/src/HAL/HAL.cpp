#include "HAL/HAL.h"
#include "Configs/Version.h"

#define DISP_HOR_RES         CONFIG_SCREEN_HOR_RES
#define DISP_VER_RES         CONFIG_SCREEN_VER_RES
#define DISP_BUF_SIZE        CONFIG_SCREEN_BUFFER_SIZE
extern lv_color_t* lv_disp_buf_p;

void HAL::Init()
{
    Serial.begin(115200);
    Serial.println(VERSION_FIRMWARE_NAME);
    Serial.println("Version: " VERSION_SOFTWARE);
    Serial.println("Author: " VERSION_AUTHOR_NAME);

    // Move the malloc process to Init() to make sure that the largest heap can be used for this buffer.
    lv_disp_buf_p = static_cast<lv_color_t*>(malloc(DISP_BUF_SIZE * sizeof(lv_color_t)));
    if (lv_disp_buf_p == nullptr)
        LV_LOG_WARN("lv_port_disp_init malloc failed!\n");

   
    HAL::Backlight_Init();
   // HAL::I2C_Init(true);
    //HAL::IMU_Init();
  
}

void HAL::Update()
{
   
   // HAL::IMU_Update();

}
