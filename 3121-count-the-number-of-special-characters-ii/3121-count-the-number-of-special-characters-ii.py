class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        last_lower = {}
        first_upper = {}
        
        for c in word:
            if c.islower():
                last_lower[c] = word.rindex(c)
            elif c.isupper() and c.lower() not in first_upper:
                first_upper[c.lower()] = word.index(c)
        
        return sum(
            1 for c in last_lower
            if c in first_upper and last_lower[c] < first_upper[c]
        ) 