         
void auto_menu(void){
          
          display.clearDisplay();
          display.setCursor(15,0);
          display.print("Wickeln:");
          display.setCursor(85,0);
          
          display.print(w_ziffer_1); /////// Wickeln Wert
          display.print(w_ziffer_2); /////// Wickeln Wert
          display.print(w_ziffer_3); /////// Wickeln Wert
          display.print(w_ziffer_4); /////// Wickeln Wert
          display.print(" U");
          display.setCursor(85,15);
          display.print(s_ziffer_1); /////// Wickeln Wert
          display.print(s_ziffer_2); /////// Wickeln Wert
          display.print(",");
          display.print(s_ziffer_3); /////// Wickeln Wert
          display.print("mm");
          
          display.setCursor(15, 15);
          display.print("Spulenbr.");

          display.setCursor(15,30);
          display.print("Drahtbr.");
          display.setCursor(85,30);
          display.print(d_ziffer_1); /////// draht Wert
          display.print(",");
          display.print(d_ziffer_2); /////// draht Wert
      
          display.print(d_ziffer_3); /////// draht Wert
          display.print("mm");


          
          display.setCursor(5, 50);
          display.print("Next");
          display.setCursor(60,50);
          display.print("Back");
          
          if(currentPos % 5 == 0){
          modus = 1;
          display.setCursor(0,0);
          display.print("->");
          //display.drawRect(0,5,50,17,SH110X_WHITE);
          }
          if(currentPos %5 == 1) {
            modus = 2;
            display.setCursor(0,15);
            display.print("->");
          };
          if(currentPos %5 == 2) {
            modus = 5;
            display.setCursor(0,30);
            display.print("->");
          };
          if(currentPos %5 == 3) {
            modus = 3;
            display.drawRect(0,45,40,17,SH110X_WHITE);
          };
          if(currentPos %5 == 4) {
            modus = 4;
            display.drawRect(55,45,40,17,SH110X_WHITE);
          };

          if(sw == 1)
          {
          if(modus ==1){
            a = 3;
           };
          if(modus == 2){
            a = 4;
          }
          if(modus == 3){
            a = 18; 
          };

          if(modus == 4){
            a = 1; 
          };

          if(modus == 5){
            a = 17; 
          };

          modus = 0;
          rotaryEncoder.setEncoderValue(0);
          currentPos= 0;
          }
          display.display();

}