#include <stdio.h>
#include "drone.h"

int main() {
   Drone drone[3] = {
    {GROUNDED, {0.0, 0.0, 0.0}, {100.0, 0.0}, "gama"},
    {GROUNDED, {1.0, 0.0, 0.0}, {100.0, 0.0}, "beta"},
    {GROUNDED, {2.0, 0.0, 0.0}, {100.0, 0.0}, "alfa"}
};

    printf("Başlangıç değerleri\n");
    for(int i=0;i<3;i++){
        dronekontrol(&drone[i]);

    }

    
    float yeni_degerler[3][3][2][3] = {
        {{{5.0, 5.0, 5.0},{ 90.0, 30.0}},
        {{-15.0, -10.0, -20.0}, {10.0, 3.0}},
        {{25.0, 20.0, 30.0}, {50.0, 120.0}}},
        {{{2.0, 7.0, 12.0},{ 80.0, 20.0}},
        {{-10.0, -10.0, -30.0}, {50.0, 3.0}},
        {{25.0, 20.0, 30.0}, {10.0, 180.0}}},
        {{{5.0, 50.0, 5.0},{ 90.0, 30.0}},
        {{-15.0, -8.0, -20.0}, {25.0, 3.0}},
        {{25.0, 20.0, 30.0}, {5.0, 1200.0}}}
    };
    

    for (int y = 0;  y < 3; y ++) {
        for(int i = 0; i < 3 ; i++){
        droneguncelle(&drone[y], yeni_degerler[y][i][0][0], yeni_degerler[y][i][0][1], yeni_degerler[y][i][0][2], yeni_degerler[y][i][1][0], yeni_degerler[y][i][1][1]);
        dronekontrol(&drone[y]);
        printf("%s için Güncelleme %d tamamlandı.\n\n",drone[y].name, i + 1);
        }
    }
    
   
    return 0;
}