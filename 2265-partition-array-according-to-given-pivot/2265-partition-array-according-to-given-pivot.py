class Solution(object):
    def pivotArray(self, nums, pivot):
        """
        :type nums: List[int]
        :type pivot: int
        :rtype: List[int]
        """
        n = len(nums)
        lis = []

        for i in nums:
            if i < pivot:
                lis.append(i)
        
        for i in nums:
            if i == pivot:
                lis.append(i)

        for i in nums:
            if i > pivot:
                lis.append(i)

        return lis
        