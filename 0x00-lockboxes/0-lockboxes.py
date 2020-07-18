#!/usr/bin/python3
def canUnlockAll(boxes):
    dictboxes = {0: 'open'}
    dictboxes2 = {}

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
                if count == 0:
                    return False
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
        # if doesnt have more boxes to open return false
        if count == 0:
            return False
        # if all boxes are opened return true
        if (len(boxes) == len(dictboxes)) and count:
            return True
    print(dictboxes)
    return False
