/*
FlightComputer_01:  Display started, push button press detection and some noises
				VX.Y: X ==> HW Version, Y ==> Firmware version
				HW V0: Arduino Uno, wires and jumpers and breadboard used
				FW V0
FlightComputer_02: Debouncing and detecting short and long presses
				DBG V0.1
FlightComputer_03: FSM Basics: turning on and off by long pressing the center button
				DBG V0.2
*/

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Software SPI (slower updates, more flexible pin options):
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

// Hardware SPI (faster, but must use certain hardware pins):
// SCK is LCD serial clock (SCLK) - this is pin 13 on Arduino Uno
// MOSI is LCD DIN - this is pin 11 on an Arduino Uno
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
// Adafruit_PCD8544 display = Adafruit_PCD8544(5, 4, 3);
// Note with hardware SPI MISO and SS pins aren't used but will still be read
// and written to during SPI transfer.  Be careful sharing these pins!

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16

const uint8_t buzzerPin = 8;  //Buzzer
const uint8_t ledPin = 13;    //Led
const uint8_t btn_L = A0;
const uint8_t btn_C = A1;
const uint8_t btn_R = A2;
const uint8_t btn_D = A3;
const uint8_t btn_U = A4;

uint8_t	key_counter = 0;

void setup() {

	/*My code for initializing the Flight computer*/

	Serial.begin(9600);

	display.begin();
	display.setContrast(50);
	display.clearDisplay();

	display.setTextSize(1);
	display.setTextColor(BLACK);
	display.setCursor(0, 0);
	display.println("FC100 DBG V0.2");
	display.setTextColor(WHITE, BLACK); // 'inverted' text
	display.println("              ");
	display.println(" INITIALIZING ");
	display.println("              ");
	display.display();

	//Generating start up noise
	//PlayStartup();
	//delay(2000);

	pinMode(btn_L, INPUT);
	pinMode(btn_C, INPUT);
	pinMode(btn_R, INPUT);
	pinMode(btn_D, INPUT);
	pinMode(btn_U, INPUT);




}


void loop() {

	if ((digitalRead(btn_L) && digitalRead(btn_C) && digitalRead(btn_R) && digitalRead(btn_D) && digitalRead(btn_U)) == 0) {
		display.setTextColor(BLACK, WHITE);
		display.setCursor(0, 33);
		//display.println("A key pressed");
		display.println(key_counter, DEC);
		display.display();
		key_counter++;
		delay(5);
	}
	else if (key_counter > 2 && key_counter <= 40) {
		key_counter = 0;
		display.setTextColor(BLACK, WHITE);
		display.setCursor(0, 33);
		display.println("short press");
		display.display();
		Noise_click();
		//delay(2000);
		display.setCursor(0, 33);
		display.println("              ");
		display.display();
	}
	else if (key_counter > 40) {
		key_counter = 0;
		display.setTextColor(BLACK, WHITE);
		display.setCursor(0, 33);
		display.println("LONG press");
		display.display();
		PlayExit();
		delay(2000);
		display.setCursor(0, 33);
		display.println("              ");
		display.display();

	}
	else {
		key_counter = 0;
	}

	/* if (digitalRead(btn_L) == LOW) {
	display.setTextColor(BLACK, WHITE);
	display.setCursor(0, 33);
	display.println("BTN L");
	display.display();
	Noise_click();
	delay(200);
	}
	else if (digitalRead(btn_C) == LOW) {
	display.setTextColor(BLACK, WHITE);
	display.setCursor(0, 33);
	display.println("BTN C");
	display.display();
	Noise_click();
	delay(200);
	}
	else if (digitalRead(btn_R) == LOW) {
	display.setTextColor(BLACK, WHITE);
	display.setCursor(0, 33);
	display.println("BTN R");
	display.display();
	Noise_click();
	delay(200);
	}
	else if (digitalRead(btn_D) == LOW) {
	display.setTextColor(BLACK, WHITE);
	display.setCursor(0, 33);
	display.println("BTN D");
	display.display();
	Noise_click();
	delay(200);
	}
	else if (digitalRead(btn_U) == LOW) {
	display.setTextColor(BLACK, WHITE);
	display.setCursor(0, 33);
	display.println("BTN U");
	display.display();
	Noise_click();
	delay(200);
	}*/


}

void  PlayStartup() {
	digitalWrite(ledPin, HIGH);
	tone(buzzerPin, 1000, 50);   //Time,Frequency
	delay(80);
	digitalWrite(ledPin, LOW);
	tone(buzzerPin, 2000, 50);
	delay(80);
	digitalWrite(ledPin, HIGH);
	tone(buzzerPin, 1000, 50);
	delay(80);
	digitalWrite(ledPin, LOW);
	tone(buzzerPin, 2000, 50);
	delay(80);
	digitalWrite(ledPin, HIGH);
	tone(buzzerPin, 4000, 50);
	delay(80);
	digitalWrite(ledPin, LOW);
	tone(buzzerPin, 2000, 50);
	delay(80);
	digitalWrite(ledPin, HIGH);
	tone(buzzerPin, 8000, 50);
	delay(80);
	digitalWrite(ledPin, LOW);
	digitalWrite(buzzerPin, HIGH);
}

void PlayExit() {
	tone(buzzerPin, 400, 20);
	tone(buzzerPin, 400, 20);
	delay(50);
	tone(buzzerPin, 400, 20);
	tone(buzzerPin, 150, 20);
	delay(50);
	tone(buzzerPin, 200, 20);
	delay(50);
	tone(buzzerPin, 250, 20);
}

void PlayCruise() {
	tone(buzzerPin, 3500, 20);
	delay(50);
	tone(buzzerPin, 1500, 20);
}

void PlayConfirm() {
	tone(buzzerPin, 4000, 20);
	delay(50);
	tone(buzzerPin, 4000, 20);
	tone(buzzerPin, 1500, 20);
	delay(50);
	tone(buzzerPin, 2000, 20);
	delay(50);
	tone(buzzerPin, 2500, 20);
	delay(50);
	tone(buzzerPin, 3500, 20);
	tone(buzzerPin, 1500, 20);
	delay(50);
	tone(buzzerPin, 2000, 20);
	delay(50);
	tone(buzzerPin, 2500, 20);
	delay(50);
	tone(buzzerPin, 3500, 20);
}

void PlayPush() {
	tone(buzzerPin, 3000, 15);
	digitalWrite(buzzerPin, HIGH);
}

void PlayConfiguration() {
	tone(buzzerPin, 1500, 20);
	delay(50);
	tone(buzzerPin, 2000, 20);
	delay(50);
	tone(buzzerPin, 2500, 20);
	delay(50);
	tone(buzzerPin, 3500, 20);
}

void PlayError() {
	tone(buzzerPin, 200, 50);
	delay(50);
	tone(buzzerPin, 200, 50);

}

void PlayArming() {
	tone(buzzerPin, 1000, 20);
	delay(20);
	tone(buzzerPin, 2000, 20);
	delay(40);
	tone(buzzerPin, 4000, 20);
	delay(80);
	tone(buzzerPin, 9000, 20);
	delay(20);
}

void PlayArmed() {
	tone(buzzerPin, 262, 10); tone(buzzerPin, 262, 10); tone(buzzerPin, 262, 100);
	tone(buzzerPin, 262, 10); tone(buzzerPin, 262, 10); tone(buzzerPin, 0, 100);
	tone(buzzerPin, 262, 10); tone(buzzerPin, 262, 10); tone(buzzerPin, 0, 100);
	tone(buzzerPin, 262, 10); tone(buzzerPin, 262, 10); tone(buzzerPin, 262, 100);
}


void PlaySomeFuturisticSound() {
	digitalWrite(ledPin, LOW); tone(buzzerPin, 2000, 25); delay(50);
	digitalWrite(ledPin, HIGH); tone(buzzerPin, 1800, 25); delay(50);
	digitalWrite(ledPin, LOW); tone(buzzerPin, 2000, 25); delay(50);
	digitalWrite(ledPin, HIGH); tone(buzzerPin, 1800, 25); delay(50);
	digitalWrite(ledPin, LOW); tone(buzzerPin, 2000, 25); delay(50);
	tone(buzzerPin, 2000, 400); delay(50);
	tone(buzzerPin, 2050, 400); delay(50);
	tone(buzzerPin, 2100, 400); delay(50);
	tone(buzzerPin, 2150, 200); delay(50);
	tone(buzzerPin, 2200, 100); delay(50);
	delay(100);
	tone(buzzerPin, 2000, 400); delay(50);
	tone(buzzerPin, 2050, 400); delay(50);
	tone(buzzerPin, 2100, 400); delay(50);
	tone(buzzerPin, 2150, 200); delay(50);
	tone(buzzerPin, 2200, 100); delay(50);
}

void Noise_click() {
	tone(buzzerPin, 400, 10);
	digitalWrite(buzzerPin, HIGH);

}

