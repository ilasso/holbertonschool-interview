#!/usr/bin/python3
"""0-lockboxes.py: determines if all the boxes can be opened"""


def canUnlockAll(boxes):
    """ determines if all the boxes can be opened"""
    if boxes == [[0]]:
        return True
    if boxes == []:
        return False
    if boxes == [[]]:
        return False
    # if boxes is not coherent
    maxim = max([item for lista in boxes for item in lista])
    print(max(boxes)[0])
    print(maxim)
    print(len(boxes) - 1)
    if maxim != len(boxes) - 1:
        return False
    if [0] not in boxes:
        dictboxes = {0: 'open'}
    else:
        dictboxes = {}
    dictboxes2 = {}

    # iteration all boxes
    for i in boxes:
        if i == [0]:
            return False
        count = 0  # open boxes
        # add open box for each position
        for j in i:
            # verify if box is was or could be open
            # if there any key, add how an open box in a dictboxes
            # and incremente counter of opened boxes
            if j not in dictboxes:
                dictboxes[j] = 'open'
                count = count + 1
        # checks if each box opened have keys to open more boxes
        for k, l in dictboxes.items():
            for m in boxes[k]:
                if m not in dictboxes:
                    dictboxes2[m] = 'open'
        # insert box apened into dictboxes
        for n, o in dictboxes2.items():
            if n not in dictboxes:
                dictboxes[n] = o
                count = count + 1
        if (len(boxes) == len(dictboxes)) and count:
            return True
    return False
