# Competitive Programming Code Library

This directory contains my standard templates and Sublime Text setup for Competitive Programming in C++.

## Files Included

- **`code.cpp`**
  A standard C++ template used as a starting point for solving problems. It includes:
  - Fast I/O (`ios_base::sync_with_stdio(false); cin.tie(nullptr);`).
  - Required includes (`#include <bits/stdc++.h>`).
  - A basic `solve()` function structure inside a test case loop.

- **`random_generator.cpp`**
  A utility template for generating high-quality 64-bit random integers.
  - Utilizes `mt19937` (Mersenne Twister generator).
  - Seeded automatically using `chrono::steady_clock`.
  - Provides a convenient `ran(a, b)` function to get random numbers within a specific range `[a, b]`.

- **`c++17_mac_os.sublime-build`**
  A custom Sublime Text build system tailored for macOS.
  - **Compiler**: `g++-15`
  - **Standard**: C++17 (`-std=c++17`)
  - **I/O Redirection**: Automatically reads standard input from `input.txt` and writes standard output to `output.txt` within the same directory.
  - **Target OS Version**: macOS 15.0 (`-mmacosx-version-min=15.0`)

## Usage

1. Create a problem file, for example, `A.cpp`, using `code.cpp` as your template.
2. In the same directory, create two empty files: `input.txt` and `output.txt`.
3. In Sublime Text, select the custom C++17 build system (if placed in your `User` packages folder; otherwise simply use it via its path).
4. Write your logic, place any sample input into `input.txt`, and build (typically `Cmd+B` on Mac). The execution results will be written to `output.txt`.
