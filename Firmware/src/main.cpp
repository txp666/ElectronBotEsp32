#include "robot.h"
#include "HAL/HAL.h"
#include "Port/Display.h"
#include "App/image.h"

Robot electron;
TaskHandle_t motorTaskHandle;

void motorTask(void *parameter);

void setup()
{
  // Wire.begin(21, 14); // sda 21,scl 14
  HAL::Init();
  Port_Init();
  INIT_DONE();
  excited1_animing();
  vTaskDelay(2000);
  xTaskCreate(
      motorTask,
      "motor Task",
      2048,
      NULL,
      5,
      &motorTaskHandle);

}

void loop()
{

  HAL::Update();

  delay(20);
}
void motorTask(void *parameter)
{
  while (1)
  {
    int n = 1; // 1-6
    electron.joint[n].angleMin = 0;
    electron.joint[n].angleMax = 180;
    electron.joint[n].angle = 0;
    electron.joint[n].modelAngelMin = -90;
    electron.joint[n].modelAngelMax = 90;
    electron.SetJointEnable(electron.joint[n], true);

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
    }
  }
}
