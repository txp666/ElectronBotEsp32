
#include <stdio.h>
#include "esp_log.h"
#include "driver/i2c.h"
#include "robot.h"

static const char *TAG = "i2c-simple-example";

#define I2C_MASTER_SCL_IO CONFIG_I2C_MASTER_SCL /*!< GPIO number used for I2C master clock */
#define I2C_MASTER_SDA_IO CONFIG_I2C_MASTER_SDA /*!< GPIO number used for I2C master data  */
#define I2C_MASTER_NUM I2C_NUM_0                /*!< I2C master i2c port number, the number of i2c peripheral interfaces available will depend on the chip */
#define I2C_MASTER_FREQ_HZ 100000               /*!< I2C master clock frequency */
#define I2C_MASTER_TX_BUF_DISABLE 0             /*!< I2C master doesn't need buffer */
#define I2C_MASTER_RX_BUF_DISABLE 0             /*!< I2C master doesn't need buffer */

/**
 * @brief i2c master initialization
 */

int I2C_Init(void)
{
    int i2c_master_port = I2C_MASTER_NUM;
    static i2c_config_t conf;
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = I2C_MASTER_SDA_IO;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
    conf.scl_io_num = I2C_MASTER_SCL_IO;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
    conf.master.clk_speed = I2C_MASTER_FREQ_HZ;
    i2c_param_config(i2c_master_port, &conf);
    return i2c_driver_install(i2c_master_port, conf.mode, I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE, 0);
}

Robot electron;
extern "C" void app_main()
{
    int a;
    vTaskDelay(300);
    int *Mytimeout = &a;
    ESP_ERROR_CHECK(I2C_Init());
    ESP_LOGI(TAG, "I2C initialized successfully");
    i2c_get_timeout(I2C_NUM_0, Mytimeout);
    ESP_LOGI(TAG, "timeout  %d", a);
    int n = 1;
    int high_period;
    int low_period;
    i2c_get_period(I2C_NUM_0, &high_period, &low_period);
    ESP_LOGI(TAG, "high_period  %d   low_period   %d", high_period, low_period);
    int setup_time;
    int hold_time;
    i2c_get_start_timing(I2C_NUM_0, &setup_time, &hold_time);
    ESP_LOGI(TAG, "setup_time  %d   hold_time   %d", setup_time, hold_time);
    int stopsetup_time;
    int stophold_time;
    i2c_get_stop_timing(I2C_NUM_0, &stopsetup_time, &stophold_time);
    ESP_LOGI(TAG, "stopsetup_time  %d   stophold_time   %d", stopsetup_time, stophold_time);




    ESP_LOGI(TAG, "开始了");
    electron.joint[n].angleMin = 0;
    ESP_LOGI(TAG, "设置了angleMin");
    electron.joint[n].angleMax = 180;
    electron.joint[n].angle = 0;
    electron.joint[n].modelAngelMin = -90;
    electron.joint[n].modelAngelMax = 90;
    ESP_LOGI(TAG, "modelAngelMax");
    electron.SetJointEnable(electron.joint[n], true);
    ESP_LOGI(TAG, "设置了");
    while (1)
    {
        for (int i = -90; i < 90; i += 1)
        {
            float angle = i;
            electron.UpdateJointAngle(electron.joint[n], angle);

            vTaskDelay(20);
        }
        for (int i = 90; i > -90; i -= 1)
        {
            float angle = i;
            electron.UpdateJointAngle(electron.joint[n], angle);

            vTaskDelay(20);
        }
    }
}
