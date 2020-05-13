#!/usr/bin/python3
'get minimum operations'


def minOperations(n):
    'calculates the fewest number of operations needed'
    if type(n) is not int or n <= 1 or n is None:
        return 0
    div = 2
    counter_oper = 0
    while n >= div:
        if n % div == 0:
            counter_oper += div
            n /= div
        else:
            div += 1
    return counter_oper
