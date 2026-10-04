# 🔧 LPC2148 Menu-Driven RTC Configuration and Scheduled Device Control System

## 📌 Project Overview

This project is a menu-driven Embedded Systems project developed using the **LPC2148 ARM7 microcontroller**.

The system uses the **Real-Time Clock (RTC)** to maintain the current date and time. A **4×4 matrix keypad** is used to configure RTC parameters and the device ON/OFF schedule.

A configuration switch connected to **EINT0** is used to enter the menu. The programmed schedule is continuously compared with the current RTC time, and the LED/device is automatically controlled.

## ✨ Features

- ⏰ RTC time display
- ⚙️ RTC time configuration
- 📅 RTC date configuration
- 🗓️ RTC day configuration
- ⌨️ 4×4 matrix keypad input
- 📋 Menu-driven operation
- ⏱️ Programmable ON/OFF schedule
- 💡 Automatic LED/device control
- 🔘 EINT0 external interrupt
- ✅ Date validation
- 🗓️ Leap-year validation
- 🧩 Modular Embedded C implementation

## 🧰 Hardware

- 🔧 LPC2148 ARM7 Microcontroller
- 📺 16×2 LCD
- ⌨️ 4×4 Matrix Keypad
- 💡 LED
- 🔘 Configuration Switch
- ⏰ RTC

## 💻 Software Tools

- 🛠️ Keil µVision
- 💻 Embedded C
- 🧪 Proteus

## 📋 Main Menu

```text
1. RTC
2. SCH
3. EXIT

