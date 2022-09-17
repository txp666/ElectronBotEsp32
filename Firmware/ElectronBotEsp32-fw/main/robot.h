#pragma once

#include "driver/i2c.h"
#include "esp_log.h"
#define ANY 0


class Robot
{

public:
    Robot()
    {
        /********* Need to adjust parameters for specific hardware *********/
        joint[ANY] = JointStatus_t{
            0,
            -180,
            180,
            90};

        joint[1] = JointStatus_t{
            // Head
            2,
            70,
            95,
            0,
            -15,
            15,
            true};

        joint[2] = JointStatus_t{
            // Left arm roll
            4,
            -9,
            3,
            0,
            0,
            30,
            false};

        joint[3] = JointStatus_t{
            // Left arm pitch
            6,
            -16,
            117,
            0,
            -20,
            180,
            false};

        joint[4] = JointStatus_t{
            // Right arm roll
            8,
            133,
            141,
            0,
            0,
            30,
            true};

        joint[5] = JointStatus_t{
            // Right arm pitch
            10,
            15,
            150,
            0,
            -20,
            180,
            true};

        joint[6] = JointStatus_t{
            // Body
            12,
            0,
            180,
            0,
            -90,
            90,
            false};
        /********* Need to adjust parameters for specific hardware *********/
    }

    struct UsbBuffer_t
    {
        uint8_t extraDataTx[32];
        uint8_t rxData[2][60 * 240 * 3 + 32]; // 43232bytes, 43200 of which are lcd buffer
        volatile uint16_t receivedPacketLen = 0;
        volatile uint8_t pingPongIndex = 0;
        volatile uint32_t rxDataOffset = 0;
    };
    UsbBuffer_t usbBuffer;
    struct JointStatus_t
    {
        uint8_t id;
        float angleMin;
        float angleMax;
        float angle;
        float modelAngelMin;
        float modelAngelMax;
        bool inverted = false;
    };
    JointStatus_t joint[7];

    uint8_t *GetPingPongBufferPtr();
    uint8_t *GetLcdBufferPtr();
    uint8_t *GetExtraDataRxPtr();
    void SwitchPingPongBuffer();
    void SendUsbPacket(uint8_t *_data, uint32_t _len);
    void ReceiveUsbPacketUntilSizeIs(uint32_t _count);
    void SetJointId(JointStatus_t &_joint, uint8_t _id);
    void SetJointKp(JointStatus_t &_joint, float _value);
    void SetJointKi(JointStatus_t &_joint, float _value);
    void SetJointKv(JointStatus_t &_joint, float _value);
    void SetJointKd(JointStatus_t &_joint, float _value);
    void SetJointEnable(JointStatus_t &_joint, bool _enable);
    void SetJointInitAngle(JointStatus_t &_joint, float _angle);
    void SetJointTorqueLimit(JointStatus_t &_joint, float _percent);

    void UpdateServoAngle(JointStatus_t &_joint);
    void UpdateServoAngle(JointStatus_t &_joint, float _angleSetPoint);
    void UpdateJointAngle(JointStatus_t &_joint);
    void UpdateJointAngle(JointStatus_t &_joint, float _angleSetPoint);

private:
    uint8_t i2cRxData[8];
    uint8_t i2cTxData[8];

    void TransmitAndReceiveI2cPacket(uint8_t _id);
};


