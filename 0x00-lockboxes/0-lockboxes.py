#!/usr/bin/python3
"Lockboxes"


def canUnlockAll(boxes):
    "determines if all the boxes can be opened"
    all_boxes = []
    print(len(boxes))
    for i in range(len(boxes)):
        if i not in boxes[i]:
            if len(boxes[i]) == 0:
                all_boxes.append([0])
            else:
                all_boxes.append(boxes[i])
    set_of_boxes = set([item for box in all_boxes for item in box])
    print(len(set_of_boxes))
    print(len(boxes))
    if len(set_of_boxes) == len(boxes):
        return True
    else:
        return False
