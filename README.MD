# Cub3D Project Documentation

## Table of Contents
1. [Introduction](#introduction)
2. [Project Structure](#project-structure)
3. [Main Module](#main-module)
4. [Algorithms](#algorithms)
5. [User Interface](#user-interface)
6. [Rendering](#rendering)
7. [Utilities](#utilities)
8. [Workflow](#workflow)
9. [Contributors](#contributors)

## Introduction

Cub3D is a raycasting engine inspired by the classic game Wolfenstein 3D. The program creates a 3D perspective in a 2D map, allowing players to move through a maze rendered with textured walls.

## Project Structure

The project is organized into several key modules:

- **Main**: The entry point of the application
- **Algorithms**: Functions for raycasting and player position calculations
- **Macro**: Input handling and player movement
- **Rendering**: 3D visualization and texture management
- **Utilities**: Helper functions for various tasks

## Main Module

### main.c

- **main()**: Entry point of the program. Initializes the game data, sets up the player, and starts the 3D rendering process. Handles cleanup upon exit.

## Algorithms

### init_player.c
- **initialize_player()**: Sets up the player's initial position and direction vector based on the map data.

### degree_to_radian.c
- **degree_to_radian()**: Converts angle measurements from degrees to radians for trigonometric calculations.

### ray_cast.c
- **ray_cast()**: The core raycasting function. Sends rays from the player's position and detects wall intersections. Returns hit information and coordinates.

### init_ray_steps.c
- **init_ray_data()**: Initializes the data structure for a single ray with the appropriate angle based on screen position.
- **init_ray_steps()**: Calculates the step values for the DDA (Digital Differential Analysis) algorithm used in raycasting.

### calculate_intersection.c
- **calculate_intersection()**: Determines where a ray intersects with a wall, computing the exact coordinates.

### get_player_orientation.c
- **get_player_orientation()**: Extracts the player's initial orientation (N, S, E, W) from the map data.
- **get_base_angle()**: Converts the character orientation to a numerical angle in degrees.

### wall_calculations.c
- Functions for calculating wall distances and properties for rendering.

## User Interface

### hook.c
- **window_hook()**: Handles window events, particularly closing the window.
- **key_press_hook()**: Processes keyboard key presses for player movement and actions.
- **key_release_hook()**: Handles key release events to stop player actions.

### moves.c
- **move_player_forward()**: Moves the player forward based on the current direction vector.
- **move_player_backward()**: Moves the player backward, opposite to the current direction vector.
- **move_player_left()**: Strafes the player left (perpendicular to the direction vector).
- **move_player_right()**: Strafes the player right (perpendicular to the direction vector).

### rotates.c
- **rotate_player_left()**: Rotates the player's view to the left.
- **rotate_player_right()**: Rotates the player's view to the right.

## Rendering

### rendering.c
- **init_3d_rendering()**: Sets up the 3D rendering environment, initializing window, textures, and event handlers.
- **render()**: Main rendering function that clears the window and renders the 3D view.
- **update_3d_view()**: Game loop function that handles player movement and view updates.

### render_3d_view.c
- **render_3d_view()**: Casts rays across the screen width and renders the resulting walls.
- **calculate_distance()**: Calculates the distance to wall intersections and applies the fisheye correction.
- **process_ray()**: Processes a single ray, calculating its intersection and wall orientation.

### draw_vertical_line.c
- **draw_vertical_line()**: Draws a single vertical slice of a wall with the appropriate texture.
- **get_wall_texture()**: Returns the correct texture based on the wall's orientation.
- **draw_ceiling()**: Draws the ceiling for a vertical slice.
- **draw_floor()**: Draws the floor for a vertical slice.
- **draw_wall()**: Draws the textured wall for a vertical slice.

### determine_wall_orientation.c
- **determine_wall_orientation_part1/2/3()**: Determines which side of a wall (North, South, East, West) the ray hit based on intersection coordinates.

### init.c / init2.c
- **init_window_info()**: Configures the window creation parameters.
- **init_keys_3d()**: Initializes the keyboard input state.
- **init_render_params()**: Sets up the parameters needed for rendering a vertical slice.
- **init_line_data_part1/2/3()**: Initialize different aspects of the line drawing data.
- **init_colors()**: Sets up ceiling and floor colors from configuration.

### load_textures.c
- **load_textures()**: Loads wall textures from image files.

## Utilities

### convert_rgb_str_to_color.c
- **convert_rgb_str_to_color()**: Converts RGB string representation to a color value.

## Workflow

The program follows this general workflow:

1. Initialization of game data, player position, and rendering environment
2. Main game loop:
   - Process user input
   - Update player position and orientation
   - Cast rays for each vertical slice of the screen
   - Calculate wall distances and orientations
   - Apply textures based on wall orientation
   - Render the scene with appropriate ceiling and floor colors
3. Cleanup and exit when the user closes the window

The raycasting algorithm works by casting rays from the player's position at different angles across the viewport. For each ray:
1. Calculate the ray direction
2. Step through the map grid using DDA (Digital Differential Analysis)
3. Detect wall collisions
4. Calculate the distance to the wall (with fisheye correction)
5. Determine the wall height and orientation
6. Apply the appropriate texture based on the wall orientation
7. Draw the wall slice with the right portion of the texture

This creates the illusion of a 3D environment while maintaining fast performance even on less powerful hardware.

## Contributors

- [Mastau](https://github.com/Mastau)
- [Wormav](https://github.com/Wormav)
