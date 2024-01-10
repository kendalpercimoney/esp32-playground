#include "SevSeg.h"
SevSeg sevseg; //Initiate controller object

int checkState = 1;

void setup() {
    byte numDigits = 4;  
    byte digitPins[] = {10, 11, 12, 13};
    byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};
    bool resistorsOnSegments = 0; 
    // variable above indicates that 4 resistors were placed on the digit pins.
    // set variable to 1 if you want to use 8 resistors on the segment pins.
    sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(20);
}


void loop() {
    sevseg.setChars("heyy");
    //sevseg.setNumber(3141, 4);
    sevseg.refreshDisplay(); // Must run repeatedly
    
}
     