void manu_menu()
{
  speed = currentPos;
          /*
          display.clearDisplay();
          speed = currentPos;
          display.setCursor(0,0);
          display.print("Speed:");
          display.setCursor(80,0);
          
          display.print(speed); /////// Wickeln Wert



          display.setCursor(0, 15);
          display.print("Spulenbreite");
          display.setCursor(80,15);
          display.print(spulenbreite); /////// Wickeln Wert
          display.print(" mm");

          display.setCursor(0,30);
          display.print("Drahtbreite");
          display.setCursor(80,30);
          display.print(drahtbreite);
          display.print(" mm");
          




          display.setCursor(5,50);
          display.drawRect(0,45,40,17,SH110X_WHITE);
          display.print("STOPP");
          display.display();
          
*/
          manual_motor(speed*100, spulenbreite, drahtbreite);

          if(sw == 1){
            a = 6; 
          
          modus = 0;
          manuell= 0;
          rotaryEncoder.setBoundaries(0,1, true );
          rotaryEncoder.setEncoderValue(0);
          currentPos= 0;
          
          
          display.display();

          };

 
};




void manu_stop()
{
  roll.stop();
  guide.stop();
display.clearDisplay();
          display.setCursor(5,10);
          display.print("Start again");
          
          display.setCursor(5,30);
          display.print("Back to menu");


         if(currentPos % 2 == 0){
          modus = 1;
          display.drawRect(0,5,80,17,SH110X_WHITE);
          }
          if(currentPos %2 == 1) {
            modus = 2;
            display.drawRect(0,25,80,17,SH110X_WHITE);
          };

          display.display();


          if(sw == 1)
          {
          if(modus ==1){
            a = 5;

          rotaryEncoder.setBoundaries(-100,100, false );
          rotaryEncoder.setEncoderValue(0);
          currentPos= 0;
            currentPos=0;

           };
          if(modus == 2){
            a = 1;

          rotaryEncoder.setEncoderValue(0);
          currentPos= 0;
          rotaryEncoder.setBoundaries( 0, 9, true );
          };
          modus = 0;
          
          };
};