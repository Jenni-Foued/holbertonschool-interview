#!/usr/bin/python3
"""Module to solve the N Queens Problem"""
import sys

def drawBoard(n, board):
    """
    This method draws a board:
    F means free spot
    D means danger spot
    """
    for i in range(n):
        for j in range(n):
            if i == j:
                board[i, j] = 'D'
            else:
                board[i,j] = 'F'


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        exit(1)

    n = sys.argv[1]

    try:
        n = int(n)
    except:
        print('N must be a number')
        exit(1)

    if n < 4:
        print('N must be at least 4')
        exit(1)
