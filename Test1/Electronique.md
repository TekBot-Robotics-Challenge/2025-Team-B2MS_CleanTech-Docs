# Projet Gyroscope et Accéléromètre MPU6050

## Introduction
As part of the TRC2K25 challenge, this project aims to design an interactive embedded system using data from an inertial sensor (accelerometer + gyroscope) communicating via the I2C protocol. The core idea is to detect hand movements in different directions (up, down, left, right, forward, backward) and display in real-time the movement direction and the acceleration intensity on a 16x2 LCD screen.

The system is based on the MPU6050 module, which combines a 3-axis gyroscope and accelerometer, connected to an Arduino UNO microcontroller. The project covers several key aspects of embedded systems:

the selection and integration of an inertial sensor, the design of a simple electronic circuit, programming in C++ with Arduino for data processing, and the implementation of an autonomous power supply.

This project provides experience in reading and interpreting sensor data in real-time and offers a clear and educational visualization of detected movements, making it ideal for beginner projects in IoT, robotics, or human-machine interfaces.


## Sensor Choice: MPU6050

The MPU6050 is a 6-axis IMU (Inertial Measurement Unit) sensor that combines:

**A 3-axis accelerometer**

**A 3-axis gyroscope**

### Main features:
The MPU6050 combines a 3-axis accelerometer and a 3-axis gyroscope in a single compact module, which allows accurate measurement of both orientation and hand movement speed.

It uses an I2C interface, fully compatible with microcontrollers like Arduino, making data reading easy with minimal wiring and low power consumption.

Stable and fast communication with the microcontroller. It is widely used in the Arduino community, with many available libraries (such as MPU6050.h or Wire.h), simplifying development and debugging.

- Accelerometer measurement range: ±2g, ±4g, ±8g, ±16g

- Gyroscope measurement range: ±250, ±500, ±1000, ±2000 °/s

- Supply voltage: 3.3V – 5V
  
### Operating principle:
 The MPU6050 sensor combines two main functions: an accelerometer and a gyroscope. The accelerometer measures linear acceleration on the three axes (X, Y, Z), which allows detection of hand movement in the up, down, left, right, forward, or backward directions. The gyroscope measures angular velocity on these same axes, enabling the determination of hand orientation, such as tilt or rotation.

To transmit data to the microcontroller, the MPU6050 uses the I2C communication protocol. This protocol is simple and efficient, requiring only two wires: the SCL line (for the clock) and the SDA line (for data). Through this connection, the microcontroller can send commands to the sensor and read its values in real-time.
To make the MPU6050 send data, simply connecting it is not enough. Since I2C communication is used, a well-defined protocol must be followed:
Before reading data, the Arduino must send the address of the desired register. This address indicates the type of data to retrieve (acceleration, angular velocity).

<img width="525" alt="image" src="https://github.com/user-attachments/assets/86f63efa-30d9-48cc-9a36-7b5bf20c1be7" /> <img width="527" alt="image" src="https://github.com/user-attachments/assets/950e87a8-2212-455f-823d-7ecc61219eb4" />
Each measurement (acceleration or rotation) is encoded on 16 bits (2 bytes):
8 MSB bits (most significant)
8 LSB bits (least significant)
Values are in two’s complement (signed integer), allowing for indication of positive or negative movement direction.

To use the measurements, they must be converted into physical units:
Acceleration in g (earth gravity)
Rotation in °/s (degrees per second)

![image](https://github.com/user-attachments/assets/32af0436-8c42-437a-9c0e-ee4a9486035b)

Rotation in °/s (degrees per second)

![image](https://github.com/user-attachments/assets/f0270c67-dbc1-4aa4-802a-d2ef67d9eb11)


### Datasheet :
> 🔗 [View the MPU6050 3.4 datasheet (PDF)](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf)
> 🔗 [View the MPU6050 4.2 datasheet (PDF)](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Register-Map1.pdf)

## Liste des composants
- Arduino Uno
- IMU Module MPU6050
- 16x2 LCD screen with I2C interface
- Jumper wires (male-to-male)
- Breadboard
- 5V Power supply


## Circuit Diagram

<img width="408" alt="image" src="https://github.com/user-attachments/assets/5713927e-edbf-491a-930d-1074d48480c9" />

- The diagram shows the main connections:
- SDA (LCD & MPU6050) → A4 (Arduino)
- SCL (LCD & MPU6050) → A5 (Arduino)
- VCC (LCD & MPU6050) → 5V (Arduino)
- GND (LCD & MPU6050) → GND (Arduino)



## Code Explanation

The code performs the following steps:

- Initializes I2C communication with the MPU6050 sensor and the 16x2 LCD screen.
- Checks if the sensor is properly connected.
- Reads acceleration values on the 3 axes (X, Y, Z).
- Calculates the total acceleration norm.
- Detects the dominant movement direction (Left, Right, Forward, Backward, Up, Down, or Stable).
- Displays the detected direction and acceleration intensity on the LCD screen.

## Photos

**Start**  
![Start](https://github.com/user-attachments/assets/9d2e749a-d353-4479-93dd-5cab8e7c77d6)

**Working**  
![Working1](https://github.com/user-attachments/assets/73b5fa34-8397-4766-9c18-858dda9c1cdb)  
![Working2](https://github.com/user-attachments/assets/cc679bfa-6355-4a55-bc95-7ef6c44f8b9a)  
![Working3](https://github.com/user-attachments/assets/048a04b7-573b-472b-a7b6-d8bf74f95b42)

**Prototype final** 
![WhatsApp Image 2025-06-12 à 01 42 47_a59e8de9](https://github.com/user-attachments/assets/d09e98fb-51eb-4637-8a00-7452ec714bcc)
![WhatsApp Image 2025-06-12 à 01 42 47_1ceb12f4](https://github.com/user-attachments/assets/8e4d0327-8772-4716-8a14-df12f8085d69)


## Demo Videos
- [🎬 First trial](https://youtube.com/shorts/durMujPbixI?si=PIUfneER4diqM4VX)  
- [🎬 Final Successful Trial](https://youtube.com/shorts/d7HRCWKiFtE?si=rqMBNyRJBchXtX6A)  
- [🎬 Acceleration in Motion](https://youtube.com/shorts/WYKy4-q5Adw?si=LnA5E9QnaUxR04ia)  
- [🎬 Demo 1](https://youtube.com/shorts/AAsT8OWc2lI?si=SOCxGWyvDSOcB6vq)
- [🎬 Demo 2](https://youtube.com/shorts/AAsT8OWc2lI?si=SOCxGWyvDSOcB6vq)
- [🎬 Final Demonstration](https://youtube.com/shorts/AAsT8OWc2lI?si=vX0ZBbOxcTdwuzrz)

##  How to Use the Project

### 1. Hardware Setup
- Connect the MPU6050 module to SDA/SCL (A4/A5) of the Arduino.
- Connect the I2C LCD screen to the same lines.
- Power everything with the Arduino's 5V and GND. 

### 2.Software Setup
- Install the Arduino IDE.
- Add the libraries: 
  - `Wire.h`  
  - `LiquidCrystal_I2C.h`  
  - `MPU6050.h` ou `Adafruit_MPU6050.h` 
- Open `code`.
- Téléversé le code sur l'arduino.

### 3.Upload the Code
- Open the Arduino IDE.
- Select the correct board: Arduino UNO.
- Select the correct port (COM).
- Upload the program.

### 4. Test the System
- Move your hand in different directions (up, down, left, right, forward, backward).
- Observe the direction displayed on the LCD screen.
- The acceleration intensity will also be shown in real-time.
  

## Notes
- For smoother readings, a complementary filter or a Kalman filter can be integrated.
- This project serves as a great foundation for systems such as controllers, self-balancing robots, or stabilization platforms.

## Conclusion
This project allowed us to explore the integration of an inertial sensor in an embedded system, and to implement real-time detection and display of hand movements. The MPU6050 module proved to be an effective and accessible tool for detecting orientation and movement.

Thanks to its compatibility with the Arduino ecosystem, and the availability of dedicated libraries, the MPU6050 can be easily implemented in various educational or prototyping projects. The display of the detected direction and acceleration values on an LCD 16x2 offers a clear and educational visualization, ideal for learning about sensors, microcontroller programming, and human-machine interfaces.

In addition to its educational interest, this system can be extended to applications such as gesture control, virtual reality, or robotics, with the possibility of adding Bluetooth or Wi-Fi communication to increase interactivity.



**Made with ❤️ by our electronics team.**
