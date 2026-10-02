# 🔧 LPC2148 Menu-Driven RTC Configuration and Scheduled Device Control System

## 📌 Project Overview

This project is an Embedded Systems application developed using the LPC2148 ARM7 microcontroller and Embedded C.

The system uses the internal RTC to maintain the current time, date, and day. A 16×2 LCD is used to display RTC information and menu options, while a 4×4 matrix keypad is used for user input and configuration.

A configuration switch connected to EINT0 is used to enter the menu system. The user can configure the RTC and program the device ON/OFF schedule.

The system continuously compares the current RTC time with the configured schedule and automatically controls the connected LED/device.

---

## 🎯 Aim

To develop a menu-driven RTC-based scheduled device control system using the LPC2148 ARM7 microcontroller.

### Objectives

- Display current time, date, and day.
- Configure RTC time using a keypad.
- Configure RTC date and day.
- Configure device ON and OFF times.
- Automatically control the device according to the schedule.
- Support schedules crossing midnight.
- Validate time and date inputs.
- Use EINT0 for menu access.
- Implement the project using modular Embedded C drivers.

---

## ✨ Features

- ⏰ Real-Time Clock
- 📺 16×2 LCD Display
- ⌨️ 4×4 Matrix Keypad
- 🔘 EINT0 External Interrupt
- 💡 Automatic LED/Device Control
- ⚙️ Configurable ON/OFF Schedule
- 🌙 Midnight-Crossing Schedule
- 📅 Date Validation
- 🗓️ Leap-Year Validation
- 🧩 Modular Embedded C Architecture
- 🛠️ Keil µVision Development
- 🧪 Proteus Simulation

---

## 🧰 Hardware Requirements

| Component | Purpose |
|---|---|
| LPC2148 | Main ARM7 microcontroller |
| 16×2 LCD | Display interface |
| 4×4 Matrix Keypad | User input |
| LED / Device | Scheduled output |
| Push Button | EINT0 configuration switch |
| 10K Potentiometer | LCD contrast |
| 330Ω Resistor | LED current limiting |
| Power Supply | Circuit power |

---

## 💻 Software Requirements

- Embedded C
- Keil µVision
- Proteus
- LPC2148 Device Support

---

## 🧠 Microcontroller

### LPC2148 ARM7

The LPC2148 is an ARM7-based microcontroller used as the main controller of this project.

The microcontroller handles:

- GPIO
- RTC
- LCD interfacing
- Keypad interfacing
- External interrupt
- Schedule processing
- LED/device control

---

## 🏗️ System Architecture

The project follows a modular architecture consisting of:

- Application layer
- LCD driver
- Keypad driver
- RTC driver
- Schedule driver
- Delay driver
- Interrupt handling
- Output control

### Main Application

`output.c` handles:

- Main program flow
- Menu system
- RTC display
- RTC configuration
- Schedule configuration
- EINT0 handling
- LED/device control

### Driver Modules

| Module | Function |
|---|---|
| `LCD.c` | LCD driver |
| `KPM.c` | Keypad driver |
| `RTCLOCK.c` | RTC driver |
| `schedule.c` | Schedule processing |
| `delay.c` | Delay functions |
| `output.c` | Main application |

---

## 🔌 Hardware Connections

### LCD Interface

The project uses the LCD in 8-bit mode.

| LPC2148 Pin | LCD Signal |
|---|---|
| P0.8 – P0.15 | D0 – D7 |
| P0.16 | RS |
| P0.17 | RW |
| P0.18 | EN |

### LCD Control Signals

| Signal | Function |
|---|---|
| RS | Selects command/data |
| RW | Selects read/write operation |
| EN | Enables LCD data/command transfer |

### LCD Commands

| Command | Function |
|---|---|
| `0x01` | Clear LCD |
| `0x80` | First line, position 0 |
| `0xC0` | Second line, position 0 |

---

## ⌨️ Keypad Interface

A 4×4 matrix keypad is used for menu navigation and numeric input.

The keypad is used to:

- Select menu options
- Enter RTC values
- Enter schedule values
- Navigate between menus

Main keypad functions:

```c
INIT_KPM();
KeyScan();
ReadNum();
🔘 EINT0 Interface
The configuration switch is connected to:
P0.1 → EINT0

When the switch is pressed, EINT0 generates an external interrupt.
The ISR sets a menu request flag:
menu_request = 1;

The actual menu processing is performed in the main loop.
This keeps the ISR short and avoids performing lengthy LCD/keypad operations inside the interrupt handler.
⏰ RTC
The LPC2148 internal RTC maintains:
- Hour
- Minute
- Second
- Date
- Month
- Year
- Day of week
RTC Time Format
HH:MM:SS

Valid ranges:
Parameter	Range
Hour	0–23
Minute	0–59
Second	0–59


RTC Date Format
DD/MM/YYYY

The date is validated according to the selected month and year.
📆 Day Configuration
The project uses the following day mapping:
Value	Day
0	Sunday
1	Monday
2	Tuesday
3	Wednesday
4	Thursday
5	Friday
6	Saturday


📋 Menu Structure
Main Menu
1.RTC  2.SCH
3.EXIT

RTC Menu
1.TIME 2.DATE
3.DAY  4.BACK

TIME Menu
1.HR 2.MIN
3.SEC 4.BACK

DATE Menu
1.DATE 2.MONTH
3.YEAR 4.BACK

DAY Menu
0S 1M 2T 3W
4T 5F 6S 7B

Schedule Menu
1.ON  2.OFF
3.BACK

ON Menu
1.HR 2.MIN
3.BACK

OFF Menu
1.HR 2.MIN
3.BACK

⚙️ Schedule Operation
The schedule consists of:
- ON Hour
- ON Minute
- OFF Hour
- OFF Minute
The current RTC time is compared with the configured schedule.
Normal Schedule
Example:
ON  = 09:00
OFF = 17:00

The device operates during:
09:00 ≤ Current Time < 17:00

Therefore:
Time	Device
08:59	OFF
09:00	ON
12:00	ON
16:59	ON
17:00	OFF


The ON time is included and the OFF time is excluded.
🌙 Midnight-Crossing Schedule
The project also supports schedules where the ON time is later than the OFF time.
Example:
ON  = 22:00
OFF = 06:00

The device operates from 22:00 through midnight until 06:00.
Time	Device
21:59	OFF
22:00	ON
23:59	ON
00:00	ON
05:59	ON
06:00	OFF


This is handled by separate schedule comparison logic for the midnight-crossing case.
🚫 Same ON/OFF Time
The project rejects identical ON and OFF times.
Example:
ON  = 09:00
OFF = 09:00

The schedule is rejected because there is no valid activation period.
🛡️ Input Validation
The project validates user input before updating the RTC or schedule.
Time Validation
Hour   → 0–23
Minute → 0–59
Second → 0–59

Month Validation
Month → 1–12

Date Validation
The maximum number of days is checked according to the selected month.
January    → 31
February   → 28/29
March      → 31
April      → 30
May        → 31
June       → 30
July       → 31
August     → 31
September  → 30
October    → 31
November   → 30
December   → 31

🗓️ Leap-Year Validation
The project handles February correctly using leap-year validation.
The standard condition is:
(year % 400 == 0) ||
((year % 4 == 0) && (year % 100 != 0))

Examples:
2000 → Leap Year
2024 → Leap Year
2028 → Leap Year
2100 → Not a Leap Year

🔄 Application Flow
The application follows this general sequence:
1. Initialize LCD.
2. Initialize RTC.
3. Initialize keypad.
4. Initialize LED/device.
5. Initialize EINT0.
6. Enter the main application loop.
7. Display current RTC information.
8. Read the current RTC time.
9. Check the programmed schedule.
10. Control the LED/device.
11. Check for a menu request.
12. Open the menu when EINT0 is triggered.
13. Return to normal operation after configuration.
🔔 Interrupt Handling
The EINT0 ISR performs only the required interrupt-related operations.
ISR Responsibilities
- Set the menu request flag.
- Clear the external interrupt.
- Return from the interrupt.
Main Loop Responsibilities
- Display menus.
- Read keypad input.
- Configure RTC.
- Configure schedule.
- Update the display.
This separation improves the structure of the embedded application.
🧩 Software Architecture
Application
    |
    +-- RTC Management
    |
    +-- Menu Management
    |
    +-- Schedule Management
    |
    +-- LED/Device Control
    |
    +-- EINT0 Handling
    |
    +-- LCD Driver
    |
    +-- Keypad Driver
    |
    +-- RTC Driver
    |
    +-- Delay Driver

📁 Project Structure
LPC2148-RTC-Scheduled-Device-Control/
│
├── Source/
│   ├── output.c
│   ├── LCD.c
│   ├── LCD.h
│   ├── lcd_defines.h
│   ├── KPM.c
│   ├── kpm.h
│   ├── KPM_defines.h
│   ├── RTCLOCK.c
│   ├── rtclock.h
│   ├── schedule.c
│   ├── schedule.h
│   ├── delay.c
│   └── delay.h
│
├── Startup/
│   └── Startup.s
│
├── Proteus/
│   ├── LPC2148_Circuit.png
│   └── mini project.jpeg
│
├── Hardware/
│   ├── Hardware_Setup.jpeg
│   └── LCD.jpeg
│
└── README.md

🧪 Test Cases
Test Case	Input	Expected Result
Valid Hour	23	Accepted
Invalid Hour	24	Rejected
Valid Minute	59	Accepted
Invalid Minute	60	Rejected
Valid Second	59	Accepted
Invalid Second	60	Rejected
Valid Month	12	Accepted
Invalid Month	13	Rejected
Valid Date	30/04	Accepted
Invalid Date	31/04	Rejected
Leap-Year Date	29/02/2028	Accepted
Invalid Leap Date	29/02/2027	Rejected
Normal Schedule	09:00–17:00	Device operates correctly
Midnight Schedule	22:00–06:00	Device operates across midnight
Same ON/OFF	09:00–09:00	Schedule rejected
EINT0	Switch press	Menu opens
RTC BACK	4	Returns to Main Menu
Time BACK	4	Returns to RTC Menu
Date BACK	4	Returns to RTC Menu
Day BACK	7	Returns to RTC Menu
Schedule BACK	3	Returns to Main Menu


🧪 Proteus Simulation
The project can be tested using Proteus simulation.
Simulation Procedure
1. Build the project using Keil µVision.
2. Generate the HEX file.
3. Open the Proteus project.
4. Load the generated HEX file into the LPC2148.
5. Start the simulation.
6. Verify the LCD output.
7. Test keypad operation.
8. Press the EINT0 configuration switch.
9. Configure RTC values.
10. Configure ON/OFF schedule.
11. Verify automatic LED/device control.
🐛 Troubleshooting
Problem	Possible Area to Check
LCD not displaying	LCD power, contrast and wiring
Incorrect LCD output	Data/control connections
Keypad not responding	Row/column configuration
Wrong keypad values	Keypad mapping
RTC not updating	RTC initialization
Incorrect date	RTC date configuration
EINT0 not working	P0.1 and interrupt configuration
Menu not opening	menu_request and ISR
LED always OFF	Schedule and output control
LED always ON	Schedule comparison
Midnight schedule incorrect	Schedule comparison logic
Schedule rejected	ON/OFF time validation


📚 Concepts Demonstrated
Embedded C
- Functions
- Pointers
- Structures where required
- Header files
- Modular programming
- Conditional statements
- Loops
- Static variables
- Register-level programming
ARM7 / LPC2148
- GPIO
- RTC
- External Interrupts
- VIC
- Peripheral interfacing
Hardware Interfacing
- LCD
- Matrix keypad
- LED/device
- Push button
Firmware Concepts
- Menu-driven programming
- Input validation
- Interrupt handling
- Schedule comparison
- Device control
- Driver-based architecture
- Embedded debugging
🎓 Learning Outcomes
This project provides practical experience in:
- Embedded C programming
- ARM7 microcontroller programming
- LPC2148 peripheral programming
- LCD interfacing
- Keypad interfacing
- RTC programming
- External interrupt handling
- Schedule-based control
- Date and time validation
- Hardware debugging
- Proteus simulation
- Keil µVision development
- Modular firmware development
🚀 Future Enhancements
Possible future improvements include:
1. Multiple ON/OFF schedules.
2. Weekday-specific scheduling.
3. EEPROM/Flash-based schedule storage.
4. UART-based configuration.
5. Password/PIN protection.
6. Remote monitoring.
7. Sensor integration.
8. Event logging.
9. Relay-based appliance control.
10. Mobile-based control.
📸 Project Images
Hardware Setup
 
LCD Interface
 
Proteus Circuit
 
Project Setup
 
💼 Interview Explanation
Project Introduction
"My project is a Menu-Driven RTC Configuration and Scheduled Device Control System developed using the LPC2148 ARM7 microcontroller and Embedded C.
The LPC2148 RTC maintains the current time and date. I used a 16×2 LCD for display and a 4×4 matrix keypad for user input.
A configuration switch connected to EINT0 is used to enter the menu. From the menu, the user can configure the RTC and device ON/OFF schedule.
The firmware continuously compares the current RTC time with the configured schedule and automatically controls the connected device.
The project also supports schedules crossing midnight and validates time and date inputs before updating the RTC."
❓ Key Interview Questions
Why did you use RTC?
RTC is used to maintain the current time and date continuously. The current time is also required for schedule-based device control.
Why did you use EINT0?
EINT0 provides an external interrupt mechanism to detect the configuration switch without continuously polling the switch.
Why is the ISR kept short?
The ISR should execute quickly. Therefore, the ISR only sets a flag and clears the interrupt. Menu processing is handled by the main loop.
How do you handle a schedule crossing midnight?
When ON time is greater than OFF time, the schedule is treated as an overnight schedule. The current time is checked against both sides of midnight.
What happens when ON and OFF times are equal?
The schedule is rejected because there is no valid activation interval.
How do you validate February 29?
The year is checked using the standard leap-year condition before accepting February 29.
👨‍💻 Author
Sudheer Nandipati
Embedded Systems / Firmware Engineer – Fresher
Technical Focus
- Embedded C
- ARM7
- LPC2148
- GPIO
- RTC
- Interrupts
- LCD
- Keypad
- Hardware Interfacing
- Firmware Debugging
🔗 GitHub Repository
https://github.com/SUDHEER74/LPC2148-RTC-Scheduled-Device-Control
⭐ Project Summary
The LPC2148 Menu-Driven RTC Configuration and Scheduled Device Control System demonstrates practical Embedded Systems development using ARM7 and Embedded C.
The project integrates:
- LPC2148 ARM7
- RTC
- LCD
- Matrix keypad
- External interrupt
- Schedule logic
- LED/device control
It demonstrates how multiple microcontroller peripherals can be integrated into a modular firmware application to create a practical time-based control system.
🛠️ Technologies Used
Microcontroller : LPC2148 ARM7
Language        : Embedded C
Display         : 16×2 LCD
Input           : 4×4 Matrix Keypad
Time Source     : Internal RTC
Interrupt       : EINT0
Output          : LED / Device
IDE             : Keil µVision
Simulation      : Proteus
