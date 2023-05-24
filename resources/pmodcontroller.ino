#include <ArduinoJson.h>
StaticJsonDocument<128> doc;
JsonObject data = doc.createNestedObject("data");
String input;
int zybo_power = 13;
int pmod_pin1 = 2;
int pmod_pin2 = 3;
int pmod_pin3 = 4;
int pmod_pin4 = 5;
int pmod_pin7 = 6;
int pmod_pin8 = 7;
int pmod_pin9 = 8;
int pmod_pin10 = 9;

void setup() {
  Serial.begin(9600);
  pinMode(pmod_pin1, OUTPUT);
  pinMode(pmod_pin2, OUTPUT);
  pinMode(pmod_pin3, OUTPUT);
  pinMode(pmod_pin4, OUTPUT);
  pinMode(pmod_pin7, OUTPUT);
  pinMode(pmod_pin8, OUTPUT);
  pinMode(pmod_pin9, OUTPUT);
  pinMode(pmod_pin10, OUTPUT);
  pinMode(zybo_power, OUTPUT);
  //Serial.println("initialized");
  delay(1000);

  jsonData();
  //Serial.println();
}

void loop() {
  if (Serial.available()) {
    //input=Serial.read();
    input = Serial.readStringUntil('\n');
    // Serial.print(input);
    // Serial.print(inp["pin1"]);
    if (input == "pin1") {
      digitalWrite(pmod_pin1, HIGH);
      jsonData();
    }
    if (input == "pin1_o") {
      digitalWrite(pmod_pin1, LOW);
      jsonData();
    }
    if (input == "pin2") {
      digitalWrite(pmod_pin2, HIGH);
      jsonData();
    }
    if (input == "pin2_o") {
      digitalWrite(pmod_pin2, LOW);
      jsonData();
    }
    if (input == "pin3") {
      digitalWrite(pmod_pin3, HIGH);
      jsonData();
    }
    if (input == "pin3_o") {
      digitalWrite(pmod_pin3, LOW);
      jsonData();
    }
    if (input == "pin4") {
      digitalWrite(pmod_pin4, HIGH);
      jsonData();
    }
    if (input == "pin4_o") {
      digitalWrite(pmod_pin4, LOW);
      jsonData();
    }
    if (input == "pin7") {
      digitalWrite(pmod_pin7, HIGH);
      jsonData();
    }
    if (input == "pin7_o") {
      digitalWrite(pmod_pin7, LOW);
      jsonData();
    }
    if (input == "pin8") {
      digitalWrite(pmod_pin8, HIGH);
      jsonData();
    }
    if (input == "pin8_o") {
      digitalWrite(pmod_pin8, LOW);
      jsonData();
    }
    if (input == "pin9") {
      digitalWrite(pmod_pin9, HIGH);
      jsonData();
    }
    if (input == "pin9_o") {
      digitalWrite(pmod_pin9, LOW);
      jsonData();
    }
    if (input == "pin10") {
      digitalWrite(pmod_pin10, HIGH);
      jsonData();
    }
    if (input == "pin10_o") {
      digitalWrite(pmod_pin10, LOW);
      jsonData();
    }
    if (input == "jsonData"){
      jsonData();
    }
    if (input == "zybo_power"){
      digitalWrite(zybo_power, HIGH);
      jsonData();
    }
    if (input == "zybo_power_o"){
      digitalWrite(zybo_power, LOW);
      jsonData();
    }
  }
  //delay(5000);
}

void jsonData() {
  doc["sensor"] = "gps";
  doc["time"] = 1351824120;


  data["pin1"] = digitalRead(pmod_pin1);
  data["pin2"] = digitalRead(pmod_pin2);
  data["pin3"] = digitalRead(pmod_pin3);
  data["pin4"] = digitalRead(pmod_pin4);
  data["pin7"] = digitalRead(pmod_pin7);
  data["pin8"] = digitalRead(pmod_pin8);
  data["pin9"] = digitalRead(pmod_pin9);
  data["pin10"] = digitalRead(pmod_pin10);
  data["power"] = digitalRead(zybo_power);

  serializeJson(doc, Serial);
  Serial.println();
  // serializeJsonPretty(doc, Serial);
}
