#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))

    walls = [1, 2, 1, 3, 1, 2, 1, 4, 1, 0, 0, 2, 1, 4]
    print(rain(walls))
