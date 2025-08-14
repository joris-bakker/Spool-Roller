void menu_zeroing()
{

  digitalWrite(ENABLE_GUIDE,LOW);
  digitalWrite(ENABLE_ROLL,HIGH);


		if (firstCall)
			{
        display.clearDisplay();
        display.setCursor(0,0);
        display.println("Fahr den Guide mit");
        display.println("Drehregler zur Innen-");
        display.println("Kante der Spule");

        display.drawBitmap(40, 32, symbol_bitmap, 64, 30, SH110X_WHITE);
        display.setCursor(5, 50);
        display.print("Next");
        display.drawRect(0,45,35,17,SH110X_WHITE);
        display.display();

 
 			guide.setMaxSpeed(5000);
 			guide.setAcceleration(50000);	
 			rotaryEncoder.setBoundaries( -1200, 1200, false );
 			rotaryEncoder.resetEncoderValue();
 			currentPos = 0;
			firstCall = false;
			};
	guide.moveTo(currentPos*200);
	guide.run();








if(sw == 1){
          

          wickelmenge = 1000*w_ziffer_1 + 100*w_ziffer_2 + 10* w_ziffer_3 + 1*w_ziffer_4;
          spulenbreite = 10*s_ziffer_1 + 1* s_ziffer_2 + (1/10.0* s_ziffer_3);
          drahtbreite =  d_ziffer_1 +  float((d_ziffer_2 / 10.0))+    float((d_ziffer_3 / 100.0));
          roll.setCurrentPosition(0);
          guide.setCurrentPosition(0);
          if(manuell ==0)
          {
          a = 8;


          display.clearDisplay();
          
          display.setCursor(0,0);
          display.print("Wickeln:");
          display.setCursor(80,0);
          
          display.print(wickelmenge); /////// Wickeln Wert
          display.print(" U");

          display.setCursor(80,15);
          display.print(spulenbreite); /////// Wickeln Wert
          display.print(" mm");

  
          display.setCursor(0, 15);
          display.print("Spulenbreite");


          display.setCursor(0,30);
          display.print("Drahtbreite");
          display.setCursor(80,30);
          display.print(drahtbreite);
          display.print(" mm");

          display.setCursor(5,45);
          display.drawRect(0,40,40,17,SH110X_WHITE);
          display.print("STOPP");

          display.setCursor(45,45);
          display.print("Motor runs!");
          display.display();
          digitalWrite(ENABLE_GUIDE,LOW);
          digitalWrite(ENABLE_ROLL,LOW);
          };

          if(manuell == 1)
          {
            a=5;
            rotaryEncoder.setBoundaries(-100,100, false );
            rotaryEncoder.setEncoderValue(0);
            digitalWrite(ENABLE_GUIDE,LOW);
            digitalWrite(ENABLE_ROLL,LOW);
            currentPos=0;
          };



};
};