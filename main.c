#include <stdio.h>
#include "drone.h"

int main() {
    Drone drone1 = {GROUNDED,{0.0,0.0,0.0},{100.0,0.0},"Salvador"};
    dronekontrol(&drone1);
    

   
    return 0;
}