class Solution(object):
    def countMaxOrSubsets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ma = 0
        ans = 0

        def f(i, val):
            nonlocal ma, ans
            if i == len(nums):
                if val == ma:
                    ans += 1
                elif val > ma:
                    ma = val
                    ans = 1
                return

            f(i + 1, val | nums[i])
            f(i + 1, val)
        
        f(0, 0)
        return ans
        