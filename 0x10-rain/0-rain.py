#!/usr/bin/python3
"""
0-rain:This method includes function rain
"""


def rain(walls):
    """
    function rain:
    calculates the amount of water trapped. The only argument
    passed is the walls, in form of a list.
    """

    water = 0  # keeps track of the total water as we traverse the walls map

    n = len(walls)  # number of points on the map

    #  lists to store the left_max and right_max of each point in the map

    left_max = [0] * n
    right_max = [0] * n

    #  default values
    left_max[0] = walls[0]
    right_max[n - 1] = walls[n - 1]

    #  filling the left_max list
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    #  filling the right_max list
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    #  calculating the amount of water
    for i in range(n):
        water += min(left_max[i], right_max[i]) - walls[i]

    return water
