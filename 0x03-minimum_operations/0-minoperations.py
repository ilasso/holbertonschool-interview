#!/usr/bin/python3
"""
"""
def minOperations(n):
    lista = []
    numberKey = 0
    for value in range(2, n):
        if ((n % value) == 0):
            minOper = 2 + ((n / value) - 2) + 1 + (value - 1)
            print(value)
            print(minOper)
            lista.append(int(minOper))
    return (min(lista))
    #if numberKey == n:
    #    return 0
    #minOper = 2 + ((n / numberKey) - 2) + 1 + (numberKey - 1)
    #return minOper
