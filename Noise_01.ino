int buzzerPin = 10;
int ledPin = 13;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {

  PlayStartup();
  delay(1000);
  PlayExit();
  delay(1000);
  PlayCruise();
  delay(1000);
  PlayConfirm();
  delay(1000);
  PlayPush();
  delay(1000);
  PlayConfiguration();
  delay(1000);
  PlayError();
  delay(1000);
  PlayArming();
  delay(1000);
  PlayArmed();
  delay(1000);
  PlaySomeFuturisticSound();
  delay(1000);

}

void  PlayStartup(){
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
}

void PlayExit(){
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

void PlayCruise(){
         tone(buzzerPin, 3500, 20);
         delay(50);
         tone(buzzerPin, 1500, 20);
}

void PlayConfirm(){
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
       
void PlayPush(){
         tone(buzzerPin, 3000, 15);
       }
       
void PlayConfiguration(){
         tone(buzzerPin, 1500, 20);
         delay(50);
         tone(buzzerPin, 2000, 20);
         delay(50);
         tone(buzzerPin, 2500, 20);
         delay(50);
         tone(buzzerPin, 3500, 20);
       }
       
void PlayError(){
         tone(buzzerPin, 200, 50);
         delay(50);
         tone(buzzerPin, 200, 50);

       }
       
void PlayArming(){
         tone(buzzerPin, 1000, 20);
         delay(20);
         tone(buzzerPin, 2000, 20);
         delay(40);
         tone(buzzerPin, 4000, 20);
         delay(80);
         tone(buzzerPin, 9000, 20);
         delay(20);
       }
       
void PlayArmed(){
         tone(buzzerPin, 262, 10); tone(buzzerPin, 262, 10); tone(buzzerPin, 262, 100);
         tone(buzzerPin, 262, 10); tone(buzzerPin, 262, 10); tone(buzzerPin, 0, 100);
         tone(buzzerPin, 262, 10); tone(buzzerPin, 262, 10); tone(buzzerPin, 0, 100);
         tone(buzzerPin, 262, 10); tone(buzzerPin, 262, 10); tone(buzzerPin, 262, 100);
       }


void PlaySomeFuturisticSound(){
      digitalWrite(ledPin, LOW);tone(buzzerPin, 2000, 25);delay(50);
      digitalWrite(ledPin, HIGH);tone(buzzerPin, 1800, 25);delay(50);
      digitalWrite(ledPin, LOW);tone(buzzerPin, 2000, 25);delay(50);
      digitalWrite(ledPin, HIGH);tone(buzzerPin, 1800, 25);delay(50);
      digitalWrite(ledPin, LOW);tone(buzzerPin, 2000, 25);delay(50);
      tone(buzzerPin, 2000, 400);delay(50);
      tone(buzzerPin, 2050, 400);delay(50);
      tone(buzzerPin, 2100, 400);delay(50);
      tone(buzzerPin, 2150, 200);delay(50);
      tone(buzzerPin, 2200, 100);delay(50);
      delay(100);
      tone(buzzerPin, 2000, 400);delay(50);
      tone(buzzerPin, 2050, 400);delay(50);
      tone(buzzerPin, 2100, 400);delay(50);
      tone(buzzerPin, 2150, 200);delay(50);
      tone(buzzerPin, 2200, 100);delay(50);  
}

