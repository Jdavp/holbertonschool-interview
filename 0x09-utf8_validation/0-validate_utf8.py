#!/usr/bin/python3
'UTF-8 Validation'
import itertools as it


def to_bits(bytes):
    'Changing a number to a list of bits'
    NUMBER_OF_BITS_PER_BLOCK = 8
    for byte in bytes:
        num = []
        exp = 1 << NUMBER_OF_BITS_PER_BLOCK
        while exp:
            exp >>= 1
            num.append(bool(byte & exp))
        yield num


def validUTF8(data):
    'determines if a given data set represents a valid UTF-8 encoding'
    """
    :type data: List[int]
    :rtype: bool
    """
    if len(data) == 0:
        return False

    MAX_NUMBER_OF_ONES = 4

    bits = to_bits(data)
    for byte in bits:
        # single byte char
        if byte[0] == 0:
            continue

        # multi-byte character
        amount = sum(it.takewhile(bool, byte))
        if amount <= 1:
            return False
        if amount >= MAX_NUMBER_OF_ONES:
            return False

        for _ in range(amount - 1):
            try:
                byte = next(bits)
            except StopIteration:
                return False
            if byte[0:2] != [1, 0]:
                return False
    return True
