/*
File: q1.cpp
Triggered when a specific CAN frame is received
    Analog read PIN_PC0,
    Send the reading over CAN.
While this happens, make an LED turn on to indicate activity.
    This LED is connected to PIN_PD2.
The CAN frames are received and sent via an MCP2515 CAN controller.
    It is connected via SPI with CS on PIN_PB2.
    The crystal is 20MHz and the CAN speed is 500kbps.
*/

// include the necessary libraries
#include <Arduino.h>
#include <mcp2515.h>

// pin consts
const int CS_PIN = 10;/*TODO*/ // CAN pin
const int PIN_LED = 2;/*TODO*/ // LED pin
const int PIN_PC0 = 14;/*TODO*/ // SomeinputIguess pin

// create MCP2515 object
MCP2515 CAN1(CS_PIN); //1 indexing

void setup() {
    // set the pinMode on the input pin
    pinMode(PIN_PC0, INPUT);
    // set the pinMode on the LED pin
    pinMode(PIN_LED, OUTPUT);
    // initialize the CAN controller at 500kbps
    CAN1.reset();
    CAN1.setBitrate(500000); // 500kbps
    CAN1.setNormalMode();
}

void loop() {
    // create CAN frame objects
    // make one for receiving, another for transmitting
    struct can_frame txFrame; // transmitting
    struct can_frame rxFrame; // recieving

    // check if a CAN frame is received
    if (CAN1.readMessage(&rxFrame) == MCP2515::ERROR_OK) {
        // check if the received frame is of ID 0x420 and first data byte is 0x69
        if (rxFrame.can_id == 0x420 && rxFrame.data[0] == 0x69) {
            // turn on the LED to indicate activity
            digitalWrite(PIN_LED, HIGH);
            
            // read the analog value from the input pin and store it as a variable
            analogValue = analogRead(PIN_PC0, HIGH);
            
            // prepare the CAN frame to send
            txFrame.can_id = 0x690; // replace with desired send ID
            txFrame.can_dlc = 2; // data length code
            txFrame.data[0] = (analogValue >> 8) & 0xFF; // high byte
            txFrame.data[1] = analogValue & 0xFF; // low byte
            
            // send the CAN frame
            CAN1.sendMessage(&txFrame);
            
            // turn off the LED after sending
            digitalWrite(PIN_LED, LOW);
        }
    }
}