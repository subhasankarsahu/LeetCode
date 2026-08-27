class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        left = 0
        ones = 0
        best = ""
        
        for right in range(len(s)):
            if s[right] == '1':
                ones += 1
            
            while ones == k:
                sub = s[left:right+1]
                
                if best == "" or len(sub) < len(best) or (len(sub) == len(best) and sub < best):
                    best = sub
                
                if s[left] == '1':
                    ones -= 1
                left += 1
                
        return best