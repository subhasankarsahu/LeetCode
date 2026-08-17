from typing import List

class Solution:
    def findMaxConsecutiveOnes(self, arr: List[int]) -> int:
        maxi = cnt = 0
        for num in arr:
            cnt = cnt + 1 if num == 1 else 0
            maxi = max(maxi, cnt)
        return maxi