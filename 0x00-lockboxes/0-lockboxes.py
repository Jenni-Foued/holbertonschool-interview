#!/usr/bin/python3
"""This module contains one function: canUnlockAll()"""


def canUnlockAll(boxes):
    """Determines if all the boxes can be opened"""
    keysList = [0]
    for key in keysList:
        for k in boxes[key]:
            if k not in keysList and k < len(boxes):
                keysList.append(k)
    for i in range(len(boxes)):
        if i not in keysList:
            return False
    return True
