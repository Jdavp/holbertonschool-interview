#!/usr/bin/python3
'Rain'


def rain(walls: list) -> int:
    'Return Integer indicating total amount of rainwater retained'
    if (len(walls) > 2):
        return sum(walls[1:-1])
    return 0
