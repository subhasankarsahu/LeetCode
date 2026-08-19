import collections
from typing import List

class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        reserved = collections.defaultdict(int)

        for row, seat in reservedSeats:
            reserved[row] |= (1 << seat)

        max_families = (n - len(reserved)) * 2

        for bitmask in reserved.values():
            left_free = (bitmask & 60) == 0
            right_free = (bitmask & 960) == 0
            middle_free = (bitmask & 240) == 0

            if left_free and right_free:
                max_families += 2
            elif left_free or right_free or middle_free:
                max_families += 1

        return max_families