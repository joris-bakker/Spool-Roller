          

void main_menu(void){
  
  display.clearDisplay();
  display.setCursor(30,2);
  display.drawLine(30,11,90,11,SH110X_WHITE);
  display.print("Main Menu:");
  display.setCursor(10,30);
  display.print("Auto");
  firstCall = true;
  firstCall_manual = true;
  firstCall_auto = true;

          
  display.setCursor(60, 30);
  display.print("Manual");

  if(currentPos % 2 == 0){
    modus = 1;
    display.drawRect(5,25,35,17,SH110X_WHITE);
      }
  if(currentPos %2 == 1) {
    modus = 2;
    display.drawRect(55,25,45,17,SH110X_WHITE);
    };
  display.display();

  if(sw == 1)
    {
    if(modus ==1){
      a = 2;
      rotaryEncoder.setEncoderValue(0);
      currentPos= 0;
      };
    if(modus == 2){
      a = 4;
      manuell = 1;
      };
    modus= 0;
    
          
     };

      }