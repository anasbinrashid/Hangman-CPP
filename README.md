# Hangman Game

Welcome to **Hangman**, a simple console-based word-guessing game built in C++. The player tries to guess a hidden word by entering letters, with each incorrect guess bringing the hangman closer to being fully drawn. The game ends either when the player correctly guesses the word or when the hangman is fully drawn.

## How to Play
1. **Start the game** by entering a list of words separated by commas, all in lowercase.
2. **Guess letters** one by one to try and reveal the hidden word.
   - If you guess a correct letter, it will be revealed in the word.
   - If the letter is incorrect, the hangman begins to form.
3. **Repeat** until you either guess the word correctly or the hangman is completed after 7 incorrect guesses.
4. If you enter a letter that you've already guessed, the game will notify you, and you can continue guessing without penalty.

## Features
- Supports multiple words in a single game session.
- Allows unlimited correct guesses, but only 7 incorrect guesses.
- Provides feedback on already entered letters to avoid repeat guessing.

## Game Flow
1. **Enter words**: The game starts by asking you to input a comma-separated list of words. These words are then used one by one for each round.
2. **Rounds**: Each word represents a round, where you have 7 chances to guess the word. If you successfully guess the word, you move on to the next round.
3. **End of Game**: The game ends when you've either guessed all the words or run out of lives (7 wrong guesses).

## Requirements
- C++ compiler (e.g., g++, clang++)
- The code is portable and should work on any system with a standard C++ compiler.

## License
This project is licensed under the MIT License. Feel free to use, modify, and distribute the code.
