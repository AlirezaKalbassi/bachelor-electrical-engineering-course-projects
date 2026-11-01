# Console Maze Game (C++)

A console maze game written in C++ for the Introductory Programming course. You steer a small character
through a hand-drawn maze, avoid moving obstacles, and try to reach the exit in the bottom-right corner.

## Gameplay

- Move the character (a small figure made of six `*` characters) from the top-left corner to the exit in the bottom-right corner.
- You start with **3 hearts**, shown under the maze.
- Touching a **moving obstacle** costs one heart. At zero hearts the game is over.
- Touching a **maze wall or the outer border** ends the game immediately.
- Reaching the exit shows the **YOU WIN!!** screen.

The maze has four sections separated by walls with gaps. Each section has two moving obstacles that sweep
along a row or column and then restart from their starting point.

### Controls

| Key | Action |
|---|---|
| `w` | Move up |
| `a` | Move left |
| `s` | Move down |
| `d` | Move right |

Use lowercase letters (Caps Lock off).

### The maze

```
|----------------------------------------------------|
|               |                                    |
|               |                                    |
|               |                                    |
|               |                                    |
|               |                                    |
|               |                                    |
|               |                |-------     -------|
|               |                |                   |
|               |                |                   |
|               |                |                   |
|               |                |                   |
|               |                |                   |
|-----     -----|                |                   |
|                                |                   |
|                                |                   |
|                                |                   |
|                                |                   |
|                                |                   |
|                                |                   |
|                                |-------     -------|
|                                |                   |
|                                |                   |
|                                |                   |
|      |-------------------------|                   |
|      |                                             |
|      |                                             |
|      |                                             |
|      |                                             |
|      |                                             |
|      |                                             |
|      |                                             |
|      |                                             |
|      |                                             |
|------|---------------------------------------------|
```

## How it works

- **Drawing:** `gotoxy()` moves the console cursor with `SetConsoleCursorPosition`, so the maze, obstacles, and character are drawn at exact coordinates. The screen is cleared and redrawn every frame.
- **Input:** `_kbhit()` and `_getch()` read key presses without stopping the game loop, so the obstacles keep moving while you play.
- **Obstacles:** each of the eight obstacles has its own position and step counter, and moves one cell per frame until it reaches the end of its path.
- **Collisions:** every frame, the six cells of the character are compared with the wall coordinates (game over) and with the obstacle coordinates (lose a heart).
- **Screens:** `main_page()` draws the maze, and `game_over()` and `you_win()` draw the end screens.

## Build and run

The game uses `conio.h` and the Windows console API, so it runs on **Windows**.

1. Open `game (final project).sln` in Visual Studio.
2. Build and run with **Ctrl + F5**.
3. Make the console window at least 55 columns wide and 40 rows tall so the maze is not cut off.

## Files

| File | Description |
|---|---|
| `game (final project).cpp` | Complete game source code |
| `game (final project).sln` | Visual Studio solution |
| `game (final project).vcxproj` | Visual Studio project file |

## Concepts practiced

- Functions and program structure
- Loops and conditionals for the game loop and collision checks
- Console graphics with cursor positioning
- Non-blocking keyboard input
