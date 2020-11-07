void setup()
{
  pinMode(13,OUTPUT);
  pinMode(3,INPUT);
  Serial.begin(9600);
}
void loop()
{
  if (digitalRead(3)== LOW)
  {
    digitalWrite(13,HIGH);
    
    delay(10);
  }
  else 
  {
    
    digitalWrite(13,LOW);
    delay(10);
    
  }
  
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// Include Libraries
#include "Arduino.h"
#include "Buzzer.h"


// Pin Definitions
#define BUZZER_PIN_SIG	2



Buzzer buzzer(BUZZER_PIN_SIG);


const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

void setup() 
{
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    
    menuOption = menu();
    
}

void loop() 
{
    
    
    if(menuOption == '1') {
    // Buzzer - Test Code
    // The buzzer will turn on and off for 500ms (0.5 sec)
    buzzer.on();      
    delay(500);    
    buzzer.off(); 
    delay(500); 
    }
    else if(menuOption == '2')
    {
    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}

char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) Buzzer"));
    Serial.println(F("(2) Infrared Thermometer - MLX90614"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing Buzzer"));
    		else if(c == '2') 
    			Serial.println(F("Now Testing Infrared Thermometer - MLX90614 - note that this component doesn't have a test code"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}
