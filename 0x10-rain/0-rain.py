#!/usr/bin/python3
"""
This module contains one function def rain()
"""


def rain(walls):
	"""Calculate the total amount of rainwater retained"""
	drops = 0
	if (walls):
		for i in range(1, len(walls) - 1):
			left_wall = walls[i]
			for j in range(i):
				left_wall = max(left_wall, walls[j])
			right_wall = walls[i]
			for j in range(i + 1, len(walls)):
				right_wall = max(right_wall, walls[j])
			drops += (min(left_wall, right_wall) - walls[i])
		return drops
	return 0
