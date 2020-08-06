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
    lista = []
    numberKey = 0
    for value in range(2, n):
        if ((n % value) == 0):
            minOper = 2 + ((n / value) - 2) + 1 + (value - 1)
            lista.append(int(minOper))
    if lista:
        return (min(lista))
    return 0
