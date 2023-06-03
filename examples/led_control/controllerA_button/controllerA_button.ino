#include "/home/mont/Documents/PlatformIO/Projects/WireBus/WireBus/src/WireBus.h"


#define PIN_BUTTON  2


#define PIN_TXRX 4 //D2 to D7 on Uno/Nano 
#define DEVICE_ADDR 11 //Device address must be unique to every device on the bus! (Range 0 to 255)
WireBus _wirebus(DEVICE_ADDR, PIN_TXRX);

void setup()
{
	// put your setup code here, to run once:

  pinMode(PIN_BUTTON, INPUT_PULLUP);

	Serial.begin(9600);

	while(!_wirebus.begin(1000, true)) //1000 baud with internal pullup
	{
		Serial.println("Wirebus begin() failed.");
		delay(1000);
	}

}

void loop()
{
	// put your main code here, to run repeatedly:

  int buttonPressed = !digitalRead(PIN_BUTTON);
	_wirebus.write(buttonPressed);
	delay(200);

}