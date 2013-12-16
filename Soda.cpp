#include "Arduino.h"
#include "Soda.h"

void Soda::pins(int a, int b, int c, int d, int e, int f, int g, int dp, boolean common) {

    _a=a;
    _b=b;
    _c=c;
    _d=d;
    _e=e;
    _f=f;
    _g=g;
    _dp=dp;
    _common=common;

    segmentPins[0] = _dp;
    segmentPins[1] = _g;
    segmentPins[2] = _f;
    segmentPins[3] = _e;
    segmentPins[4] = _d;
    segmentPins[5] = _c;
    segmentPins[6] = _b;
    segmentPins[7] = _a;

    for(int i=0; i < 8; i++) {

        pinMode(segmentPins[i], OUTPUT);
    }
}

void Soda::write(int number) {

    const byte numeral[10] = {
        B11111100,  // 0
        B00110000,  // 1
        B11011010,  // 2
        B01111010,  // 3
        B00110110,  // 4
        B01101110,  // 5
        B11101110,  // 6
        B10001100,  // 7
        B11111110,  // 8
        B01111110,  // 9
    };

    boolean isBitSet;

    for(int segment=1; segment < 8; segment++) {
        if(number < 0 || number > 9) {
            isBitSet = 0;
        }
        else{
            isBitSet = bitRead(numeral[number], segment);
        }
        isBitSet = ! isBitSet;
        digitalWrite(segmentPins[segment], isBitSet);
    }
}

void Soda::setDecimalPoint(int digit, boolean decimalState) {

    _digit=digit;
    _decimalState=decimalState;

    if(_digit == 1) {

        if (_decimalState == HIGH && _common == HIGH) {
            digitalWrite(_dp, LOW);
        }
        if (_decimalState == HIGH && _common == LOW) {
            digitalWrite(_dp, HIGH);
        }
        if (_decimalState == LOW && _common == HIGH) {
            digitalWrite(_dp, HIGH);
        }
        if (_decimalState == LOW && _common == LOW) {
            digitalWrite(_dp, LOW);
        }
    }
}