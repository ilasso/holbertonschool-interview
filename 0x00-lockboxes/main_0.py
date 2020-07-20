#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes').canUnlockAll


#boxes = {1,2,3} # false
#print(canUnlockAll(boxes))
#boxes = [1,2,3]
#print(canUnlockAll(boxes))

# debe dar  true
boxes = [[1], [1,2],[1,2,3],[1,2,3,4],[1,2,3,4,5],[1,2,3,4,5,6]]
print(canUnlockAll(boxes))

boxes = [[5], [4],[3],[0],[2],[1]] # debe dar  true
print(canUnlockAll(boxes))

boxes = [[5], [],[],[],[],[0]] # debe dar false
print(canUnlockAll(boxes))

boxes = [[5]] # debe dar TRUE
print(canUnlockAll(boxes))

boxes = [[1],[1]] # debe dar true
print(canUnlockAll(boxes))

boxes = [[],[1]] # debe dar false
print(canUnlockAll(boxes))

boxes = [[1],[]] # debe dar true
print(canUnlockAll(boxes))

boxes = [[2], [3], [1], [5], [4]] # debe  dar false
print(canUnlockAll(boxes))

boxes = [[2],[3,1], [1]] # debe dar true
print(canUnlockAll(boxes))

boxes = [[2,1],[2,1],[]] # true
print(canUnlockAll(boxes))

boxes = [[1,2],[],[2]] # true
print(canUnlockAll(boxes))


boxes = [[2], [3], [1], [5], [], [4]] # true OJO
print(canUnlockAll(boxes))

boxes = [[1],[3],[],[1,2,3,4,5],[],[],[6]] # false
print(canUnlockAll(boxes))

boxes = [[2],[2,1],[]] # false
print(canUnlockAll(boxes))

print("-----")

boxes = [[0],[1],[2]] # false
print(canUnlockAll(boxes))

boxes = [[1], [2], [3], [], [4]] # false
print(canUnlockAll(boxes))

#---boxes = []
#---print(canUnlockAll(boxes))

boxes = [[1,2], [3,4], [5,6], [7,8],[9,0],[],[],[],[0],[2]] # true
print(canUnlockAll(boxes))

boxes = [[1], [1], [1], [1],[1]] # false
print(canUnlockAll(boxes))

boxes = [[1], [2], [3], [4],[0]] # true
print(canUnlockAll(boxes))

boxes = [[1], [2], [3], [4], []] # true
print(canUnlockAll(boxes))

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]] # true
print(canUnlockAll(boxes))

# false
boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))

boxes = [[5], [1,3], [5,1], [2,3], [4,6], [],[4,3,2]] #false
print(canUnlockAll(boxes))
