# sxOS

`sxOS` is a bare-metal operating system developed from scratch in C and assembly. This OS is designed to run directly on hardware or in a virtualized environment (like QEMU) and serves as a foundation for learning OS development, low-level programming, and embedded systems.

Redirect to https://github.com/sudoXpg/x86_protected_mode

## Table of Contents
- [Features](#features)
- [File Structure](#file-structure)
- [Code Overview](#code-overview)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Build Instructions](#build-instructions)
  - [Running sxOS](#running-sxos)
- [Contributing](#contributing)
- [License](#license)

## Features

- Custom kernel with basic bootstrapping and memory management
- Support for low-level I/O operations
- Basic display and interrupt handling capabilities
- Modular and organized codebase for easy expansion and experimentation

## File Structure

The `sxOS` repository is organized as follows:

```plaintext
sxOS/
├── Makefile               # Build instructions
├── build.sh               # Script to automate building
├── bin/                   # Output directory for compiled binaries
│   ├── boot.bin           # Compiled boot sector
│   ├── kernel.bin         # Compiled kernel
│   └── os.bin             # Combined OS binary
├── build/                 # Intermediate build files
│   ├── config.o           # Configuration object file
│   ├── display/           # Display-related object files
│   ├── idt/               # Interrupt descriptor table files
│   ├── io/                # Low-level I/O handling files
│   ├── kernel.asm.o       # Kernel assembly object file
│   ├── kernel.o           # Kernel main object file
│   ├── kernelfull.o       # Linked full kernel binary
│   └── mem/               # Memory management object files
└── src/                   # Source code for sxOS
    ├── boot/              # Bootloader code
    ├── config.c, config.h # Configuration settings
    ├── display/           # Display driver and graphics code
    ├── idt/               # Interrupt Descriptor Table setup
    ├── io/                # Low-level I/O operations
    ├── kernel.asm         # Assembly code for kernel entry
    ├── kernel.c, kernel.h # Main kernel code and headers
    ├── linker.ld          # Linker script
    ├── mem/               # Memory management routines
    └── string/            # String and memory utilities
```
## Code Overview

### Core Components

    boot/: Contains the bootloader code (boot.bin) that initializes the CPU and loads the kernel. This code handles the setup required to switch the CPU to protected mode, enabling advanced OS features.

    config.h: Defines configuration constants and settings used across the OS, such as memory limits, stack sizes, and display settings.

    display/: Implements display-related functions. This includes code to manage text or graphics output on the screen, helping with debugging and user interactions by providing visual feedback.

    idt/: Responsible for setting up the Interrupt Descriptor Table (IDT), allowing the OS to handle hardware and software interrupts. This is critical for multitasking and managing external events.

    io/: Contains low-level input/output functions that handle port-mapped I/O. Essential for interacting directly with hardware, including the keyboard and other peripherals.

    kernel.asm / kernel.c: The core of sxOS. kernel.asm contains the assembly startup code that prepares the system before handing control to kernel.c. The C file (kernel.c) contains the main loop and fundamental functions of the OS.

    linker.ld: A linker script specifying how the output binary (os.bin) is organized in memory. This script arranges code, data, and stack sections properly for execution.

    mem/: Contains memory management routines. These functions include setting up basic memory allocation, initializing memory regions, and potentially implementing a simple heap.

    string/: Provides utilities for handling strings and memory operations. These functions are often similar to memcpy, memset, and strlen but tailored for the bare-metal environment without relying on external libraries.

### Binaries and Build Artifacts

    Makefile: The main build file that automates the compilation and linking process. Run make to build all necessary components and generate the OS binary.

    build.sh: Script that provides a simplified way to build the project by running the necessary make commands.

    bin/:
        boot.bin: The compiled bootloader binary, which prepares the system for loading the kernel.
        kernel.bin: The compiled kernel binary.
        os.bin: The final combined binary, containing both the bootloader and kernel, ready for execution.

## Getting Started
### Prerequisites

    Cross Compiler: You will need an i686-elf cross-compiler to build sxOS. Instructions can be found on the OSDev Cross Compiler Guide.
    QEMU: For testing the OS in a virtual machine environment.

## Build Instructions

Clone the repository and navigate to the project directory:

```
git clone https://github.com/sudoXpg/sxOS
cd sxOS
```
To build the OS, run:
```
make
```
This will compile the code and place the binaries in the bin/ directory.
Running sxOS

To test sxOS using QEMU:
```
qemu-system-i386 -hda ./bin/os.bin
```
This command will launch sxOS in the QEMU virtual machine, allowing you to interact with and test the OS.
Contributing

Contributions are welcome! To contribute:

    Fork the repository.
    Create a new branch for your feature or bug fix.
    Submit a pull request with a description of the changes.

License

This project is licensed under the MIT License. See [LICENSE](LISENCE) for details.
