## Project Description
so_long is a 2D game where the player controls a character with the goal of collecting all items scattered across a predefined map and escaping via the shortest possible route. The game simulates a maze-like environment, requiring strategic decisions from the player while navigating the available paths.

<div align="center" max-width="auto" max-height="auto">
	<img src="IMG_9918.png" max-height="250" alight="center">
</div>

## Features
Character Movement: The player uses the W, A, S, D keys to move the character in the up, left, down, and right directions, respectively.

Environment Interaction: The player cannot walk through walls and must collect all items before reaching the exit.

Move Counter: Every time the player moves, the total number of moves is updated and displayed in the terminal in real-time.

2D View: The game is presented in a two-dimensional view, with each map element represented by custom textures and sprites.

## Game Rules

The player must collect all collectible items before accessing the exit.
Movement is restricted by obstacles (walls), making it necessary to find the optimal path.
The game interface is responsive, providing immediate feedback on player actions.

## Technologies Used

 Minilibx:
A graphical library used to render game elements in an interactive window.
 C Language: 
Implementation of the game mechanics and movement logic.
 Custom Maps: 
The game accepts a map file as a parameter, allowing flexibility in creating and testing different layouts.

## Learning Objectives

This project is designed to promote understanding of fundamental 2D graphics concepts, including texture manipulation, event management, and collision logic. Through the development of this game, skills in graphical programming are enhanced, particularly in the efficient use of low-level libraries like Minilibx.

## Map 

The map can be composed of only these 5 characters:

`0` for an empty space,

`1` for a wall,

`C` for a collectible,

`E` for a map exit,

`P` for the player’s starting position

## Getting Started
First, you need to install some dependencies.

```
sudo apt install libbsd-dev libxext-dev
```

make

```
 ./so_long [MAP_FILE.ber]
```

Only map files with extension `.ber` are available. Map file examples are available in the `maps/` directory.

```bash
 ./so_long so_long/maps/map.ber
```

Run the code to use all the features of the game.
