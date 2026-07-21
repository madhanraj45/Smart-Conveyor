# Smart-Conveyor
Automatic Product Detection, Counting, and Conveyor Control System using LPC2129 ARM7 Microcontroller

# SMART CONVEYOR : AUTOMATIC PRODUCT DETECTION, COUNTING, AND CONVEYOR CONTROL SYSTEM

## Project Overview

The **Smart Conveyor System** is an embedded systems project developed using the **ARM7 LPC2129** microcontroller. The system automates product detection, counting, and conveyor motor control using two infrared (IR) sensors. A 16×2 LCD displays a scrolling project title and the total number of products that have passed through the conveyor.

The conveyor motor automatically starts when a product enters the belt and stops when no products remain on the conveyor, making the system suitable for industrial automation and production line monitoring.

---

## Features

* Automatic product detection using two IR sensors.
* Automatic product counting.
* Conveyor motor starts when a product enters.
* Conveyor motor stops when the conveyor becomes empty.
* Real-time product count displayed on a 16×2 LCD.
* Scrolling project title on the first LCD row.
* Efficient timer-based delay functions using the LPC21xx Timer0 peripheral.
* Simple and reliable embedded C implementation.

---

## Hardware Requirements

* ARM7 LPC2129 Development Board 
* 16×2 LCD Display (8-bit mode)
* 2 × Infrared (IR) Sensors
* DC Conveyor Motor
* Motor Driver
* Power Supply (5V as required)
* Connecting Wires

---

## Software Requirements

* Keil µVision IDE
* Embedded C
* Flash Magic (for programming the controller)
* Proteus (for simulation)

---

## Pin Configuration

| Device         | LPC21xx Pin |
| -------------- | ----------- |
| LCD Data D0–D7 | P0.0 – P0.7 |
| LCD RS         | P0.8        |
| LCD Enable     | P0.9        |
| IR Sensor 1    | P0.10       |
| IR Sensor 2    | P0.11       |
| Motor Control  | P0.21       |

---

## Working Principle

1. The LCD is initialized and continuously displays a scrolling project title on the first line.
2. The second line displays the total number of products counted.
3. When **IR Sensor 1** detects a product entering the conveyor:
   * The number of products currently on the conveyor increases.
   * The conveyor motor is switched ON.
4. When **IR Sensor 2** detects the product leaving the conveyor:
   * The number of products on the conveyor decreases.
   * The total product count is incremented.
5. If no products remain on the conveyor, the motor is automatically switched OFF.
6. The process repeats continuously.

---

## Program Flow

1. Initialize LCD.
2. Configure GPIO pins.
3. Display scrolling project title.
4. Read IR Sensor 1.
5. If a product enters:

   * Increment products on the conveyor.
   * Turn ON motor.
6. Read IR Sensor 2.
7. If a product exits:

   * Decrement products on the conveyor.
   * Increment total count.
8. If the conveyor is empty:

   * Turn OFF motor.
9. Repeat forever.

---

## Folder Structure

```text
Smart_Conveyor_System/
│
├── main.c                 # Main application
├── README.md              # Project documentation
├── Images/                # Circuit and project images
```

---

## Applications

* Manufacturing industries
* Packaging units
* Assembly lines
* Warehouse automation
* Product sorting systems
* Production monitoring systems

---

## Advantages

* Reduces manual product counting.
* Improves industrial automation.
* Saves electrical power by automatically controlling the conveyor.
* Low-cost embedded solution.
* Easy to expand for IoT and Industry 4.0 applications.
* Reliable and real-time operation.

---

## Future Enhancements

* IoT-based remote monitoring.
* Wi-Fi/GSM notifications.
* Cloud data logging.
* Barcode/QR code integration.
* Object classification using machine vision.
* Automatic sorting mechanism.
* Production database management.
* Mobile application monitoring.

---

## Author

**Madhanraj B**

Embedded Systems Developer

---

## License

This project is developed for educational and academic purposes. It may be modified and used for learning, research, and non-commercial applications with appropriate acknowledgment.
