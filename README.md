# WordHuntSolver
A quick little C++ program to print out all the words in that GamePigeon game word hunt.

# Usage
Run these commands in any unix shell with c++11 and git installed (which should be almost any shell nowadays).
## To download
>  `git clone https://github.com/kpstesla/WordHuntSolver.git`
## To compile:
> `g++ -std=c++11 -o WordHuntSolver *.cpp`
## To run
> `./WordHuntSolver`
>
Then type in the 16 characters in the word hunt box.  It takes a few seconds to load the dictionary, so I reccomend starting the program before you start the game.

# Notes
Right now, only 4x4 grids are supported.  However, with a few tweaks to main.cpp all MxN grids should work.
