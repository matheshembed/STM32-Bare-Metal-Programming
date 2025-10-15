# 🧠 STM32 Bare Metal Programming

This repository contains my collection of **bare-metal (no HAL, no RTOS)**  for the **STM32 Nucleo-F446RE** board. Each example demonstrates how to configure and control peripherals by directly accessing **registers** as defined in the STM32 reference manual and datasheet.

---

## ⚙️ Features

- 🚀 100% Bare-Metal Code (No HAL/LL Libraries)  
- 🧩 Covers Core Peripherals:
  - GPIO (LEDs, Buttons)
  - Timers (Delay, PWM)
  - UART (Tx/Rx)
  - ADC (Analog Input)
  - Interrupts (EXTI, NVIC)
- 📚 Includes Reference Documents and Notes  
- 💻 Built using **STM32CubeIDE**

---

## 🗂️ Project Structure

STM32-Bare-Metal-Programming/
│
├── GPIO_Blink/ # Basic LED blink using GPIO registers
├── UART_Communication/ # Transmitting & receiving data over UART
├── Timer_Interrupt/ # Timer configuration with interrupts
├── ADC_Read/ # Analog to Digital conversion example
├── External_Interrupt/ # Button interrupt handling via EXTI
│
├── Data_Sheets_&_Manual/ # Reference manuals and datasheets
├── Notes/ # Key register and bitfield explanations
│
└── README.md


---

## 🧩 Tools & Environment

- **IDE:** STM32CubeIDE  
- **MCU:** STM32F446RE (ARM Cortex-M4)  
- **Debugger:** ST-Link/V2 (on-board)  
- **Language:** C  
- **Optimization:** None (for learning and clarity)

---

## 📖 References

- [STM32F446RE Reference Manual (RM0390)](https://www.st.com/resource/en/reference_manual/dm00135183.pdf)  
- [STM32F4 Series Datasheet](https://www.st.com/resource/en/datasheet/stm32f446re.pdf)  
- [ARM Cortex-M4 Generic User Guide](https://developer.arm.com/documentation/dui0553/latest/)  
- [STM32CubeIDE Documentation](https://www.st.com/en/development-tools/stm32cubeide.html)

---

## 🧠 Learning Goals

- Understand how microcontroller peripherals work at the register level  
- Learn the flow of initialization for each peripheral  
- Strengthen low-level embedded C and debugging skills  

---

## 💬 Author

**Mathesh Varma**  
🔗 [LinkedIn](www.linkedin.com/in/matheshvarma25)  
🧰 [GitHub](https://github.com/matheshembed)

---


---

## 🏁 Future Additions

- DMA Example  
- SPI & I2C Communication  
- Custom Bootloader  
- Bare-Metal RTOS-like Task Scheduler  

---

⭐ **If you find this repository helpful, consider giving it a star!**
