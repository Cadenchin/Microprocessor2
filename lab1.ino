int button = 4;
int red = 12;
int yellow = 11;
int green = 10;
int speakerPin = 7; //set speaker
bool onbutton = false; 



void setup() {
  
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(button, INPUT);
    pinMode(speakerPin, OUTPUT); //set speaker
    
}


void loop() {
 if (digitalRead(button) == HIGH|| onbutton == true){
        delay(15); // software debounce
        if (digitalRead(button) == HIGH || onbutton == true) {
            // if the switch is HIGH, ie. pushed down - change the lights!
            button = true;
            changeLights();
            delay(15);
        }
    }
  else if (digitalRead(button) == LOW && onbutton == false)
  {
      digitalWrite(green, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(red, HIGH);
      delay(1000);
      digitalWrite(red, LOW);
      delay(1000);
  }
    
 }

void changeLights(){
    // turn off yellow, then turn red on for 6 seconds
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    delay(12000);
    beeping();
    
    // green off, yellow on for 2 seconds
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    delay(12000);
    beeping();
    
    // red and yellow on for 2 seconds (red is already on though)
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    beeping();
}

void beeping(){
      tone(speakerPin,1200,3000);
      delay(3000);
}
