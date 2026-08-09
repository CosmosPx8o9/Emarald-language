
<p align="center">
  <img src="logo.png" width="180" alt="Emerald Logo">
</p>

# Emerald 

A modern implementation of the Emerald programming language, originally created in the 1980s by Andrew P. Black, Norman K. Hutchinson, Eric B. Jul, and Henry M. Levy at the University of Washington.

Emerald is a modern reimplementation of the original Emerald programming language, designed for modern distributed systems and microservice architectures while preserving the core ideas of the original language.

It is an object-oriented programming language featuring a portable virtual machine, distributed object migration, interoperability with C, native code generation,and strong static typing

## Features

- Portable Emerald VM
- Distributed object migration
- C interoperability
- Native code generation
- Strong static typing

## Example

```emerald
const out: module = import std.stdio

const Main: object = new object Main {
    initially {
        out::stdout.putstring("Hello, World!\n")
    }
}
```

## Project status

Current version 0.0.0
This project is in the early stages of development.

## Repository structure

compiler/
vm/
runtime/
docs/
examples/
stdlib/
common/

## Build

mkdir build
cd build
cmake ..
make

## Original Emerald

Official website of the original Emerald programming language:
https://www.emeraldprogramminglanguage.org

Article describing the Emerald programming language: 
https://dl.acm.org/doi/10.1145/1238844.1238855
