#include <Arduino.h>

#if !defined(ARDUINO_ESP32C3_DEV) // This is due to a bug in RISC-V compiler, which requires unused function sections :-(.
#define DISABLE_CODE_FOR_RECEIVER // Disables static receiver code like receive timer ISR handler and static IRReceiver and irparams data. Saves 450 bytes program memory and 269 bytes RAM if receiving functions are not required.
#endif
#include "PinDefinitionsAndMore.h" // Define macros for input and output pin etc. Sets FLASHEND and RAMSIZE and evaluates value of SEND_PWM_BY_TIMER.
#include <IRremote.hpp> // include the library

#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char hexaKeys[ROWS][COLS] = { //Adding values without double quotes which makes IDE store it in BYTE format
  {0x1E,0x1F,0x18,0x19},
  {0x1A,0xE,0x1B,0xF},
  {0x6,0x12,0x7,0x13},
  {0xA,0x16,0xB,0x17}
};
byte RowDigpins[ROWS]={5,6,7,8};
byte ColDigpins[COLS]={10,11,12,A1};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), RowDigpins, ColDigpins, ROWS, COLS); 

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);

    // Just to know which program is running on my Arduino
    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));
    Serial.print(F("Send IR signals at pin "));
    Serial.println(IR_SEND_PIN);
}

uint8_t sCommand=0;
uint8_t sRepeats=3;
// byte arr[26]={0x18,0x4,0x8,0xC,0x10,0x14,0x19,0x5,0x9,0xD,0x11,0x15,0x1E,0x1A,0x6,0xE,
//               0x12,0x13,0xF,0x7,0x1B,0x1F,0xA,0xB,0x16,0x17}; ALL THE CODES OF THE REMOTE!
//byte arr[16]={0x1E,0x1F,0x1A,0x1B,0x6,0x7,0xA,0xB,0xE,0xF,0x12,0x13,0x16,0x17,0x18,0x19}; no need as directly using keypad value for sCommand

void loop() {
    sCommand = customKeypad.getKey();

    if (sCommand != 0){ //to avoid continuous printing
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX); //HEX converts integer to hexadecimal 
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();

    // Receiver output for the first loop must be: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    IrSender.sendNEC(0x00, sCommand, sRepeats);
    }
    sCommand=0; //reset the command value to 0 inorder to avoid repeated printing of previous value
    
    //delay(3000);  // delay must be greater than 5 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal

//codes written earlier to find the unknown buttons' commands

 /*   sCommand= 0x0;
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();

    // Receiver output for the first loop must be: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    IrSender.sendNEC(0x00, sCommand, sRepeats);
    delay(3000);

    sCommand= 0x1;
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();

    // Receiver output for the first loop must be: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    IrSender.sendNEC(0x00, sCommand, sRepeats);
    delay(3000);

    sCommand= 0x2;
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();

    // Receiver output for the first loop must be: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    IrSender.sendNEC(0x00, sCommand, sRepeats);
    delay(3000);

    sCommand= 0x3; 
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();

    // Receiver output for the first loop must be: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    IrSender.sendNEC(0x00, sCommand, sRepeats);
    delay(3000);

    sCommand= 0x20; 
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();
    IrSender.sendNEC(0x00, sCommand, sRepeats);
 delay(3000);
    // // Receiver output for the first loop must be: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    // IrSender.sendNEC(0x00, sCommand, sRepeats);
    // delay(2000);
    sCommand= 0x21; 
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();
    IrSender.sendNEC(0x00, sCommand, sRepeats);
 delay(3000);
 sCommand= 0x3D; 
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();
    IrSender.sendNEC(0x00, sCommand, sRepeats);
 delay(3000);
 sCommand= 0x3E; 
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();
    IrSender.sendNEC(0x00, sCommand, sRepeats);
 delay(3000);
 sCommand= 0x3F; 
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();
    IrSender.sendNEC(0x00, sCommand, sRepeats);
 delay(3000);
 sCommand= 0x40; 
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();
    IrSender.sendNEC(0x00, sCommand, sRepeats);
 delay(3000);
    sCommand= 0x1A;
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();

    // Receiver output for the first loop must be: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    IrSender.sendNEC(0x00, sCommand, sRepeats);
    delay(3000);  // delay must be greater than 5 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal
    
    sCommand= 0x1B;
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();

    // Receiver output for the first loop must be: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    IrSender.sendNEC(0x00, sCommand, sRepeats);
    delay(3000);

    sCommand= 0x1C;
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();

    // Receiver output for the first loop must be: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    IrSender.sendNEC(0x00, sCommand, sRepeats);
    delay(3000);

    sCommand= 0x1D;
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();

    // Receiver output for the first loop must be: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    IrSender.sendNEC(0x00, sCommand, sRepeats);
    delay(3000);

    sCommand= 0x1E; 
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();

    // Receiver output for the first loop must be: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    IrSender.sendNEC(0x00, sCommand, sRepeats);
    delay(3000);

    sCommand= 0x1F; 
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();
    IrSender.sendNEC(0x00, sCommand, sRepeats);
 delay(3000);
    // // Receiver output for the first loop must be: Protocol=NEC Address=0x102 Command=0x34 Raw-Data=0xCB340102 (32 bits)
    
    // delay(2000);
    sCommand= 0x3C; 
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();
    IrSender.sendNEC(0x00, sCommand, sRepeats);
 delay(3000);
 sCommand= 0x3D; 
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();
    IrSender.sendNEC(0x00, sCommand, sRepeats);
 delay(3000);
 sCommand= 0x3E; 
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();
    IrSender.sendNEC(0x00, sCommand, sRepeats);
 delay(3000);
 sCommand= 0x3F; 
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();
    IrSender.sendNEC(0x00, sCommand, sRepeats);
 delay(3000);
 sCommand= 0x40; 
    Serial.println();
    Serial.print(F("Send now: address=0x00, command=0x"));
    Serial.print(sCommand, HEX);
    Serial.print(F(", repeats="));
    Serial.print(sRepeats);
    Serial.println();

    Serial.println(F("Send standard NEC with 8 bit address"));
    Serial.flush();
    IrSender.sendNEC(0x00, sCommand, sRepeats);
 delay(3000); */
}

