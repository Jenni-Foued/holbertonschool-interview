#!/usr/bin/python3
"""Module to solve the N Queens problem"""
import sys


def print_sol(board):
    global k
    k = k + 1
    S = []
    for i in range(n):
        for j in range(n):
            if board[i][j] == 1:
                S.append([i, j])
    print(S)


def isSafe(board, row, col):
    for i in range(col):
        if (board[row][i]):
            return False
    i = row
    j = col
    while i >= 0 and j >= 0:
        if(board[i][j]):
            return False
        i -= 1
        j -= 1
    i = row
    j = col
    while j >= 0 and i < n:
        if(board[i][j]):
            return False
        i = i + 1
        j = j - 1
    return True


def solving(board, col):
    if (col == n):
        print_sol(board)
        return True
    res = False
    for i in range(n):
        if (isSafe(board, i, col)):
            board[i][col] = 1
            res = solving(board, col + 1) or res
            board[i][col] = 0
    return res


def solveNQueens():
    board = [[0 for j in range(n)]for i in range(n)]
    if (solving(board, 0) is False):
        print("Solution does not exist")
        return
    return

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

    k = 1
    solveNQueens()
