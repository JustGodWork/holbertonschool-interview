#!/usr/bin/python3

"""
Module that solves the N Queens problem using backtracking.
"""

import sys


def is_safe(board, row, col):
    """
    Check if placing a queen at (row, col) is safe.
    """

    for r, c in board:
        if c == col or r + c == row + col or r - c == row - col:
            return False

    return True


def solve_nqueens(N, board=None, row=0):
    """Backtracking solution for N Queens."""

    if board is None:
        board = []

    if row == N:
        print([[r, c] for r, c in board])
        return

    for col in range(N):
        if is_safe(board, row, col):
            solve_nqueens(N, board + [[row, col]], row + 1)


def main():
    """
    Parse command-line arguments and solve the N Queens problem.
    """

    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    solve_nqueens(N)


if __name__ == "__main__":
    main()
