#include <LiquidCrystal.h>
#include <IRremote.h>
LiquidCrystal lcd (8, 9, 4, 5, 6, 7);

const int RECV_PIN = 2;
int LED = 10;
int LED2 = 11;
int LED3 = 12;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  lcd.begin (16, 2);

  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop() {

  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
  ///////////////////////////////////////////////////////////////
  if (results.value == 0xFF30CF /* #1 */) {
    digitalWrite(LED, HIGH);
    lcd.setCursor(0, 0);
    lcd.print ("Verde");
  }
  else if (results.value == 0xFF10EF /* #4 */) {
    digitalWrite(LED, LOW);
    lcd.setCursor(0, 0);
    lcd.print ("-----");
  }
  ///////////////////////////////////////////////////////////////
  if (results.value == 0xFF18E7 /* #2 */) {
    digitalWrite(LED2, HIGH);
    lcd.setCursor(0, 1);
    lcd.print ("Amarillo");
  }
  else if (results.value == 0xFF38C7 /* #5 */) {
    digitalWrite(LED2, LOW);
    lcd.setCursor(0, 1);
    lcd.print ("--------");
  }
  ///////////////////////////////////////////////////////////////
  if (results.value == 0xFF7A85 /* #3 */) {
    digitalWrite(LED3, HIGH);
    lcd.setCursor(9, 0);
    lcd.print ("Azul");
  }
  else if (results.value == 0xFF5AA5 /* #6 */) {
    digitalWrite(LED3, LOW);
    lcd.setCursor(9, 0);
    lcd.print ("----");
  }
  ///////////////////////////////////////////////////////////////
  if (results.value == 0xFF6897 /* #0 */) {
    digitalWrite(LED, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);

    lcd.setCursor(0, 0);
    lcd.print ("-----");

    lcd.setCursor(0, 1);
    lcd.print ("--------");

    lcd.setCursor(9, 0);
    lcd.print ("----");

  }
}
