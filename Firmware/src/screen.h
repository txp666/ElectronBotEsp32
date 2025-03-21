#ifndef ELECTRONBOT_FW_SCREEN_H
#define ELECTRONBOT_FW_SCREEN_H

#include <Arduino.h>
#include <SPI.h>

class Screen
{
public:
    explicit Screen(uint8_t csPin, uint8_t dcPin, uint8_t resetPin) : csPin(csPin), dcPin(dcPin), resetPin(resetPin)
    {
        pinMode(csPin, OUTPUT);
        pinMode(dcPin, OUTPUT);
        pinMode(resetPin, OUTPUT);
    }

    typedef enum Orientation_t
    {
        DEGREE_0,
        DEGREE_90,
        DEGREE_180,
        DEGREE_270
    } Orientation_t;

    typedef enum ColorMode_t
    {
        BIT_12,
        BIT_16,
        BIT_18
    } ColorMode_t;

    void Init(Orientation_t _orientation);

    void SetWindow(uint16_t _startX, uint16_t _endX, uint16_t _startY, uint16_t _endY);

    void WriteFrameBuffer(uint8_t *_buffer, uint32_t _len, bool _isAppend = false);

    void SetBackLight(float _val = 1.0f);

    volatile bool isBusy = false;

private:
    void ChipSelect(bool _enable);

    void Reset(bool _enable);

    void SetDataOrCommand(bool _isData);

    void WriteCommand(uint8_t _cmd);

    void Write1Byte(uint8_t _data);


    void WriteData(uint8_t *_data, uint32_t _len);

    uint8_t csPin;
    uint8_t dcPin;
    uint8_t resetPin;
    Orientation_t orientation = DEGREE_0;
    ColorMode_t colorMode = BIT_18;
};

#endif
