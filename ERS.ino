#define LED_PIN 8 //Pin for Light on Arduino Board
#define BUTTON_PIN 7 // Pin for switch on Arduino Board

unsigned long time;
unsigned long timeOn;
unsigned long timeOff;

bool on;
bool prevOn = false;
int dayNum = 0;
int hour = 0;
int** Days;



void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);


  *Days = new int[7];
  for (int i = 0; i < 7; ++i) {
    Days[i] = new int[24];
  }
}

void loop() {
  time = millis();
  if (digitalRead(BUTTON_PIN) == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    on = true;
  }
  else {
    digitalWrite(LED_PIN, LOW);
    on = false;
  }

  if (time >= 3600000) {
    if (on) {
      Days[dayNum][hour] = 1;
    }
    else {
      Days[dayNum][hour] = 0;      
    }
    hour++;
    time = 0;

    if (dayNum >= 1) {
     if (digitalRead(BUTTON_PIN == HIGH) && Days[dayNum - 1][hour - 1] == 0) {
       digitalWrite(LED_PIN, LOW);
      }
    }
    if (dayNum >=2 ) {
      if (digitalRead(BUTTON_PIN == HIGH) && Days[dayNum - 1][hour - 1] == 0 && Days[dayNum - 2][hour - 2] == 0) {
        digitalWrite(LED_PIN, LOW);
      }
    }
    if (hour == 24) {
      hour = 0;
      dayNum++;
    }
    if (dayNum == 7) {
      dayNum = 0;
      hour = 0;
    }
  }
  
 
  
}
