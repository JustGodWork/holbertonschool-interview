#!/usr/bin/python3
"""
    This module contains a function to calculate
    the minimum number of operations
    needed to achieve exactly n 'H' characters in
    a text file, starting with a
    single 'H' and using only copy
    all and paste operations.
    Function:
        minOperations(n): Returns the minimum number
        of operations needed to
        achieve exactly n 'H' characters.
    Parameters:
        n (int): The target number of 'H' characters.
    Returns:
        int: The minimum number of operations
        needed to achieve exactly n 'H'
        characters. Returns 0 if n is less than or equal to 1.
"""


def minOperations(n: int) -> int:
    """
    Returns the minimum number of operations needed to achieve exactly n 'H'
    """
    if n <= 1:
        return 0

    operations = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1

    return operations
