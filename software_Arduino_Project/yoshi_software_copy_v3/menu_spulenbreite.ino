void menu_spulenbreite()
{
     
     y_linie = 39;
          display.clearDisplay();
        
          display.setCursor(5, 30);
          display.print("Spulenbreite:");

          display.setCursor(85,30);
          display.print(s_ziffer_1); /////// Wickeln Wert
          display.print(s_ziffer_2); /////// Wickeln Wert
          display.print(",");
          display.print(s_ziffer_3); /////// Wickeln Wert
          display.print(" mm");
          
          
          display.setCursor(5, 50);
          display.print("Fertig");
          
          if(currentPos % 4 == 0){
          modus = 1;
          display.drawLine(85,y_linie,89,y_linie,SH110X_WHITE);
          }
          if(currentPos %4 == 1) {
            modus = 2;
            display.drawLine(91,y_linie,96,y_linie,SH110X_WHITE);
          };
          if(currentPos %4 == 2) {
            modus = 3;
           display.drawLine(104,y_linie,108,y_linie,SH110X_WHITE);
          };
          if(currentPos %4 == 3) {
            display.drawRect(0,45,45,17,SH110X_WHITE);
            modus = 4;
            
        
            
          };



          

        
          if(sw == 1)
          {
          if(modus ==1){
            a = 13;
            currentPos = 1;
           };
          if(modus == 2){
            a = 14;
          }
          if(modus == 3){
            a = 15; 
          };

          if(modus == 4){
            if(manuell==0){
              a = 2;
              currentPos= 2;
            };
            if(manuell== 1)
            {


          //rotaryEncoder.begin();
              a = 17;
            };
          };
          modus = 0;
          rotaryEncoder.setEncoderValue(0);
          currentPos= 0;
          }
          display.display();



  
};















void ziffer_1_s()
{

          s_ziffer_1 = currentPos;   

          display.clearDisplay();
        
          display.setCursor(5, 30);
          display.print("Spulenbreite:");

          display.setCursor(85,30);
          display.print(s_ziffer_1); /////// Wickeln Wert
          display.print(s_ziffer_2); /////// Wickeln Wert
          display.print(",");
          display.print(s_ziffer_3); /////// Wickeln Wert
          display.print(" mm");
          display.drawLine(85,y_linie,89,y_linie,SH110X_WHITE);
          display.display();

            if(sw == 1){
            a = 4;
            rotaryEncoder.setEncoderValue(0);
            currentPos = 1;
          };
};

void ziffer_2_s()
{

          s_ziffer_2 = currentPos;   

          display.clearDisplay();
          display.clearDisplay();
          display.setCursor(5, 30);
          display.print("Spulenbreite:");

        
          display.setCursor(85,30);
          display.print(s_ziffer_1); /////// Wickeln Wert
          display.print(s_ziffer_2); /////// Wickeln Wert
          display.print(",");
          display.print(s_ziffer_3); /////// Wickeln Wert
          display.print(" mm");
          
          display.drawLine(91,y_linie,96,y_linie,SH110X_WHITE);
        display.display();

            if(sw == 1){
            a = 4;
            rotaryEncoder.setEncoderValue(0);
            currentPos = 2;
          };
};

void ziffer_3_s()
{

          s_ziffer_3 = currentPos;   

          display.clearDisplay();
          display.clearDisplay();


          display.setCursor(5, 30);
          display.print("Spulenbreite:");

        
          display.setCursor(85,30);
          
          
          display.print(s_ziffer_1); /////// Wickeln Wert
          display.print(s_ziffer_2); /////// Wickeln Wert
          display.print(",");
          display.print(s_ziffer_3); /////// Wickeln Wert
          display.print(" mm");
          
        
          display.drawLine(102,y_linie,108,y_linie,SH110X_WHITE);
          
        display.display();

            if(sw == 1){
            a = 4;
            rotaryEncoder.setEncoderValue(0);
            currentPos = 3;
          };
};




