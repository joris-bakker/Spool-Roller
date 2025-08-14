void menu_drahtbreite()
{
     
     y_linie = 39;
          display.clearDisplay();
        
          display.setCursor(5, 30);
          display.print("Drahtbreite:");

          display.setCursor(85,30);
          display.print(d_ziffer_1); /////// Wickeln Wert
          display.print(",");
          display.print(d_ziffer_2); /////// Wickeln Wert
        
          display.print(d_ziffer_3); /////// Wickeln Wert
          display.print(" mm");
          
          
          display.setCursor(5, 50);
          display.print("Fertig");
          
          if(currentPos % 4 == 0){
          modus = 1;
          display.drawLine(85,y_linie,89,y_linie,SH110X_WHITE);
          }
          if(currentPos %4 == 1) {
            modus = 2;
            display.drawLine(98,y_linie,102,y_linie,SH110X_WHITE);
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
            a = 19;
            currentPos = 1;
           };
          if(modus == 2){
            a = 20;
          }
          if(modus == 3){
            a = 21; 
          };

          if(modus == 4){
            if(manuell==0){
              a = 2;
              currentPos= 4;
            };
            if(manuell== 1)
            {

              a = 18;
            };
          };
          modus = 0;
          rotaryEncoder.setEncoderValue(0);
          currentPos= 0;
          }
          display.display();



  
};















void ziffer_1_d()
{

          d_ziffer_1 = currentPos;   

          display.clearDisplay();
        
          display.setCursor(5, 30);
          display.print("Drahtbreite:");

          display.setCursor(85,30);
          display.print(d_ziffer_1); /////// Wickeln Wert
          display.print(",");
          display.print(d_ziffer_2); /////// Wickeln Wert
        
          display.print(d_ziffer_3); /////// Wickeln Wert
          display.print(" mm");
          display.drawLine(85,y_linie,89,y_linie,SH110X_WHITE);
          display.display();

            if(sw == 1){
            a = 17;
            rotaryEncoder.setEncoderValue(0);
            currentPos = 1;
          };
};

void ziffer_2_d()
{

          d_ziffer_2 = currentPos;   

          display.clearDisplay();
          display.clearDisplay();
          display.setCursor(5, 30);
          display.print("Drahtbreite:");

        
          display.setCursor(85,30);
          display.print(d_ziffer_1); /////// Wickeln Wert
          display.print(",");
          display.print(d_ziffer_2); /////// Wickeln Wert
        
          display.print(d_ziffer_3); /////// Wickeln Wert
          display.print(" mm");
          
          display.drawLine(98,y_linie,102,y_linie,SH110X_WHITE);
        display.display();

            if(sw == 1){
            a = 17;
            rotaryEncoder.setEncoderValue(0);
            currentPos = 2;
          };
};

void ziffer_3_d()
{

          d_ziffer_3 = currentPos;   

          display.clearDisplay();
          display.clearDisplay();


          display.setCursor(5, 30);
          display.print("Drahtbreite:");

        
          display.setCursor(85,30);
          
          
          display.print(d_ziffer_1); /////// Wickeln Wert
          display.print(",");
          display.print(d_ziffer_2); /////// Wickeln Wert
        
          display.print(d_ziffer_3); /////// Wickeln Wert
          display.print(" mm");
          
        
          display.drawLine(104,y_linie,108,y_linie,SH110X_WHITE);
          
        display.display();

            if(sw == 1){
            a = 17;
            rotaryEncoder.setEncoderValue(0);
            currentPos = 3;
          };
};




