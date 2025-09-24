 Custom Bootloader for STM32F407 — AUTOSAR-Inspired, CRC-Verified, Command-Driven

**Overview**

This project implements a robust, modular bootloader for the STM32F407 DISC board, architected with AUTOSAR-like layering and designed for production-grade reliability. It supports command-based firmware updates, hardware-accelerated CRC verification, and safe memory partitioning between bootloader and application code.

The bootloader resides in **Flash Sectors 0 and 1**, while the user application occupies the remaining sectors. Communication is packet-driven, with each command mapped to a well-defined handler and response logic.

---

**Layered Architecture**

Inspired by AUTOSAR principles, the project is split into clean, testable layers:

| Layer        | Description                                                                 |
|--------------|-----------------------------------------------------------------------------|
| **MCAL**     | Direct register-level access for GPIO, UART, and peripheral clocks          |
| **ECUAL**    | Abstracted drivers for UART and GPIO, decoupled from hardware specifics     |
| **BootLoader** | Core bootloader logic: command parsing, CRC checks, ACK/NACK responses     |
| **App**      | User application (not part of this repo) — loaded post-bootloader execution |

Each layer is independently testable and designed for future extension.

---

**Memory Mapping**

| Flash Sector | Address Range        | Purpose              |
|--------------|----------------------|----------------------|
| Sector 0     | 0x08000000–0x08003FFF | Bootloader Code      |
| Sector 1     | 0x08004000–0x08007FFF | Bootloader Code      |
| Sector 2+    | 0x08008000 onwards    | User Application     |

Bootloader ensures safe handoff to the application only after CRC verification and command validation.



**Packet-Based Command Protocol**

Communication is driven by serialized packets, each containing:

- **Command Code** (e.g., `BL_GET_VER`, `BL_CMD_HELP`)
- **Payload Length**
- **Payload Data**(not supported as of now)
- **CRC32 Checksum**

**Supported Commands(as of now)**

| Command Code     | Description                          |
|------------------|--------------------------------------|
| `BL_GET_VER`     | Returns bootloader version           |
| `BL_MEM_WRITE`   | Writes data to flash                 |
| `BL_JUMP_TO_APP` | Transfers control to user app        |
| `BL_ERASE_FLASH` | Erases application sectors           |
| `BL_CRC_VERIFY`  | Verifies CRC of received data        |

Each command is acknowledged with an ACK/NACK response and optional status payload.


 **CRC Verification**

- Uses **STM32 hardware CRC unit** for fast, deterministic validation.
- Ensures integrity of incoming packets before flash operations.
- Prevents accidental overwrites and corrupted jumps.


**Bootloader Flow**

1)This bootloader for STM32F407 DISC uses a GPIO-triggered entry mechanism and a UART-driven command interface to manage firmware operations securely.
2)Startup Check: If GPIOB PIN 5 is high, the bootloader enters interactive mode; otherwise, it jumps directly to the user application.
3)UART Menu Interface: Presents a command menu (BL_GET_VER, BL_GET_HELP, BL_GET_CID, etc.) and waits for user input.
4)Packet Generation: Constructs command packets with CRC integrity using build_bl_packets().
5)Command Execution: Processes packets via bootloader_uart_read_data() and responds with ACK/NACK.
6)User-Controlled Exit: Prompts user to continue in bootloader or jump to application using bootloader_jump_to_user_app().

This flow ensures safe, user-driven firmware handling with clear separation between bootloader and application memory regions.

**Hardware Requirements**

1)STM32F407 Discovery Board (or compatible Cortex-M4 MCU).

2)UART-USB Bridge (e.g., CP2102) for terminal output.

Software Requirements 1)STM32CubeIDE / Bare-metal Toolchain. 2)TeraTerm / PuTTY for UART terminal logging. 3)Git for version control.

