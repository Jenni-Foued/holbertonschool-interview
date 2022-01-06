#!/usr/bin/python3
"""
Rotate 2D Matrix
"""
def rotate_2d_matrix(matrix):
    """
    This function rotates a 2d matrix
    90° degrees clockwise.
    """
    index = 0
    while index < len(matrix[0]):
        for j in range(index, len(matrix[0])):
            aux = matrix[index][j]
            matrix[index][j] = matrix[j][index]
            matrix[j][index] = aux
        index += 1
    for j in range(len(matrix[0])):
        matrix[j].reverse()
