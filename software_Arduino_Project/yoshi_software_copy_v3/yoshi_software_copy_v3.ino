
/*
Pins for Display: 3,3V,GND
SDA= D21
SCK= D22
*/


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <AccelStepper.h>
#include <Arduino.h>
#include <ESP32RotaryEncoder.h>










/// MOTOR SACHEN ///////////////////////////////////////////////////////////////
#define INTERFACETYPE 1 // Muss festgelegt werden
#define ROLL_STEP 17
#define ROLL_DIR 16
#define ENABLE_ROLL 32
#define ENABLE_GUIDE 13


bool directionToEnd = true;
long endposition = 20000;
// Zeitvariablen
unsigned long previousMillis = 0;
const unsigned long interval = 1000;  // 1000 Millisekunden
unsigned long currentMillis;

#define GUIDE_STEP 19
#define GUIDE_DIR 18

AccelStepper roll(INTERFACETYPE,ROLL_STEP, ROLL_DIR);
AccelStepper guide(INTERFACETYPE,GUIDE_STEP, GUIDE_DIR);
//////////////////////////////////////////////////////////////////////////////






// Change these to the actual pin numbers that you've connected your rotary encoder to
const int8_t  DO_ENCODER_VCC = 27; // VCC
const int8_t  DI_ENCODER_SW  = 33; // NOT RLY NEEDED
const uint8_t DI_ENCODER_A   = 25; // CLK
const uint8_t DI_ENCODER_B   = 26; // DT
int sw  = 0;
long currentPos = 0;
RotaryEncoder rotaryEncoder( DI_ENCODER_A, DI_ENCODER_B, DI_ENCODER_SW, DO_ENCODER_VCC );

/* Uncomment the initialize the I2C address , uncomment only one, If you get a totally blank screen try the other*/
#define i2c_Address 0x3c //initialize with the I2C addr 0x3C Typically eBay OLED's
                         // e.g. the one with GM12864-77 written on it
//#define i2c_Address 0x3d //initialize with the I2C addr 0x3D Typically Adafruit OLED's


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
const int pin34 = 34;

int manuell = 0;

int a=1;
int speed = 0;
int modus = 0;
int wickelmenge = 0;
float spulenbreite = 0;
float drahtbreite = 0;
int   y_linie = 19;
int y_linie_s = 39;
int   x_abstand = 10;
int w_ziffer_1= 0;
int w_ziffer_2 =0;
int w_ziffer_3 =0;
int w_ziffer_4 =0;
int s_ziffer_1= 0;
int s_ziffer_2 =0;
int s_ziffer_3 =0;

int d_ziffer_1= 0;
int d_ziffer_2 =0;
int d_ziffer_3 =0;






const uint8_t symbol_bitmap[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C,
  0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x30, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x0C, 0x30, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C,
  0x30, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x30, 0xFF, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x0C, 0x37, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x0C,
  0x30, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x30, 0x1F, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x0C, 0x30, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C,
  0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x30, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x0C, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C,
  0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x3F, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFC, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C,
  0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x30, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x0C, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C,
  0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x30, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x0C, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C,
  0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x30, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x0C, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C,
  0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x30, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x0C, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00
};


void knobCallback( long value )
{
    // This gets executed every time the knob is turned
    currentPos = value;
    
}

void buttonCallback( unsigned long duration )
{
    // This gets executed every time the pushbutton is pressed
    sw = 1;
    
}


int lastStableState = HIGH;            // letzter stabiler Zustand
int lastReading = HIGH;                // letzter gelesener Zustand
unsigned long lastDebounceTime = 0;    // Zeitstempel für Entprellung
const unsigned long debounceDelay = 20; // Entprellzeit in ms

// Für rotary

long lastPos    = 0;

String currentDir = "";
String lastDir    = "";
int reading;


bool firstCall = true;
bool firstCall_manual = true;
bool firstCall_auto = true;





void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);






  delay(250); // wait for the OLED to power up
  display.begin(i2c_Address, true); // Address 0x3C default
 //display.setContrast (0); // dim display
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(50, 50);

/////////////////////////////////////////// ROTARY ENCODER ///////////////////////////////

  pinMode(pin34, INPUT);
  
 // This tells the library that the encoder has its own pull-up resistors
    rotaryEncoder.setEncoderType( EncoderType::HAS_PULLUP );

    // Range of values to be returned by the encoder: minimum is 1, maximum is 10
    // The third argument specifies whether turning past the minimum/maximum will
    // wrap around to the other side:
    //  - true  = turn past 10, wrap to 1; turn past 1, wrap to 10
    //  - false = turn past 10, stay on 10; turn past 1, stay on 1
    rotaryEncoder.setBoundaries( 0, 9, true );

    // The function specified here will be called every time the knob is turned
    // and the current value will be passed to it
    rotaryEncoder.onTurned( &knobCallback );



    // This is where the inputs are configured and the interrupts get attached
    rotaryEncoder.begin();

///////////////////////////////////////////////////////////////////////////////////////////////

/////////////// MOTOR ///////////////////////////////////////////////
roll.setMaxSpeed(5000);
guide.setMaxSpeed(5000);

guide.setAcceleration(50000);
roll.setAcceleration(50000);
/////////////////////////////////////////////////////////////////////
 
 pinMode(ENABLE_ROLL, OUTPUT); // FÜR GUIDE --> LOW = AN
 pinMode(ENABLE_GUIDE, OUTPUT); // FÜR ROLL

 digitalWrite(ENABLE_ROLL,HIGH);
 digitalWrite(ENABLE_GUIDE,HIGH);
}


void loop() {

currentMillis = millis();
reading = digitalRead(pin34);

  // Hat sich der Zustand geändert?
  if (reading != lastReading) {
    lastDebounceTime = millis();  // Zeit merken
  }


  // Wenn genug Zeit vergangen ist, Zustand übernehmen
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != lastStableState) {
      lastStableState = reading;


      // Nur wenn Taste gedrückt (LOW)
      if (lastStableState == LOW) {
       
        sw = 1;
        // Hier deine Aktion
      }else{
        sw=0;
      };
    }
  }


  lastReading = reading;




 
switch(a) {
  case 1: //MENü
          main_menu();

           break;

  case 2: //AUTO
       auto_menu();
        break;


  case 3:  //Wickeln
        menu_wickeln();
         break;


  case 4:  //Spuelen
        menu_spulenbreite();
        break;


  case 5: //Set Speed 1
         manu_menu();
        break;
         


  case 6: // Start/Back
          manu_stop();
          break;

  case 7: //bisher unnötig
          display.clearDisplay();
          display.setCursor(5,20);
          display.print("Set Speed1:");

          
          display.setCursor(5,40);
          display.print("Set Speed2: lalala");
          display.display();

          if(sw == 1)
          {
            a = 6;
            
          };
          break;
  case 8: // AUTOMODUS LÄUFT!!!

          auto_motor(3000, spulenbreite, drahtbreite, wickelmenge);
          
          if(roll.distanceToGo()==0)
          {
              display.clearDisplay();
              display.setCursor(10,22);
              display.print("Menu ist Fertig!");
              display.setCursor(10,43);
              display.print("Press to go Menu!");
              display.display();
          };
          
          /// Hier Läuft der Motor!!
          // So klein  wie möglich gehalten werden für berechnungszeiten von Motor


          if(sw == 1)
          {
            a = 1;
            roll.stop();
            guide.stop();
          rotaryEncoder.setBoundaries(0,10, false );
          rotaryEncoder.setEncoderValue(0);
          currentPos=0;

          };
          break;

  case 9: //1000er
      ziffer_1();
      break;
  
  case 10: //100er
        ziffer_2();
        break;

  case 11: //10er
      ziffer_3();
      break;

  case 12: //1er
      ziffer_4();
      break;

    case 13: //1000er
      ziffer_1_s();
      break;
  
  case 14: //100er
        ziffer_2_s();
        break;

  case 15: //10er
      ziffer_3_s();
      break;

  case 16: //Motor Controller, Spulenweite already set
      Serial.print("case16, Motor Controlling");
      break;

  
  case 17: // Drahtbreite
      menu_drahtbreite();
      // Hier muss code für drahtbreite stehen
      break;

  case 18: // HIER STEHT CODE FÜR AUTO ZEROING

      menu_zeroing();


      break;

  case 19: //1000er
      ziffer_1_d();
      break;
  
  case 20: //100er
        ziffer_2_d();
        break;

  case 21: //10er
      ziffer_3_d();
      break;
  


  default: printf("KP"); break;
}


sw = 0;


}






 




