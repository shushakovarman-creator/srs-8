#include <stdlib.h>
#include <string.h>

byte* blocks[4];

void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println("MEMORY HOG TEST");
  Serial.println("Level 0: No allocation");

  for (int level = 1; level <= 4; level++) {
    blocks[level - 1] = (byte*)malloc(256);

    if (blocks[level - 1] == NULL) {
      Serial.print("Level ");
      Serial.print(level);
      Serial.println(": ALLOCATION FAILED");
      break;
    }

    memset(blocks[level - 1], level, 256);

    Serial.print("Level ");
    Serial.print(level);
    Serial.println(": 256 bytes allocated");
  }

  Serial.println("TEST FINISHED");

  for (int i = 0; i < 4; i++) {
    free(blocks[i]);
  }
}

void loop() {
}