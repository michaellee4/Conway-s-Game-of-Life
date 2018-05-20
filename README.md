# Conway-s-Game-of-Life
C++ implementation of the classic game of life

Rules are as follows
Any live cell with fewer than two live neighbours dies, as if caused by under-population.

Any live cell with two or three live neighbours lives on to the next generation.

Any live cell with more than three live neighbours dies, as if by overcrowding.

Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

Input is taken via txt file specifying 
Board dimension
number of iterations
whether to use the 1d or 2d array implementation
initial board layout
