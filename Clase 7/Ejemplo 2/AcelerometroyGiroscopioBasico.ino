#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
    Serial.begin(115200);
    Wire.begin();
    mpu.initialize();

    if (!mpu.testConnection()) {
        Serial.println("MPU6050 not found!");
        while (1);
    }
}

void loop() {
    int16_t ax, ay, az, gx, gy, gz;
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    float accel_x = ax / 16384.0;  // g
    float gyro_x  = gx / 131.0;    // deg/s

    Serial.print("Accel X: ");
    Serial.println(accel_x);
    Serial.print("Gyro  X: ");
    Serial.println(gyro_x);

    delay(100);
}
