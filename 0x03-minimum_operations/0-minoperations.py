#!/usr/bin/python3
"""
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
    #if numberKey == n:
    #    return 0
    #minOper = 2 + ((n / numberKey) - 2) + 1 + (numberKey - 1)
    #return minOper
