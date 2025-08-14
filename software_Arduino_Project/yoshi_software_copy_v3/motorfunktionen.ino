



int calc_endposition(float spulenbreite)
{

 int steigung = 2 ; // in mm
 int stepsPerRevolution = 200;
 int microsteps = 4; // muss angepasst werden 

 int steps = (spulenbreite*stepsPerRevolution*microsteps)/steigung;
 
 return steps;
};


float calc_speed_guide(long manual_speed, float drahtbreite)
{
	int steigung = 2;
	int stepsPerRevolution = 200;
	int microsteps_guide = 4;
	int microsteps_roll  = 16;

	int steps_guide = (drahtbreite*stepsPerRevolution*microsteps_guide)/steigung;
	int steps_roll = stepsPerRevolution*microsteps_roll;

	float speed = manual_speed *(float(steps_guide)/float(steps_roll));
	
	return speed;
};


void manual_motor(int speed, float spulenbreite, float drahtbreite)
{

		
		if (firstCall_manual)
			{
				rotaryEncoder.setBoundaries( 0, 100, false );
				rotaryEncoder.resetEncoderValue();
				endposition = calc_endposition(spulenbreite-drahtbreite);
				Serial.println(endposition);
 			currentPos = 0;
			
			firstCall_manual = false;
			};
     // Roll-Motor → kontinuierlich
  roll.setSpeed(speed);
  roll.runSpeed();


  // Guide-Motor → pendeln
  guide.setMaxSpeed(calc_speed_guide(speed, drahtbreite));  // aktuelle Geschwindigkeit setzen
  guide.run();               // moveTo() aktiv ausführen

  // Wenn Ziel erreicht: Richtung umkehren
  if (guide.distanceToGo() == 0) {
    if (directionToEnd) {
      guide.moveTo(0);
    } else {
      guide.moveTo(endposition);
    }
    directionToEnd = !directionToEnd;
  }
};


// Konfiguration
// Bewegungsgrenze

void auto_motor(int speed, float spulenbreite, float drahtbreite, int turns)
{
	
		if (firstCall_auto)
			{
			guide.setAcceleration(50000);	
			
			guide.setMaxSpeed(calc_speed_guide(speed, drahtbreite));
			endposition = calc_endposition(spulenbreite-drahtbreite);
			Serial.println(endposition);
			roll.setMaxSpeed(speed);
			roll.moveTo(turns*200*16);
 			currentPos = 0;
			firstCall_auto = false;
			};
     // Roll-Motor → kontinuierlich
  
	roll.run();
	if(roll.distanceToGo()>0)
		{
    // aktuelle Geschwindigkeit setzen
  	guide.run();               // moveTo() aktiv ausführen

  	// Wenn Ziel erreicht: Richtung umkehren
  	if (guide.distanceToGo() == 0) {
    	if (directionToEnd) {
      	guide.moveTo(0);
    	} else {
      	guide.moveTo(endposition);
    	}
    	directionToEnd = !directionToEnd;
  		}
	};
};









