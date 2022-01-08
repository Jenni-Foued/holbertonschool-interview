#!/usr/bin/python3
"""Module to solve the N Queens problem"""
import sys


def safe(board, position_x, position_y):
    """
    This function checks if a position is safe
    """
    for x in range(len(board)):
        for y in range(len(board[0])):
            # Horizontal check
            if (board[x][position_y] == 1):
                return(0)
            # Vertical check
            if (board[position_x][y] == 1):
                return(0)
            # Diagonal check
            try:
                if (board[position_x + x][position_y + x] == 1):
                    return(0)
            except IndexError:
                pass
            try:
                if (position_x - x >= 0):
                    if (board[position_x - x][position_y + x] == 1):
                        return(0)
            except IndexError:
                pass
            try:
                if (position_x - x >= 0 and position_y - x >= 0):
                    if (board[position_x - x][position_y - x] == 1):
                        return(0)
            except IndexError:
                pass
            try:
                if (position_y - x >= 0):
                    if (board[position_x + x][position_y - x] == 1):
                        return(0)
            except IndexError:
                pass
    return(1)


def put_coords(board, result):
    """
    This function adds a pair of coords to result
    """
    for i in range(0, len(board)):
        for j in range(0, len(board[0])):
            if (board[i][j] == 1):
                result[i][0] = i
                result[i][1] = j
    return result


def solveNQueens(board, columns, n):
    """
    This function checks for every queen
    if there's a queen atacking if not print
    the n queens position
    """
    if (columns == n):
        result = [[0 for x in range(2)] for y in range(n)]
        print(put_coords(board, result))
        return

    for row in range(n):
        if (safe(board, row, columns) == 1):
            board[row][columns] = 1
            solveNQueens(board, columns + 1, n)
            board[row][columns] = 0


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        exit(1)

    n = sys.argv[1]

    try:
        n = int(n)
    except ValueError:
        print('N must be a number')
        exit(1)

    if n < 4:
        print('N must be at least 4')
        exit(1)

    board = [[0 for i in range(n)]for j in range()]
    solveNQueens(board, 0, n)
