# QMUL-ChessGame
This is a console based two player chess game.

## How to compile
First make sure you are in the root folder of this game. To compile the code
just run the following command. It deletes eventually excisting old compiled code and compile the project.   
```bash
make clean && make
```
*Note: Make sure you have the latest gcc compiler version installed to compile
the code*

## How to run
To start the game, simply execute the following command in your teriminal at the
project root folder.
```bash
./build/main
```

## How to play
To play the game, you will be asked to enter a figures origin and target. To select
a figure just type in its coordinates. For example to make an initial move type in:
>Please select a figure: E2
>
>Please select a target: E4

*Note: The input is case insensitive*

If you type in a invalid input, you will be asked to retype in your move.
The game accepts only valid move corresponding to the standard chess rules.
After a succesfull move the current board will be printed. Now the other player
can type in it's move.

There are a bunch of extra commands to type in at the **beginning** of your move:   
Undo a move:
>:u

Save the game to a file:
>:s

Load a previous saved game:
>:l

Quit the game:
>:q

*Note: It is only possible to save one savegame. The file location is at the rootfolder: SaveFile.txt. If you want to protect your savegame from overriding, move it to another location*

## Documentation
This project is documented using doxygen. The documentation can be found [here](https://incrediblehannes.github.io/QMUL-ChessGame/html/index.html)
