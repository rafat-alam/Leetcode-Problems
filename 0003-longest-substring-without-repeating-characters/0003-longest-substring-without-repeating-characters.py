class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxl = left = 0
        count = {}

        for right, c in enumerate(s):
            count[c] = 1 + count.get(c, 0)
            while count[c] > 1:
                count[s[left]] -= 1
                left += 1
            maxl = max(maxl, right - left + 1)
        
        return maxl