#!/usr/bin/python3
"""
This module contains a function to determine if all the boxes can be opened.

Function:
    canUnlockAll(boxes): Determines if all the boxes can be opened.

Args:
    boxes (list of list of int): A list of lists where each sublist represents
    a box and contains keys to other boxes.

Returns:
    bool: True if all boxes can be opened, False otherwise.
"""


def canUnlockAll(boxes):
    """Determines if all the boxes can be opened."""
    n = len(boxes)
    opened = [False] * n
    opened[0] = True
    keys = [0]

    while keys:
        current_key = keys.pop()
        for key in boxes[current_key]:
            if key < n and not opened[key]:
                opened[key] = True
                keys.append(key)

    return all(opened)
