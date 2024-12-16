#!/usr/bin/python3
"""
This module contains a function to calculate the perimeter of an island.

Function:
    island_perimeter(grid): Returns the perimeter of the
    island described in grid.

Args:
    grid (list of list of int): A list of lists where each sublist represents
    a row in the grid. 0 represents water and 1 represents land.

Returns:
    int: The perimeter of the island.
"""


def island_perimeter(grid):
    """Returns the perimeter of the island described in grid."""
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

    return perimeter
