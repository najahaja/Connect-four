# Connect Four - C++ SFML Implementation

## Overview

This project is a C++ implementation of the classic Connect Four game using the SFML library. The game is designed for two players, where each player takes turns dropping colored discs into a vertical grid. The objective is to connect four of one's own discs horizontally, vertically, or diagonally before the opponent.

## Features

- Two-player gameplay.
- Graphical user interface with a visual representation of the game board.
- Dynamic status updates to indicate the current player's turn.
- Visual indication of the winning sequence of discs.
- Option to reset the game and start a new match.

## Prerequisites

- C++ Compiler
- SFML Library (version 2.5.1 or later)

## Setup Instructions

1. **Install SFML**

   Follow the instructions on the [official SFML website](https://www.sfml-dev.org/download.php) to download and install SFML for your operating system.

2. **Clone the Repository**

   ```bash
   git clone <repository-url>
   cd connect-four
3.**Compile the Code**

    Ensure you have a C++ compiler installed. Use the following command to compile the code:

    ```bash
    g++ -o connect_four main.cpp -lsfml-graphics -lsfml-window -lsfml-system
4.**Run the Game**

  ```bash
./connect_four
