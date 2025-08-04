void menu_wickeln()
{
  y_linie = 19;
   wickelmenge = 0000;
          display.clearDisplay();
          display.setCursor(5,10);
          display.print("Wickeln:");
          display.setCursor(85,10);
          display.print(w_ziffer_1); /////// Wickeln Wert
          display.print(w_ziffer_2); /////// Wickeln Wert
          display.print(w_ziffer_3); /////// Wickeln Wert
          display.print(w_ziffer_4); /////// Wickeln Wert
          display.print(" U");
          
          display.setCursor(5, 30);
          //display.print("Spulenbreite");
          display.setCursor(5, 50);
          display.print("Fertig");


        if(currentPos % 5 == 0){
          modus = 1;
          display.drawLine(85,y_linie,89,y_linie,SH110X_WHITE);
          }
          if(currentPos %5 == 1) {
            modus = 2;
            display.drawLine(91,y_linie,96,y_linie,SH110X_WHITE);
          };
          if(currentPos %5 == 2) {
            modus = 3;
           display.drawLine(98,y_linie,102,y_linie,SH110X_WHITE);
          };
          if(currentPos %5 == 3) {
            modus = 4;
            display.drawLine(104,y_linie,108,y_linie,SH110X_WHITE);
          };

          if(currentPos %5 == 4) {
            modus = 5;
            display.drawRect(0,45,45,17,SH110X_WHITE);
          };
          


          

          if(sw == 1)
          {
          if(modus ==1){
            a = 9;
           };
          if(modus == 2){
            a = 10;
          }
          if(modus == 3){
            a = 11;
           
          };

          if(modus == 4){
            a = 12; 
              
          };
          if(modus ==5){
            a = 2;
            currentPos= 1;
          };
          modus = 0;
          rotaryEncoder.setEncoderValue(0);
          
          }
          display.display();
};

//////////////////////////////////////////////////////////////////////////////////////////////





void ziffer_1()
{

          w_ziffer_1 = currentPos;   

          display.clearDisplay();
          display.setCursor(5,10);
          display.print("Wickeln:");
          display.setCursor(85,10);
          display.print(w_ziffer_1); /////// Wickeln Wert
          display.print(w_ziffer_2); /////// Wickeln Wert
          display.print(w_ziffer_3); /////// Wickeln Wert
          display.print(w_ziffer_4); /////// Wickeln Wert
          display.print(" U");
          display.drawLine(85,y_linie,89,y_linie,SH110X_WHITE);
        display.display();

            if(sw == 1){
            a = 3;
            rotaryEncoder.setEncoderValue(0);
            currentPos= 1;
          };
};

void ziffer_2()
{

          w_ziffer_2 = currentPos;   

          display.clearDisplay();
          display.setCursor(5,10);
          display.print("Wickeln:");
          display.setCursor(85,10);
          display.print(w_ziffer_1); /////// Wickeln Wert
          display.print(w_ziffer_2); /////// Wickeln Wert
          display.print(w_ziffer_3); /////// Wickeln Wert
          display.print(w_ziffer_4); /////// Wickeln Wert
          display.print(" U");
         display.drawLine(91,y_linie,96,y_linie,SH110X_WHITE);
        display.display();

            if(sw == 1){
            a = 3;
            rotaryEncoder.setEncoderValue(0);
            currentPos= 2;
          };
};

void ziffer_3()
{

          w_ziffer_3 = currentPos;   

          display.clearDisplay();
          display.setCursor(5,10);
          display.print("Wickeln:");
          display.setCursor(85,10);
          display.print(w_ziffer_1); /////// Wickeln Wert
          display.print(w_ziffer_2); /////// Wickeln Wert
          display.print(w_ziffer_3); /////// Wickeln Wert
          display.print(w_ziffer_4); /////// Wickeln Wert
          display.print(" U");
        
           display.drawLine(98,y_linie,102,y_linie,SH110X_WHITE);
          
        display.display();

            if(sw == 1){
            a = 3;
            rotaryEncoder.setEncoderValue(0);
            currentPos= 3;
          };
};



void ziffer_4()
{

          w_ziffer_4 = currentPos;   

          display.clearDisplay();
          display.setCursor(5,10);
          display.print("Wickeln:");
          display.setCursor(85,10);
          display.print(w_ziffer_1); /////// Wickeln Wert
          display.print(w_ziffer_2); /////// Wickeln Wert
          display.print(w_ziffer_3); /////// Wickeln Wert
          display.print(w_ziffer_4); /////// Wickeln Wert
          display.print(" U");
        
          display.drawLine(104,y_linie,108,y_linie,SH110X_WHITE);
          
          display.display();

            if(sw == 1){
            a = 3;
            rotaryEncoder.setEncoderValue(0);
            currentPos= 4;
          };
};