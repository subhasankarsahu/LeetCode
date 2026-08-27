class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        from collections import Counter

        counts = Counter(s)
        n = len(s)

        max_match = 0
        for i in range(n):
            if counts[target[i]] > 0:
                counts[target[i]] -= 1
                max_match += 1

            else:
                break

        start_i = min(n-1, max_match)

        counts = Counter(s)

        for j in range(start_i):
            counts[target[j]] -= 1

        for i in range(start_i, -1, -1):
            best_char = None
            for char_code in range(ord(target[i])+1, ord('z') + 1):
                c = chr(char_code)

                if counts[c] > 0:
                    best_char = c
                    break

            if best_char:
                prefix = target[:i]
                counts[best_char] -= 1

                suffix = []
                for char_code in range(ord('a'), ord('z') + 1):
                    c = chr(char_code)
                    if counts[c] > 0:
                        suffix.append(c * counts[c])

                return prefix + best_char + "".join(suffix)

            if i > 0:
                counts[target[i-1]] += 1

        return ""