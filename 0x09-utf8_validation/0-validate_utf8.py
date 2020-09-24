#!/usr/bin/python3


def validUTF8(data):
    cnt = 0
    for x in data:
        x = bin(x)[2:].zfill(8)
        if cnt:
            if x.startswith("10"):
                cnt -= 1
            else:
                return False
        else:
            cnt = x.find("0")
            if cnt == -1 or cnt == 1 or cnt > 4:
                return False
            if cnt:
                cnt -= 1
    return cnt == 0
