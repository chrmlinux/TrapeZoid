#include <TrapeZoid.hpp>
static TrapeZoid tz;

#include <extendFor.hpp>
static extendFor ef;

#define MAXCNT (10)
#define PWMPIN (25)
#define PWMCH  ( 0)

int bits = 8;
int scale = 256;

float fact = ((float)scale / 20.0);
float smin = (1.0 * fact);
float smax = (2.0 * fact);
  int st = -90;
  int en =  90;
  
//
//   |----|  0.5..2.5 msec
//   +----+                +---
//   |    |                |
//   |    |                |
//---+    +----------------+
//   |---- 20msec(50Hz) ---|
//

void servo(int rad, uint32_t usec) {
  float fdt = tz.update((float)rad);
  int dt = map(fdt, st, en, smin, smax);
  ledcWrite(PWMCH, dt);
  delayMicroseconds(usec);
}

void setup(void)
{
  Serial.begin( 115200 ); while(!Serial);
  ef.begin();
  tz.begin(MAXCNT);
  ledcAttachPin(PWMPIN, PWMCH);
  ledcSetup(PWMCH, 50, bits);
}

void loop() {
  int rad = ef.exf(st, en, 3);
  servo(rad, 1000 * 20);
}
