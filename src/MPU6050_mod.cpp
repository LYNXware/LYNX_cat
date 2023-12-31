#include "MPU6050_mod.h"


Adafruit_MPU6050 mpu;

MPU6050 mpu6050;

// MPU6050::MPU6050() {
void MPU6050::initialize(){

    mpu.begin();

    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

    mpu.setGyroRange(MPU6050_RANGE_500_DEG);

    mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);

}

// void MPU6050::readSensor(){
    
//     mpu.getEvent(&accel, &gyro, &temp);
//     read_accel();
//     // read_gyro();
//     delay(10);
// }

// void MPU6050::read_accel(){
//     /* Get new sensor events with the readings */
//     // sensors_event_t accel;
//     // mpu.getEvent(&accel, NULL, NULL);

//     accel_x = accel.acceleration.x;
//     accel_y = accel.acceleration.y;
//     accel_z = accel.acceleration.z;

//     if (accel_x != accel_x_prev){
//         Serial.print("Accel X: ");
//         Serial.println(accel_x);
//     }
//     // if (accel_y != accel_y_prev){
//     //     Serial.print("Accel Y: ");
//     //     Serial.println(accel_y);
//     // }
//     // if (accel_z != accel_z_prev){
//     //     Serial.print("Accel Z: ");
//     //     Serial.println(accel_z);
//     // }

//     accel_x_prev = accel_x;
//     accel_y_prev = accel_y;
//     accel_z_prev = accel_z;
// }

// void MPU6050::read_gyro(){
//     // /* Get new sensor events with the readings */
//     // sensors_event_t gyro;
//     // mpu.getEvent(NULL, &gyro, NULL);

//     gyro_x = gyro.gyro.x;
//     gyro_y = gyro.gyro.y;   
//     gyro_z = gyro.gyro.z;

//     if (gyro_x != gyro_x_prev){
//         Serial.print("Gyro X: ");
//         Serial.println(gyro_x);
//     }
//     // if (gyro_y != gyro_y_prev){
//     //     Serial.print("Gyro Y: ");
//     //     Serial.println(gyro_y);
//     // }
//     // if (gyro_z != gyro_z_prev){
//     //     Serial.print("Gyro Z: ");
//     //     Serial.println(gyro_z);
//     // }

//     gyro_x_prev = gyro_x;
//     gyro_y_prev = gyro_y;
//     gyro_z_prev = gyro_z;
// }




void MPU6050::readSensor(){
    /* Get new sensor events with the readings */
    // sensors_event_t accel, gyro, temp;
    mpu.getEvent(&accel, &gyro, &temp);

    accel_x = accel.acceleration.x;
    accel_y = accel.acceleration.y;
    accel_z = accel.acceleration.z;

    gyro_x = gyro.gyro.x;
    gyro_y = gyro.gyro.y;   
    gyro_z = gyro.gyro.z;
    
    Serial.print("Accel X: ");
    Serial.print(accel_x);
    Serial.print("  Y: ");
    Serial.print(accel_y);
    Serial.print("  Z: ");
    Serial.print(accel_z);
    Serial.print("  Gyro X: ");
    Serial.print(gyro_x);
    Serial.print("  Y: ");
    Serial.print(gyro_y);
    Serial.print("  Z: ");
    Serial.println(gyro_z);
    delay(100);

}



// // MPU6050::MPU6050() {
// void MPU6050::initialize(){

//     // Serial.begin(115200);
//     while (!Serial)
//     delay(10); // will pause Zero, Leonardo, etc until serial console opens

//     Serial.println("Adafruit MPU6050 test!");

//     // Try to initialize!
//     if (!mpu.begin()) {
//     Serial.println("Failed to find MPU6050 chip");
//     while (1) {
//         delay(10);
//     }
//     }
//     Serial.println("MPU6050 Found!");

//     mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
//     Serial.print("Accelerometer range set to: ");
//     switch (mpu.getAccelerometerRange()) {
//     case MPU6050_RANGE_2_G:
//     Serial.println("+-2G");
//     break;
//     case MPU6050_RANGE_4_G:
//     Serial.println("+-4G");
//     break;
//     case MPU6050_RANGE_8_G:
//     Serial.println("+-8G");
//     break;
//     case MPU6050_RANGE_16_G:
//     Serial.println("+-16G");
//     break;
//     }
//     mpu.setGyroRange(MPU6050_RANGE_500_DEG);
//     Serial.print("Gyro range set to: ");
//     switch (mpu.getGyroRange()) {
//     case MPU6050_RANGE_250_DEG:
//     Serial.println("+- 250 deg/s");
//     break;
//     case MPU6050_RANGE_500_DEG:
//     Serial.println("+- 500 deg/s");
//     break;
//     case MPU6050_RANGE_1000_DEG:
//     Serial.println("+- 1000 deg/s");
//     break;
//     case MPU6050_RANGE_2000_DEG:
//     Serial.println("+- 2000 deg/s");
//     break;
//     }

//     mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
//     Serial.print("Filter bandwidth set to: ");
//     switch (mpu.getFilterBandwidth()) {
//     case MPU6050_BAND_260_HZ:
//     Serial.println("260 Hz");
//     break;
//     case MPU6050_BAND_184_HZ:
//     Serial.println("184 Hz");
//     break;
//     case MPU6050_BAND_94_HZ:
//     Serial.println("94 Hz");
//     break;
//     case MPU6050_BAND_44_HZ:
//     Serial.println("44 Hz");
//     break;
//     case MPU6050_BAND_21_HZ:
//     Serial.println("21 Hz");
//     break;
//     case MPU6050_BAND_10_HZ:
//     Serial.println("10 Hz");
//     break;
//     case MPU6050_BAND_5_HZ:
//     Serial.println("5 Hz");
//     break;
//     }

//     Serial.println("");
//     delay(100);
// }


// void MPU6050::readSensor(){
//   /* Get new sensor events with the readings */
//   sensors_event_t a, g, temp;
//   mpu.getEvent(&a, &g, &temp);

//   /* Print out the values */
//   Serial.print("Acceleration X: ");
//   Serial.print(a.acceleration.x);
//   Serial.print(", Y: ");
//   Serial.print(a.acceleration.y);
//   Serial.print(", Z: ");
//   Serial.print(a.acceleration.z);
//   Serial.println(" m/s^2");

//   Serial.print("Rotation X: ");
//   Serial.print(g.gyro.x);
//   Serial.print(", Y: ");
//   Serial.print(g.gyro.y);
//   Serial.print(", Z: ");
//   Serial.print(g.gyro.z);
//   Serial.println(" rad/s");

//   Serial.print("Temperature: ");
//   Serial.print(temp.temperature);
//   Serial.println(" degC");

//   Serial.println("");
//   delay(500);
// }