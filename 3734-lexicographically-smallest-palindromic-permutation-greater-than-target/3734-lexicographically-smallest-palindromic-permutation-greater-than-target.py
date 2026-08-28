from collections import Counter

class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        counts = Counter(s)
        odd_count = sum(1 for v in counts.values() if v % 2 != 0)

        if odd_count > 1:
            return ""

        mid_char = ""

        for c, v in counts.items():
            if v % 2 != 0:
                mid_char = c

        half_counts = {c: v // 2 for c, v in counts.items()}
        L = len(s) // 2

        for i in range(L, -1, -1):
            pref_counts = Counter(target[:i])

            possible = all(half_counts.get(c, 0) >= v for c, v in pref_counts.items())

            if not possible:
                continue

            rem_counts = {c: half_counts.get(c, 0) - pref_counts.get(c, 0) for c in half_counts}

            if i == L:
                P = target[:L]
                pal = P + mid_char + P[::-1]
                if pal > target:
                    return pal

            else:
                best_c = None
                for c in sorted(rem_counts.keys()):
                    if rem_counts[c] > 0 and c > target[i]:
                        best_c = c
                        break
                
                if best_c:
                    rem_counts[best_c] -= 1
                    P = target[:i] + best_c
                    
                    for c in sorted(rem_counts.keys()):
                        P += c * rem_counts[c]
                        
                    return P + mid_char + P[::-1]
                    
        return ""
