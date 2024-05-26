#include "mbed.h"

DigitalOut red(PA_5);
DigitalOut green(PA_6);
DigitalOut yellow(PA_7);

void dimAllLeds(DigitalOut *leds) {
  for (size_t i = 0; i <= 2; i++) {
    leds[i] = false;
  }
}

// main() runs in its own thread in the OS
int main() {

  DigitalOut leds[3] = {red, green, yellow};

  int counter = 0;

  while (true) {

    dimAllLeds(leds);

    if (counter <= 2) {

      leds[counter] = true;

      ThisThread::sleep_for(2000ms);

      for (size_t i = 0; i <= 10; i++){
          leds[counter] = !leds[counter];
          ThisThread::sleep_for(400ms);
      }

        counter++;
    } else {
      counter = 0;
    }
  }
}
