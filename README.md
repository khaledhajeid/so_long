# So_Long – 2D Mini Game (42 Project)

![Language](https://img.shields.io/badge/Language-C-blue)
![Framework](https://img.shields.io/badge/MiniLibX-Graphics-yellow)
![Norminette](https://img.shields.io/badge/Norminette-Passed-brightgreen)
![Status](https://img.shields.io/badge/Build-Passing-success)
![License](https://img.shields.io/badge/License-42-blueviolet)

So_Long is a 2D tile-based game written in **C** using **MiniLibX** as part of the 42 cursus.  
The goal is simple: move the player across the map, collect all collectibles, and reach the exit to win ✅  
The project features full map validation, memory safety, event handling, and texture rendering.

---

## 📌 Table of Contents
- [📂 Project Structure](#project-structure)
- [🗺️ Map Rules](#map-rules)
- [🎮 Gameplay](#gameplay)
- [🖥️ Rendering](#rendering)
- [⚙️ How to Compile](#how-to-compile)
- [✅ Status & Implemented Features](#status--implemented-features)
- [🚀 Future Improvements](#future-improvements)
- [👨‍💻 Author](#author)

---

## 📂 Project Structure

| Path / File | Description |
|------------|-------------|
| `libft/` | Custom library including `ft_printf` |
| `get_next_line/` | Reading map files (`.ber`) line-by-line |
| `minilibx/` | Graphics library |
| `texture/` | Sprites for walls, floor, player, etc. |
| `maps/` | Map files for testing |
| `so_long.c` | Main program entry |
| `rendering.c` | Rendering the map and entities |
| `handle_movement_event.c` | Player movement logic |
| `handle_press.c` | Keyboard inputs |
| `read_texture.c` | Loading images |
| `validation.c`, `validation_of_map.c` | Map validation rules |
| `utils.c` | Helper functions |
| `free.c` | Free all allocated memory |
| `Makefile` | Build rules |

---

## 🗺️ Map Rules

Maps must use `.ber` extension.  
Valid map characters:

| Character | Meaning |
|----------|---------|
| `1` | Wall |
| `0` | Floor |
| `P` | Player |
| `C` | Collectible |
| `E` | Exit |

✅ Must follow these constraints:
- Rectangular
- Surrounded **entirely** by walls
- Exactly **1** Player **P**
- Exactly **1** Exit **E**
- At least **1** Collectible **C**
- Must be **solvable** (all collectibles and exit reachable)

---

## 🎮 Gameplay

| Key | Action |
|-----|--------|
| **W** | Move Up |
| **A** | Move Left |
| **S** | Move Down |
| **D** | Move Right |
| **ESC** | Close the game |

📌 Number of moves is printed to the terminal.

---

## 🖥️ Rendering

- Each map tile is rendered as a **64×64** texture
- Map re-renders on every movement
- No movement allowed through walls

---

## ⚙️ How to Compile

Note: you must install this before Compile the game:
```bash
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```
Run this in the terminal:
```bash
make
```
Run the game:
```bash
./so_long maps/map1.ber
```
Clean object files:
```bash
make clean
```
Remove executable:
```bash
make fclean
```
Recompile everything:
```bash
make re
```
## ✅ Status & Implemented Features

- ✅ Norm-compliant
- ✅ No memory leaks
- ✅ Map path validation (flood-fill)
- ✅ Movement & rendering fully working
- ✅ Multiple map support
- ✅ Proper event handling

## 🚀 Future Improvements

- Enemy system (game over on collision)
- Animations for player or collectibles
- Move count displayed inside window
- Improved textures / sprites

## 👨‍💻 Author

Khaled Alhaj Eid
42 Amman
🔗 GitHub: https://github.com/khaledhajeid

