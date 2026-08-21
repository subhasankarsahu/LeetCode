import math

class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        n = len(coins)
        lcm_list = []
        
        for i in range(1, 1 << n):
            current_lcm = 1
            count = 0

            for j in range(n):
                if (i >> j) & 1:
                    current_lcm = math.lcm(current_lcm, coins[j])
                    count += 1

            lcm_list.append((current_lcm, count))

        def count_amounts(x: int) -> int:
            res = 0
            for lcm_val, count in lcm_list:
                if count % 2 == 1:
                    res += x // lcm_val
                else:
                    res -= x // lcm_val
            return res

        low = 1
        high = min(coins) * k
        ans = high

        while low <= high:
            mid = (low + high) // 2

            if count_amounts(mid) >= k:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        
        return ans