# Update 2023
This is an old assignment written in C++ back when I was still an undergrad. 

Kinda cute to look at it, but it has no bearing on my current coding capability. This is more like a gentle memory from the past.

# GoldMine
Hello and welcome to GoldMine - the Quest Game! 

It's a small game that's easy to lose and winning has no sense of accomplishment. You simply pick and choose random spaces on a board and if you find the right one, you win, and if you find the wrong one, you lose. It's essentially minesweeper but it doesn't tell you where the other mines are.

It's an exercise in templates. Like MineSweeper, you need to know whether the tile is uncovered or not (bool), what the underlying character is (char), and in this case the amount of points you lose if it's a ' _ ' character (int). With three different types all corresponding to the same grid, we implement a template to store the different values in one easy way. 

There is a makefile to compile using gcc and it's written in c++

Having said that all, please enjoy!
