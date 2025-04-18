# 🐍 Snake Game in C (Console-Based)

This project is a classic implementation of the Snake Game using the C programming language, designed to run entirely in the Windows console. It features real-time input handling, dynamic tail growth, a scoring system, and persistent high score tracking — all while using simple emoji visuals for a fun retro look.

---

## 🎮 Features

- 🐍 Snake grows longer with each 🍎 fruit eaten
- ⌨️ Arrow key controls for smooth movement
- 💾 High score saved between sessions (`highscore.txt`)
- 🎯 Game Over screen with final score display
- 🧠 Smart logic for snake movement, collision detection, and tail tracking
- 🎨 Colorful emoji-based UI for a unique console gaming experience
- ⚡ Adjustable game speed using `Sleep()`

---

## 🧱 Technologies Used

- **Language**: C (ANSI C with Windows-specific headers)
- **Headers**:
  - `stdio.h`, `stdlib.h`: Standard I/O and memory
  - `conio.h`: Console input handling (`_getch`, `_kbhit`)
  - `windows.h`: Sleep and future sound support (`Beep`)
- **Platform**: Windows Console (CMD/PowerShell)

---

## 🚀 How to Run

1. **Clone or Download** the project files.
2. **Open Command Prompt** in the project directory.
3. **Compile the source code** using GCC (e.g., from MinGW):
   ```bash
   gcc snake_game.c -o snake_game.exe
Run the game:

bash
Copy
Edit
snake_game.exe
🎮 Controls

Key	Action
⬅️ Arrow Left	Move Left
➡️ Arrow Right	Move Right
⬆️ Arrow Up	Move Up
⬇️ Arrow Down	Move Down
❌ X Key	Exit the Game
📁 Files
snake_game.c — Main source code file

highscore.txt — Stores the highest score (auto-created)

README.md — Project documentation

🧠 Game Logic Overview
Snake Movement: Uses an integer flag to track direction. Tail arrays store previous positions.

Fruit Generation: Randomized using rand() within board dimensions.

Collision Detection: Ends the game if snake hits walls or itself.

Score System: +10 points per fruit; high score stored persistently.

👥 Project Team
This project was collaboratively developed as part of a C programming mini-project:

👑 Roshan (Team Leader)

👩‍💻 Sanana

👨‍💻 Labeed

👩‍💻 Keerthana

👩‍💻 Farhana

👩‍💻 Haniya

📌 Additional Ideas for Improvement
🔊 Add sound effects using Beep() or external libraries

🌈 Add colored output using Windows console functions

💾 Add save/load functionality for game state

🎮 Convert to GUI using SDL2 or graphics.h for better visuals

Happy Coding and Gaming! 🕹️

---
