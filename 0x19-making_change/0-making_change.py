#!/usr/bin/python3
"""
This module contains one function makechange()
"""


def makeChange(coins, total):
    """
    Given a pile of coins of different values,
    determine the fewest number of coins needed to meet a given amount total.
    """
    nbOfCoinsUsed = 0
    coins.sort(reverse=True)
    while total > 0:
        for coin in coins:
            nbOfCoinsUsed += total // coin
            total = total % coin
            if total == 0:
                break
        if total > 0:
            return -1
    return nbOfCoinsUsed
