#!/usr/bin/python3
"""0-lockboxes.py: determines if all the boxes can be opened"""


def canUnlockAll(boxes):
    """ determines if all the boxes can be opened
        return: true if all boxes can be opened
                false otherwise
    """
    # validate if boxes is a list
    if type(boxes) is not list:
        return False

    # if arent there boxes
    if not len(boxes) or boxes == [] or boxes == [[]]:
        return False

    # if only have initial box
    if boxes == [[0]]:
        return True

    dictboxes = {0: 'open'}
    dictboxes2 = {}
    noKey = False
    # iteration all boxes
    for i in boxes:
        if i == [0] or i == []:
            noKey = True
            break
        # add open box for each position
        for j in i:
            # verify if box is was or could be open
            # if there any key, add how an open box in a dictboxes

            # if box number is doesnt exist
            if j > (len(boxes) - 1):
                break

            # if box doesnt have any key
            if boxes[j] == []:
                noKey = True
                break

            # if the box has its own key
            if boxes[j] == [j]:
                break

            # register available keys
            if j not in dictboxes:
                dictboxes[j] = 'open'

        # checks if each box opened have keys to open more boxes
        for k, l in dictboxes.items():
            for m in boxes[k]:
                if m not in dictboxes:
                    dictboxes2[m] = 'open'

        # insert box apened into dictboxes
        for n, o in dictboxes2.items():
            if n not in dictboxes and (n <= (len(boxes) - 1)):
                dictboxes[n] = o

        # check if its not posible to open all boxes
        if (len(boxes) != len(dictboxes)) and noKey:
            return False

    # if its posible to open all boxes
    if (len(boxes) == len(dictboxes)):
        return True
    return False
