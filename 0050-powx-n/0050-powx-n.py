class Solution:
    def myPow(self, x: float, n: int) -> float:
        power = n

        if power < 0:
            x = 1 / x
            power = -power

        ans = 1

        while power > 0:
            if power % 2 == 1:
                ans *= x

            x *= x
            power //= 2

        return ans
        