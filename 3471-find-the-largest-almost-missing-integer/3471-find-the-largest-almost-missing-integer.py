from collections import Counter

class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        n = len(nums)
        freq = Counter(nums)

        if k == 1:
            ans = -1
            for num, count in freq.items():
                if count == 1:
                    ans = max(ans, num)
            return ans

        if k == n:
            return max(nums)

        candidates = []
        if freq[nums[0]] == 1:
            candidates.append(nums[0])

        if freq[nums[-1]] == 1:
            candidates.append(nums[-1])

        return max(candidates) if candidates else -1