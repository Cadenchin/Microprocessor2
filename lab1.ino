//pin assignment
int button = 4;
int red = 12;
int yellow = 11;
int green = 10;
int speakerPin = 7; //set speaker
bool onbutton = false; //has the button been pressed?


//pin mode setup
void setup() {
  
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(button, INPUT);
    pinMode(speakerPin, OUTPUT); //set speaker
    
}

//main program loop
void loop() {
 if (digitalRead(button) == HIGH|| onbutton == true){           //the changeLights() sequence will continue to cycle after the button is pressed
        delay(15); // software debounce
        if (digitalRead(button) == HIGH || onbutton == true) {
            // if the switch is HIGH, ie. pushed down - change the lights!
            button = true;
            changeLights();
            delay(15);
        }
    }
  else if (digitalRead(button) == LOW && onbutton == false) //red light blinking
  {
      digitalWrite(green, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(red, HIGH);      
      delay(1000);
      digitalWrite(red, LOW);   
      delay(1000);
  }
    
 }

//light change sequence
void changeLights(){
    // turn off yellow, then turn red on for 15 seconds (12s plue 3s delay from beeping())
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    delay(12000);
    beeping();
    
    // red and yellow off, green light for 15 seconds
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    delay(12000);
    beeping();
    
    //yellow on for 3 seconds
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    beeping();
}

//buzzer beep before light change
void beeping(){
      tone(speakerPin,1200,3000);
      delay(3000);
}
