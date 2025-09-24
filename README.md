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

## 🛡️ Memory Mapping

| Flash Sector | Address Range        | Purpose              |
|--------------|----------------------|----------------------|
| Sector 0     | 0x08000000–0x08003FFF | Bootloader Code      |
| Sector 1     | 0x08004000–0x08007FFF | Bootloader Code      |
| Sector 2+    | 0x08008000 onwards    | User Application     |

Bootloader ensures safe handoff to the application only after CRC verification and command validation.

---

**Packet-Based Command Protocol**

Communication is driven by serialized packets, each containing:

- **Command Code** (e.g., `BL_GET_VER`, `BL_MEM_WRITE`)
- **Payload Length**
- **Payload Data**
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

---

 **CRC Verification**

- Uses **STM32 hardware CRC unit** for fast, deterministic validation.
- Ensures integrity of incoming packets before flash operations.
- Prevents accidental overwrites and corrupted jumps.

---

**Bootloader Flow**

1. **Startup**: Initializes clocks, UART, and CRC peripheral.
2. **Command Listening**: Waits for valid command packets via UART.
3. **Packet Parsing**: Validates structure and CRC.
4. **Execution**: Performs flash write/erase/jump based on command.
5. **Response**: Sends ACK/NACK and optional data.
6. **Handoff**: Jumps to application if requested and verified.

---

## 📁 Folder Structure

