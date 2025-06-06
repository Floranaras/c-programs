# Flip 7: A Coding Exercise on 1D Arrays

> *If you don't have a built-in markdown viewer, you can copy the content of this file and paste it into <https://markdownlivepreview.org/> to view it formatted.*

The goal of this exercise is to:

- Design and implement fundamental algorithms on 1D arrays
- Observe proper code documentation
- Review and strengthen previously learned concepts

## Folder Content

- [`FLIP7-LastName.c`](FLIP7-LastName.c): The skeleton code containing some initial code that you need to complete
- [`main.c`](main.c) – Contains the `main()` function for testing purposes
- [`helper.c`](helper.c): Contains the function prototypes of the functions that you need to implement, as well as helper functions for displaying the output
- [`expected.txt`](expected.txt): The expected output when the program is run

## Restrictions

While you are in the PROG series, you are **NOT ALLOWED** to do the following:

- Declare and use global variables (i.e., variables declared outside any function)
- Use `exit`, `goto` (i.e., to jump from code segments to code segments), `break` (except in `switch` statements), or `continue` statements
- Use `return` statements to prematurely terminate a loop, function, or program
- Use `return` statements in `void` functions
- Call the `main()` function to repeat the process instead of using loops

In addition to the general restrictions above:

- You are **NOT ALLOWED** to include other library/header other than those already in the template

## Activity Instructions

1. Read and understand the materials provided to you. Instructions for the functions you need to implement are in the [Problem Statement](#problem-statement).
2. Implement your solution. Ensure that your final solution is able to compile with the following command:

    ```shell
    gcc -Wall -std=c99 <filename.c> -o <output>
    ```

3. Your program must be able to reproduce the same expected output. Take note that the functionality for output formatting is already implemented for you.

## Problem Statement

![Flip 7](asset-readme-flip7.png)

**Flip 7** is a fast-paced card game where players take turns flipping over cards one by one, trying not to reveal the same number twice. It sounds simple, but with a unique deck that includes only one 1 card, two 2s, three 3s, and so on, the odds get trickier with every flip. The challenge is to decide whether to keep flipping and risk busting, or play it safe and bank your points. It’s a tense mix of luck and strategy that keeps every round exciting and unpredictable.

Your task is to simulate some of the game mechanics of Flip 7 by implementing the following functions. You are given the following assumptions:

- A full deck consists of a maximum of 15 cards
  - To make testing easier, we'll work with only a subset of the full deck
- A player's hand consists of a maximum of 7 cards
- A `0` in the array means there is no card in that position

### `int drawCard(int deck[])`

This function simulates drawing a card (flipping) from the deck (array of cards). This means the 1st card is removed from the deck and the position of the remaining elements are adjusted. The last element is set to 0. The function returns the 1st card drawn. Assume that the deck is not empty.

### `int checkExists(int playerHand[], int drawnCard)`

This function simulates if the drawn card already exists in the player's hand. The function should return  `1` if the card already exists in the hand, `0` otherwise. Assume that the player's hand currently has no duplicates and that they can still draw cards.

### `void addToHand(int playerHand[], int drawnCard)`

This function simulates placing the drawn card to the player's hand. Assume that the player can still add cards to their hand.

### `void getScore(int playerHand[], int *score)`

This function gets the score by calculating the sum of the card values in the player hand. Assume that the value in `score` is not yet initialized.

### `int takeTurn(int deck[], int playerHand[])`

This function simulates a turn wherein a player draws a card and then checks if the drawn card is already in their hand. If the card exists in their hand, that means they are automatically out of the game and their score is 0. If the card does not exist in their hand, that means they can still continue playing and their running total score is updated. The drawn card is added to the player's hand regardless of whether it already exists in the hand. The function should return the score of the player.

To make this function work, this means that you must call and use the 4 prior functions properly. You are given the following assumptions:

- The deck is not empty
- The player's hand currently has no duplicates and that they can still draw cards
