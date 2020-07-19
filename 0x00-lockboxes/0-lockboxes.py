#!/usr/bin/python3
"""0-lockboxes.py: determines if all the boxes can be opened"""

def canUnlockAll(boxes):
    """ determines if all the boxes can be opened"""
    if len(boxes) == 0:
        return False
    if type(boxes) is not list:
        return False
    if boxes == [[0]]:
        return True
    if boxes == []:
        return False
    if boxes == [[]]:
        return False
    # if boxes is not coherent
    maxim = max([item for lista in boxes for item in lista])
    if maxim != len(boxes) - 1:
        return False

    if [0] not in boxes:
        dictboxes = {0: 'open'}
    else:
        dictboxes = {}
    dictboxes2 = {}
    if boxes[0] == [0]:
        return False
    # iteration all boxes
    for i in boxes:
        count = 0  # open boxes
        # add open box for each position
        for j in i:
            # verify if box is was or could be open
            # if there any key, add how an open box in a dictboxes
            # and incremente counter of opened boxes
            if j not in dictboxes:
                dictboxes[j] = 'open'
                count = count + 1
                # if dont have to add a opened box return false
                #if count == 0:
                #    return False
        # checks if each box opened have keys to open more boxes
        for k, l in dictboxes.items():
            for m in boxes[k]:
                if m not in dictboxes:
                    dictboxes2[m] = 'open'
                    count = count + 1
        # insert box apened into dictboxes
        for n, o in dictboxes2.items():
            if n not in dictboxes:
                dictboxes[n] = o
                count = count + 1
        # if all boxes are opened return true
        if (len(boxes) == len(dictboxes)):
            return True
    return False
