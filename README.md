# Minefield

This is a c-language project developed for academic skills and fun. Mainly in Brazilian portuguese language.


## Prerequisites

For this code, you will need a C language compiler.

## Compiling and running

For running it you need to compile the library and the main source code file of project using the below command:
```
$ gcc main.c -o minefield
```

This will create a new executable in the project root path named minefield (or minefield.exe on windows). Now you only need to run it:

For Linux/MAC users:

```
./minefield 
```

For Windows users, just double click on executable program.

## Exercise objectives

Create a board minefield with next rules:
- Board size is 10x10
- Player has 5 lives
- Possible values are 0 to 3
- Should be informed row and column for the play
- Accumulate player points
- Can not hit row and column twice
- If hits zero, loses 1 live

## How to play
Consider using a terminal size of 83x28 for a better experience. This is game consists in typing row, and a column, to get some random number on matriz. 

## Rules
* Finding 0 you loses 1 life
* Other numbers count some points
* If you get no lives the game is ended.

## Authors
* **Nicolas Anelli** - [Github](https://github.com/NicolasAnelli).

### Considerations:
Feel free for forking this project, and submiting any improvement.

