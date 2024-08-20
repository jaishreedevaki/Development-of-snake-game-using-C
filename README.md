# Snake Game in C

## Overview

This project implements a classic Snake game using the C programming language. The game is designed to run in a terminal and provides a simple yet engaging experience. The player controls a snake that moves around the screen, eating food and growing longer while avoiding collisions with the boundaries and itself.

## Features

- **Snake Movement**: The snake can be controlled using the numeric keypad.
- **Food Generation**: The snake's length increases and the score is updated when it eats the food.
- **Collision Detection**: The game ends if the snake hits the wall or itself.
- **Score Tracking**: The player's score is displayed and updated in real-time.

## Game Controls

- **Move Up**: Press `8`
- **Move Down**: Press `2`
- **Move Left**: Press `4`
- **Move Right**: Press `6`
- **Exit Game**: Press `5`

## Funtions

>- **random_generator(int max_limit):**

  This function generates pseudo-random numbers within the range [0, max_limit). It uses a linear congruential generator for randomness.

>- **initial_setup():**

  Initializes the game state by placing the snake in the center of the screen and randomly positioning the food.

>- **draw_boundary():**

  Draws the game board including the snake, food, and boundaries. It also displays the current score.

>- **get_key():**

  Captures user input from the keyboard and updates the direction of the snake or exits the game.

>- **snake_movement():**
 
   Updates the snake's position based on user input, checks for collisions, and handles the logic for eating food and growing.

