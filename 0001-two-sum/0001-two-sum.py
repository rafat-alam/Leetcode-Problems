class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        n = len(nums)

        for i in range(n):
            val = target - nums[i]
            if val in mp:
                return [mp[val], i]
            mp[nums[i]] = i
    
        return []