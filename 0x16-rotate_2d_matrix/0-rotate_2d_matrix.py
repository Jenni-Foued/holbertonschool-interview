#!/usr/bin/python3
"""
Rotate 2D Matrix
"""
def rotate_2d_matrix(matrix):
    """
    This function rotates a 2d matrix
    90° degrees clockwise.
    """
    n = len(matrix[0])
    for i in range(0, n):
        for j in range(0, i):
            temp = matrix[i][j]
            matrix[i][j] = matrix[j][i]
            matrix[j][i] = temp

    for i in range(0, n):
        for j in range(0, n / 2):
            temp = matrix[i][j]
            matrix[i][j] = matrix[i][n - j - 1]
            matrix[i][n - j - 1] = temp
