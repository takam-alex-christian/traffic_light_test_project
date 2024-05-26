#include "mbed.h"


DigitalOut red(PA_5);
DigitalOut green(PA_6);
DigitalOut yellow(PA_7);


void dimAllLeds(DigitalOut *leds){
    for(size_t i = 0; i <= 2; i++){
        leds[i] = false;
    }
}

// main() runs in its own thread in the OS
int main() {
    
    DigitalOut leds[3] = {red, green, yellow};

    int counter = 0;

    while (true){

        dimAllLeds(leds);

        if (counter <= 2){
            
            leds[counter] = true;

            counter++;
        }else {
            counter = 0;
        }

        

        ThisThread::sleep_for(400ms);
        
    }
}
