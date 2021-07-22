#!/usr/bin/python3
"""This module contains one function: canUnlockAll()"""

def canUnlockAll(boxes):
    """Determines if all the boxes can be opened"""
    keysList = []
    nextBox = 1
    for box in boxes:
        [keysList.append(key) for key in box]
        print(keysList)
        if nextBox in keysList:
            nextBox += 1
        elif nextBox == len(boxes):
            return True
        else:
            return False
