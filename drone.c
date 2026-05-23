#include <stdio.h>
#include "drone.h"

void check_roll(float roll) {
    if (roll > 10.0) {
        printf("Uyarı: Drone çok fazla sağa yatıyor!\n");
    } else if (roll < -10.0) {
        printf("Uyarı: Drone çok fazla sola yatıyor!\n");
    } else {
        printf("Drone normal pozisyonda.\n");
    }
}

void check_pitch(float pitch) {
    if (pitch > 10.0) {
        printf("Uyarı: Drone çok fazla öne yatıyor!\n");
    } else if (pitch < -10.0) {
        printf("Uyarı: Drone çok fazla arkaya yatıyor!\n");
    } else {
        printf("Drone normal pozisyonda.\n");
    }
}

void check_yaw(float yaw) {
    if (yaw > 10.0) {
        printf("Uyarı: Drone çok fazla sağa dönüyor!\n");
    } else if (yaw < -10.0) {
        printf("Uyarı: Drone çok fazla sola dönüyor!\n");
    } else {
        printf("Drone normal pozisyonda.\n");
    }
}

void check_battery(float battery_level) {
    if (battery_level < 20.0) {
        printf("Uyarı: Batarya seviyesi düşük! Şarj edin.\n");
    } else {
        printf("Batarya seviyesi yeterli.\n");
    }
}

void check_altitude(float altitude) {
    if (altitude > 100.0) {
        printf("Uyarı: Drone çok yüksek irtifada 100 metrenin üzerinde!\n");
    } else if (altitude < 4.0) {
        printf("Uyarı: Drone yere aşırı yakın, dikkatli olun!\n");
    } else {
        printf("Drone normal irtifada.\n");
    }
}

void change_roll(float *roll, float new_roll) {
    *roll = new_roll;
}

void change_pitch(float *pitch, float new_pitch) {
    *pitch = new_pitch;
}

void change_yaw(float *yaw, float new_yaw) {
    *yaw = new_yaw;
}

void dronekontrol(Drone *d) {
    check_roll(d->imu.roll);
    check_pitch(d->imu.pitch);
    check_yaw(d->imu.yaw);
    check_battery(d->status.battery_level);
    if (d->mod != GROUNDED) {
        check_altitude(d->status.altitude);
    }
    mod_guncelle(d);
    printf("Drone: %s | Mod: ", d->name);
    mod_yaz(d->mod);
    printf("Roll: %.2f, Pitch: %.2f, Yaw: %.2f, Batarya: %.2f%%, Yükseklik: %.2f\n\n",
           d->imu.roll, d->imu.pitch, d->imu.yaw, d->status.battery_level, d->status.altitude);
}

void droneguncelle(Drone *d, float new_roll, float new_pitch, float new_yaw, float new_battery_level, float new_altitude) {
    change_roll(&d->imu.roll, new_roll);
    change_pitch(&d->imu.pitch, new_pitch);
    change_yaw(&d->imu.yaw, new_yaw);
    d->status.battery_level = new_battery_level;
    d->status.altitude = new_altitude;
    mod_guncelle(d);
}

void mod_yaz(DroneMode mode) {
    switch (mode) {
        case GROUNDED:   printf("Yerde\n");       break;
        case TAKEOFF:    printf("Kalkış\n");      break;
        case HOVER:      printf("Havada\n");      break;
        case LAND:       printf("İniş\n");        break;
        case EMERGENCY:  printf("Acil Durum\n");  break;
    }
}
void mod_guncelle(Drone *d){
    if (d->status.altitude==0 && d->status.battery_level>=20)
    {
        d->mod=GROUNDED;
    }else if (d->status.battery_level<20)
    {
        d->mod=EMERGENCY;
    }else if (d->status.altitude>0 && d->status.battery_level>=20)
    {
        d->mod=HOVER;
    }
    
}