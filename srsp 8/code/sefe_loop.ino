void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println("SAFE START");

  for (int i = 1; i <= 10000; i++) {
    if (i % 1000 == 0) {
      Serial.println(i);
    }
  }

  Serial.println("DONE");
}

void loop() {
}