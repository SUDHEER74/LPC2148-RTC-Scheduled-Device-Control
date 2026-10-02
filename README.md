# 🔧 LPC2148 Menu-Driven RTC Configuration and Scheduled Device Control System

## 📌 Project Overview

The **LPC2148 Menu-Driven RTC Configuration and Scheduled Device Control System** is an Embedded Systems project developed using the **LPC2148 ARM7 microcontroller** and **Embedded C**.

The system uses the LPC2148 internal **Real-Time Clock (RTC)** to maintain the current time, date, and day. A **16×2 LCD** is used to display RTC information and menu options, while a **4×4 matrix keypad** is used for user input and configuration.

A configuration switch connected to **EINT0** is used to enter the configuration menu.

The user can configure:

- RTC time
- RTC date
- RTC day
- Device ON time
- Device OFF time

The system continuously compares the current RTC time with the configured schedule and automatically controls the connected LED/device.

The project is implemented using a modular Embedded C architecture with separate modules for LCD, keypad, RTC, schedule, and delay functionality.

---

# 🎯 Project Aim

To develop a menu-driven RTC-based scheduled device control system using the LPC2148 ARM7 microcontroller.

---

# 🎯 Objectives

- Display the current time on a 16×2 LCD.
- Display the current date and day.
- Configure RTC time using a keypad.
- Configure RTC date and day.
- Configure device ON and OFF times.
- Automatically control the device according to the programmed schedule.
- Support schedules that cross midnight.
- Validate time and date inputs.
- Handle leap-year validation.
- Use EINT0 to enter the configuration menu.
- Implement the application using modular Embedded C drivers.

---

# ✨ Features

- ⏰ Real-Time Clock
- 📺 16×2 LCD Display
- ⌨️ 4×4 Matrix Keypad
- 🔘 EINT0 External Interrupt
- 💡 LED/Device Control
- ⚙️ Programmable ON/OFF Schedule
- 🌙 Midnight-Crossing Schedule
- 📅 Date Validation
- 🗓️ Leap-Year Validation
- 🧩 Modular Embedded C Architecture
- 🛠️ Keil µVision Development
- 🧪 Proteus Simulation

---

# 🧰 Hardware Requirements

| Component | Purpose |
|---|---|
| LPC2148 ARM7 Microcontroller | Main controller |
| 16×2 LCD | Display interface |
| 4×4 Matrix Keypad | User input |
| LED / Device | Scheduled output |
| Push Button | EINT0 configuration switch |
| 10K Potentiometer | LCD contrast |
| 330Ω Resistor | LED current limiting |
| Power Supply | Circuit power |

---

# 💻 Software Requirements

| Software / Technology | Purpose |
|---|---|
| Embedded C | Firmware development |
| Keil µVision | Compilation and development |
| Proteus | Circuit simulation |
| LPC2148 Device Support | Microcontroller development |

---

# 🧠 Microcontroller

## LPC2148 ARM7

The LPC2148 is an ARM7-based microcontroller used as the main controller of this project.

The microcontroller is responsible for:

- GPIO control
- RTC operation
- LCD interfacing
- Keypad interfacing
- External interrupt handling
- Schedule processing
- LED/device control

---

# 🏗️ System Architecture

The project follows a modular Embedded C architecture.

The main application communicates with individual peripheral and functionality modules.

### Application Module

`output.c` handles:

- Main program flow
- Menu system
- RTC display
- RTC configuration
- Schedule configuration
- EINT0 handling
- LED/device control

### Driver Modules

| Module | Responsibility |
|---|---|
| `output.c` | Main application and menu handling |
| `LCD.c` | LCD driver |
| `LCD.h` | LCD function declarations |
| `lcd_defines.h` | LCD configuration and commands |
| `KPM.c` | Keypad driver |
| `kpm.h` | Keypad declarations |
| `KPM_defines.h` | Keypad configuration |
| `RTCLOCK.c` | RTC driver |
| `rtclock.h` | RTC declarations |
| `schedule.c` | Schedule processing |
| `schedule.h` | Schedule declarations |
| `delay.c` | Delay functions |
| `delay.h` | Delay declarations |
| `Startup.s` | ARM7 startup and vector configuration |

---

# 🔌 Hardware Interface

The project integrates the LPC2148 with:

- 16×2 LCD
- 4×4 matrix keypad
- RTC
- EINT0 configuration switch
- LED/device output

The individual interfaces are controlled through dedicated driver modules.

---

# 📺 LCD Interface

The project uses a **16×2 LCD in 8-bit mode**.

The LCD configuration used by the project is:

| LPC2148 Signal | LCD Signal |
|---|---|
| P0.8 – P0.15 | D0 – D7 |
| P0.16 | RS |
| P0.17 | RW |
| P0.18 | EN |

## LCD Power Connections

| LCD Pin/Signal | Connection |
|---|---|
| VSS | GND |
| VDD | VCC |
| V0/VEE | Contrast potentiometer |
| RS | LPC2148 |
| RW | LPC2148 |
| EN | LPC2148 |
| D0–D7 | LPC2148 |

## LCD Control Signals

| Signal | Full Form | Function |
|---|---|---|
| RS | Register Select | Selects command or data register |
| RW | Read/Write | Selects read or write operation |
| EN | Enable | Enables LCD data/command transfer |

### RS Operation

- `RS = 0` → Command
- `RS = 1` → Data

### RW Operation

- `RW = 0` → Write
- `RW = 1` → Read

### EN Operation

The Enable signal is used to latch the command or data into the LCD.

---

# 📋 Important LCD Commands

| Command | Function |
|---|---|
| `0x01` | Clear LCD |
| `0x80` | First line, position 0 |
| `0xC0` | Second line, position 0 |

---

# ⌨️ 4×4 Matrix Keypad

A 4×4 matrix keypad is used as the user-input device.

The keypad is used for:

- Menu selection
- Numeric input
- RTC configuration
- Schedule configuration
- Menu navigation

The keypad driver provides functions for keypad initialization, key detection, and numeric input.

Important keypad functions include:

- `INIT_KPM()`
- `KeyScan()`
- `ReadNum()`

The keypad uses row-column scanning to detect the pressed key.

---

# 🔘 EINT0 Configuration Switch

The configuration switch is connected to:

**P0.1 → EINT0**

The switch is used to enter the configuration menu.

When the switch is pressed, the EINT0 interrupt is generated.

The interrupt service routine sets the menu request flag:

`menu_request = 1`

The main loop then detects this flag and opens the configuration menu.

The complete menu processing is not performed inside the ISR.

This keeps the ISR short and allows the main application to handle LCD and keypad operations.

---

# ⏰ Real-Time Clock

The LPC2148 internal RTC maintains:

- Hour
- Minute
- Second
- Date
- Month
- Year
- Day of week

The RTC is used for two main purposes:

1. Displaying the current date and time.
2. Providing the current time for schedule comparison.

---

# 🕐 RTC Time

The RTC time format is:

**HH:MM:SS**

Example:

**14:25:36**

## Valid Time Range

| Parameter | Valid Range |
|---|---|
| Hour | 0–23 |
| Minute | 0–59 |
| Second | 0–59 |

The entered values are validated before updating the RTC.

---

# 📅 RTC Date

The RTC date format is:

**DD/MM/YYYY**

Example:

**02/10/2026**

The project validates the entered date according to the selected month and year.

---

# 📆 RTC Day

The project uses the following day mapping:

| Key | Day |
|---|---|
| 0 | Sunday |
| 1 | Monday |
| 2 | Tuesday |
| 3 | Wednesday |
| 4 | Thursday |
| 5 | Friday |
| 6 | Saturday |
| 7 | Back |

---

# 📋 Menu System

The project uses a hierarchical menu system for RTC and schedule configuration.

## Main Menu

    1.RTC  2.SCH
    3.EXIT

### RTC

Opens the RTC configuration menu.

### SCH

Opens the schedule configuration menu.

### EXIT

Exits the configuration menu and returns to normal system operation.

---

# ⏰ RTC Menu

The RTC menu is:

    1.TIME 2.DATE
    3.DAY  4.BACK

### TIME

Opens the time configuration menu.

### DATE

Opens the date configuration menu.

### DAY

Opens the day selection menu.

### BACK

Returns directly to the main menu.

---

# 🕐 TIME Menu

The Time menu is:

    1.HR 2.MIN
    3.SEC 4.BACK

### HR

Sets the RTC hour.

Valid range:

**0–23**

### MIN

Sets the RTC minute.

Valid range:

**0–59**

### SEC

Sets the RTC second.

Valid range:

**0–59**

### BACK

Returns to the RTC menu.

---

# 📅 DATE Menu

The Date menu is:

    1.DATE 2.MONTH
    3.YEAR 4.BACK

### DATE

Sets the RTC date.

### MONTH

Sets the RTC month.

Valid range:

**1–12**

### YEAR

Sets the RTC year.

### BACK

Returns to the RTC menu.

---

# 📆 DAY Menu

All day options are displayed together:

    0S 1M 2T 3W
    4T 5F 6S 7B

Where:

| Key | Function |
|---|---|
| 0 | Sunday |
| 1 | Monday |
| 2 | Tuesday |
| 3 | Wednesday |
| 4 | Thursday |
| 5 | Friday |
| 6 | Saturday |
| 7 | Back |

Selecting `0–6` updates the RTC day.

Selecting `7` returns to the RTC menu.

---

# ⚙️ Schedule Menu

The schedule menu is:

    1.ON  2.OFF
    3.BACK

The schedule contains:

- ON Hour
- ON Minute
- OFF Hour
- OFF Minute

---

# 🟢 ON Menu

The ON menu is:

    1.HR 2.MIN
    3.BACK

The user can configure:

- ON Hour
- ON Minute

---

# 🔴 OFF Menu

The OFF menu is:

    1.HR 2.MIN
    3.BACK

The user can configure:

- OFF Hour
- OFF Minute

---

# ⏱️ Schedule Operation

The current RTC time is continuously compared with the configured ON and OFF times.

The schedule supports two cases:

1. Normal same-day schedule
2. Midnight-crossing schedule

---

# 🟢 Normal Schedule

When:

**ON TIME < OFF TIME**

Example:

**ON = 09:00**

**OFF = 17:00**

The device is active when:

**ON_TIME ≤ CURRENT_TIME < OFF_TIME**

### Expected Operation

| Current Time | Device |
|---|---|
| 08:59 | OFF |
| 09:00 | ON |
| 12:00 | ON |
| 16:59 | ON |
| 17:00 | OFF |
| 17:01 | OFF |

The ON boundary is included.

The OFF boundary is excluded.

---

# 🌙 Midnight-Crossing Schedule

The project also supports schedules where:

**ON TIME > OFF TIME**

Example:

**ON = 22:00**

**OFF = 06:00**

The device operates from 22:00 through midnight and continues until 06:00.

### Expected Operation

| Current Time | Device |
|---|---|
| 21:59 | OFF |
| 22:00 | ON |
| 23:59 | ON |
| 00:00 | ON |
| 05:59 | ON |
| 06:00 | OFF |

This is handled using separate schedule comparison logic for the midnight-crossing condition.

---

# 🚫 Same ON/OFF Time

If:

**ON TIME = OFF TIME**

the schedule is rejected.

Example:

**ON = 09:00**

**OFF = 09:00**

Expected result:

**SAME TIME**

The user must configure different ON and OFF times.

---

# 🛡️ Input Validation

The project validates all important user inputs before updating the RTC or schedule.

## Time Validation

| Parameter | Valid Range |
|---|---|
| Hour | 0–23 |
| Minute | 0–59 |
| Second | 0–59 |

## Month Validation

| Parameter | Valid Range |
|---|---|
| Month | 1–12 |

## Day Validation

| Parameter | Valid Range |
|---|---|
| Day | 0–6 |

---

# 📅 Date Validation

The maximum number of days depends on the selected month.

| Month | Maximum Days |
|---|---:|
| January | 31 |
| February | 28/29 |
| March | 31 |
| April | 30 |
| May | 31 |
| June | 30 |
| July | 31 |
| August | 31 |
| September | 30 |
| October | 31 |
| November | 30 |
| December | 31 |

Examples:

| Date | Result |
|---|---|
| 30/04 | Valid |
| 31/04 | Invalid |
| 28/02 | Valid |
| 29/02 | Depends on leap year |

---

# 🗓️ Leap-Year Validation

The project checks whether the selected year is a leap year before accepting February 29.

The standard leap-year condition is:

`(year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))`

Examples:

| Year | Result |
|---|---|
| 2000 | Leap Year |
| 2024 | Leap Year |
| 2028 | Leap Year |
| 2100 | Not a Leap Year |

---

# 🔔 EINT0 Interrupt Handling

The EINT0 interrupt is used only to request entry into the configuration menu.

The ISR performs the following operations:

1. Set `menu_request`.
2. Clear the external interrupt.
3. Return from the interrupt.

The main application performs:

1. Check `menu_request`.
2. Open the main menu.
3. Process keypad input.
4. Configure RTC or schedule.
5. Return to normal operation.

This approach avoids lengthy processing inside the interrupt service routine.

---

# 🔄 Main Application Flow

The main application performs the following operations:

1. Initialize LCD.
2. Initialize RTC.
3. Initialize keypad.
4. Initialize LED/device.
5. Initialize EINT0.
6. Enter the main loop.
7. Display current RTC information.
8. Read current RTC time.
9. Check the programmed schedule.
10. Control the LED/device.
11. Check the menu request flag.
12. Open the configuration menu if requested.
13. Return to normal operation.

---

# 🧩 Software Modules

## `output.c`

Responsible for the main application.

Functions include:

- Menu handling
- RTC display
- RTC configuration
- Schedule configuration
- EINT0 initialization
- EINT0 ISR
- LED/device control
- Main application loop

## `LCD.c`

Responsible for LCD operations.

Functions include:

- LCD initialization
- Sending commands
- Sending data
- Displaying strings
- Displaying numbers

## `KPM.c`

Responsible for keypad operations.

Functions include:

- Keypad initialization
- Key scanning
- Numeric input

## `RTCLOCK.c`

Responsible for RTC operations.

Functions include:

- RTC initialization
- Setting time
- Reading time
- Setting date
- Reading date
- Setting day
- Reading day

## `schedule.c`

Responsible for schedule processing.

Functions include:

- Setting ON/OFF schedule
- Converting time for comparison
- Checking whether the schedule is active
- Supporting midnight-crossing schedules

## `delay.c`

Provides required software delay functions.

---

# 📁 Project Structure

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

---

# 🧪 Test Cases

| Test Case | Input | Expected Result |
|---|---|---|
| Valid Hour | 23 | Accepted |
| Invalid Hour | 24 | Rejected |
| Valid Minute | 59 | Accepted |
| Invalid Minute | 60 | Rejected |
| Valid Second | 59 | Accepted |
| Invalid Second | 60 | Rejected |
| Valid Month | 12 | Accepted |
| Invalid Month | 13 | Rejected |
| Valid Date | 30/04 | Accepted |
| Invalid Date | 31/04 | Rejected |
| Leap-Year Date | 29/02/2028 | Accepted |
| Invalid Leap Date | 29/02/2027 | Rejected |
| Normal Schedule | 09:00–17:00 | Device operates correctly |
| Midnight Schedule | 22:00–06:00 | Device operates across midnight |
| Same ON/OFF | 09:00–09:00 | Schedule rejected |
| EINT0 | Switch press | Menu opens |
| RTC BACK | 4 | Returns to Main Menu |
| Time BACK | 4 | Returns to RTC Menu |
| Date BACK | 4 | Returns to RTC Menu |
| Day BACK | 7 | Returns to RTC Menu |
| Schedule BACK | 3 | Returns to Main Menu |

---

# 🧪 Proteus Simulation

The project can be tested using Proteus simulation.

## Simulation Procedure

1. Open the project in Keil µVision.
2. Build the project.
3. Generate the HEX file.
4. Open the Proteus circuit.
5. Load the generated HEX file into the LPC2148.
6. Start the simulation.
7. Verify the LCD output.
8. Test keypad operation.
9. Press the EINT0 configuration switch.
10. Configure RTC values.
11. Configure ON/OFF schedule.
12. Verify automatic LED/device control.

---

# 🐛 Troubleshooting

| Problem | Possible Cause |
|---|---|
| LCD not displaying | Power, contrast or wiring issue |
| Incorrect LCD characters | Data/control connection issue |
| Keypad not responding | Row/column configuration |
| Wrong keypad values | Keypad mapping |
| RTC not updating | RTC initialization/configuration |
| Incorrect date | Invalid RTC configuration |
| EINT0 not working | P0.1 or interrupt configuration |
| Menu not opening | `menu_request` or ISR issue |
| LED always OFF | Schedule/output configuration |
| LED always ON | Schedule comparison/output configuration |
| Midnight schedule incorrect | Schedule comparison logic |
| Schedule rejected | Same ON/OFF time |

---

# 🔍 Debugging Approach

A systematic debugging approach can be followed:

1. Verify power supply.
2. Verify LPC2148 operation.
3. Test LCD separately.
4. Test keypad separately.
5. Test RTC.
6. Test EINT0.
7. Test schedule logic.
8. Test LED/device control.
9. Test the complete application.

Testing each module independently makes it easier to identify hardware or firmware problems.

---

# 📚 Embedded Concepts Used

## Embedded C

- Functions
- Pointers
- Variables
- Loops
- Conditional statements
- Static variables
- Header files
- Modular programming
- Register-level programming

## ARM7 / LPC2148

- ARM7 architecture
- GPIO
- RTC
- External Interrupts
- VIC

## Hardware Interfacing

- 16×2 LCD
- 4×4 Matrix Keypad
- LED/device
- Push button

## Firmware Concepts

- Menu-driven programming
- Input validation
- Interrupt handling
- Schedule comparison
- Device control
- Driver development
- Hardware debugging

---

# 🎓 Learning Outcomes

Through this project, I gained practical experience in:

- Embedded C programming
- ARM7 microcontroller programming
- LPC2148 programming
- GPIO
- RTC programming
- LCD interfacing
- Keypad interfacing
- External interrupt handling
- Schedule-based device control
- Date validation
- Leap-year logic
- Firmware debugging
- Proteus simulation
- Keil µVision
- Modular Embedded C development

---

# 🚀 Future Enhancements

The project can be extended with:

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

---

# 📸 Project Images

## Hardware Setup

![Hardware Setup](Hardware/Hardware_Setup.jpeg)

## LCD Interface

![LCD Interface](Hardware/LCD.jpeg)

## Proteus Circuit

![Proteus Circuit](Proteus/LPC2148_Circuit.png)

## Project Setup

![Project Setup](Proteus/mini%20project.jpeg)

---



---

# ⭐ Project Highlights

- 🔧 LPC2148 ARM7
- 💻 Embedded C
- ⏰ RTC
- 📺 16×2 LCD
- ⌨️ 4×4 Matrix Keypad
- 🔘 EINT0
- 💡 LED/Device Control
- ⚙️ Programmable Schedule
- 🌙 Midnight-Crossing Schedule
- 📅 Date Validation
- 🗓️ Leap-Year Validation
- 🧩 Modular Drivers
- 🛠️ Keil µVision
- 🧪 Proteus

---

# 👨‍💻 Author

## Sudheer Nandipati

**Embedded Systems / Firmware Engineer – Fresher**

### Technical Focus

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

---

# 📌 Project Summary

The **LPC2148 Menu-Driven RTC Configuration and Scheduled Device Control System** demonstrates practical Embedded Systems development using ARM7 and Embedded C.

The project integrates:

- LPC2148 ARM7
- Internal RTC
- 16×2 LCD
- 4×4 Matrix Keypad
- EINT0 external interrupt
- Schedule logic
- LED/device control

The RTC maintains the current time and date.

The LCD displays system information and menu options.

The keypad allows the user to configure the RTC and schedule.

The EINT0 switch provides access to the configuration menu.

The schedule logic compares the current RTC time with the configured ON/OFF period and automatically controls the device.

The project supports both normal schedules and schedules that cross midnight.

It also includes time validation, date validation, leap-year validation, and same ON/OFF time checking.

---

# 🛠️ Technologies Used

| Technology | Used For |
|---|---|
| LPC2148 ARM7 | Main Microcontroller |
| Embedded C | Firmware |
| 16×2 LCD | Display |
| 4×4 Matrix Keypad | User Input |
| Internal RTC | Time and Date |
| EINT0 | External Interrupt |
| LED/Device | Output Control |
| Keil µVision | Development |
| Proteus | Simulation |

---

# 👨‍💻 Author

## Sudheer Nandipati

