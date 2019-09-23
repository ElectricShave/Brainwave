// Magnetic Therapy Helmet using Brainwave Entrainment, programmed with Arduino Intel 101/Genuino
// Sept. 10, 2019, by Rick Regan, Raleigh, NC USA rick@rickregan.net
// Note that this uses the CurieTimerOne.h library instead of the PWM.h library for controlling the 
// frequency of the pulses. The CurieTimerOne library is specific to the Intel Curie Arduinos and may
// not work on non-Intel platforms. 
// The program steps through seven pulse frequency phases, with a high-frequency (gamma) phase bridging 
// the longer phases. Generally the phases move from wakefulness to meditation and back to awareness.


#include "CurieTimerOne.h"

int Gamma =  25000; // 40 hz.
int Christ = 30303; // 33 hz.
int LSD =    50000; // 20 hz.
int Beta =   66000; // 15 hz.
int LoBeta = 83000; // 12 hz.
int Alpha = 111000; //  9 hz.
int Theta = 250000; //  4 hz.
int Delta = 500000; //  2 hz.


void setup() {

  Serial.begin(9600);           //Initialize serial and wait for port to open:
 // while (!Serial) {
 //   ;                           // wait for serial port to connect. Needed for native USB port only
 // }
  
  Serial.println("Printing Phase Map"); // prints title with ending line break
}

void loop() {

   delay (5000); // start up wait
   Serial.println("Printing Phase Map"); // 
  
  Serial.println("Phase I: LoBETA (12 Hz) - 45 sec.");
  CurieTimerOne.pwmStart(13, 80.0, LoBeta);
   delay( 45000 );  // 45-ec  (elapsed: 45 sec.)

  Serial.println("Delta Gap: Delta (2 Hz) - 10 sec. ");
  CurieTimerOne.pwmStart(13, 50.0, Delta);
   delay( 10000 );  // 10-sec    (elapsed: 55 sec.)
   
  Serial.println("Phase II: LoBETA (12 Hz) - 90 sec.");
     CurieTimerOne.pwmStart(13, 80.0, LoBeta);
   delay( 60000 );  // 1 minutes  (elapsed: 145 sec.)

  Serial.println("Delta Gap (2 Hz) - 5 sec.");
  CurieTimerOne.pwmStart(13, 80.0, Delta);
   delay( 5000 );  // 10-sec    (elapsed: 150 sec.)
   
  Serial.println("Phase III: ALPHA (9 Hz)  - 90 sec.");
  CurieTimerOne.pwmStart(13, 80.0, Alpha);
   delay( 90000 );  //  90 sec.  (elapsed: 240 sec.)

  Serial.println("Gamma Gap: GAMMA (40 Hz) - 5 sec.");
  CurieTimerOne.pwmStart(13, 50.0, Gamma);
   delay( 5000 );   // 5-sec    (elapsed: 245 sec.)

  Serial.println("Phase IV: THETA (4 Hz) - 90 sec.");
  CurieTimerOne.pwmStart(13, 80.0, Theta);
   delay( 90000 );  // 2 minutes  (elapsed: 335 sec.)

  Serial.println("Gamma Gap: GAMMA (40 Hz) - 5 sec.");
  CurieTimerOne.pwmStart(13, 80.0, Gamma);
   delay( 5000 );   // 5-sec    (elapsed: 340 sec.)
  
  Serial.println("Phase V: ALPHA (9 Hz) - 90 sec.");
  CurieTimerOne.pwmStart(13, 80.0, Alpha);
   delay( 90000 );   // 90-sec  (elapsed:  430 sec.)

  Serial.println("Christ Gap: CHRIST (33 Hz) - 5 sec.");
  CurieTimerOne.pwmStart(13, 90.0, Christ);
   delay( 5000 );   // 5-sec  (elapsed: 435 sec.)

  Serial.println("Phase VI: LSD (20 Hz)- 45 sec.");
  CurieTimerOne.pwmStart(13, 80.0, LSD);
   delay( 45000 );  // 45-sec.  (elapsed: 480 sec.)
 
  Serial.println("Phase VII: THETA (4 Hz)- 45 sec.");
  CurieTimerOne.pwmStart(13, 80.0, Theta);
   delay( 45000 );  // 45-sec.  (elapsed: 525 sec.)

  Serial.println("Christ Gap: CHRIST (33 Hz) - 10 sec.");
  CurieTimerOne.pwmStart(13, 90.0, Christ);
   delay( 10000 );   // 10-sec  (elapsed: 535 sec.)

  Serial.println("Phase VIII: ALPHA (9 Hz) - 60 sec.");
  CurieTimerOne.pwmStart(13, 80.0, Alpha);
   delay( 60000 );  // 1 minutes  (elapsed: 595 sec.)

  Serial.println("End... Restart!");
   delay( 3000 );

    }


    // Notes:
    //
    // Setup a PWM signal on pin 13, onboard LED, with a 25% duty cycle
  // of a 1 second period (1000000 usec), as follow (please note the
  // decimal point to indicate double):
       // CurieTimerOne.pwmStart(13, 25.0, 1000000);

  // Or, use discrete number range, 0-1023, to define the duty period,
  // 255 is 24.9%, as follow:
      //  CurieTimerOne.pwmStart(13, 255, 83000);
