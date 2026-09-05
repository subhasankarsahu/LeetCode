class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = [[1]]
        for i in range(1, numRows):
            row = [1]
            for j in range(1, i):
                row.append(res[-1][j-1] + res[-1][j])

            row.append(1)
            res.append(row)
        return res