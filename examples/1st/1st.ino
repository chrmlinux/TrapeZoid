#include <TrapeZoid.hpp>
static TrapeZoid tz;

#include <extendFor.hpp>
static extendFor ef;

#define MIN   (  0)
#define MAX   (256)
#define MAXCNT (128)

void setup(void)
{
  Serial.begin( 115200 ); while (!Serial);
  ef.begin();
  tz.begin(MAXCNT);
}

void loop() {
  int i = ef.exf(MIN, MAX - 1, 1);
  float fdt = tz.update((float)i);
  Serial.printf("idx[%d] %.2f\n", tz.idx(), fdt);
}
