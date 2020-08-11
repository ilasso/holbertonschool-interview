#!/usr/bin/python3
"""
minOperations: Function
In a text file, there is a single character H. Your text editor can execute
only two operations in this file: Copy All and Paste. Given a number n,
write a method that calculates the fewest number of operations needed
to result in exactly n H characters

Returns an integer
If n is impossible to achieve, return 0
"""


def minOperations(n):
    """
    minOperations
    calculates the fewest number of operations needed
    to result in exactly n H characters
    """
    if n <= 1:
        return 0
    numberKey = 0
    for value in range(2, n + 1):
        while n % value == 0:
            numberKey = numberKey + value
            n = n / value
    return numberKey
