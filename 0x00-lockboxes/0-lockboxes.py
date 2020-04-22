#!/usr/bin/python3
"Lockboxes"


def canUnlockAll(boxes):
    "determines if all the boxes can be opened"
    all_keys = [0]
    for box in range(len(boxes)):
        for keys in range(len(boxes[box])):
            if boxes[box][keys] != box and boxes[box][keys] <= len(boxes):
                all_keys.append(boxes[box][keys])
    set_of_keys = set(all_keys)
    if len(set_of_keys) == len(boxes):
        return True
    else:
        return False
