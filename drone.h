#ifndef DRONE_H
#define DRONE_H

typedef struct {
    float roll;
    float pitch;
    float yaw;
} Imu;

typedef struct {
    float battery_level;
    float altitude;
} Status;

typedef enum {
    GROUNDED,
    TAKEOFF,
    HOVER,
    LAND,
    EMERGENCY
} DroneMode;

typedef struct {
    DroneMode mod;
    Imu imu;
    Status status;
    char name[10];
} Drone;

void check_roll(float roll);
void check_pitch(float pitch);
void check_yaw(float yaw);
void check_battery(float battery_level);
void check_altitude(float altitude);
void change_roll(float *roll, float new_roll);
void change_pitch(float *pitch, float new_pitch);
void change_yaw(float *yaw, float new_yaw);
void dronekontrol(Drone *d);
void droneguncelle(Drone *d, float new_roll, float new_pitch, float new_yaw, float new_battery_level, float new_altitude);
void mod_yaz(DroneMode mode);
void mod_guncelle(Drone *d);
#endif // DRONE_H
