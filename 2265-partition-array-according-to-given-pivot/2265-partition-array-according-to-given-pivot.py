class Solution(object):
    def pivotArray(self, nums, pivot):
        """
        :type nums: List[int]
        :type pivot: int
        :rtype: List[int]
        """
        less, more = [], []
        eq = 0

        for i in nums:
            if i < pivot:
                less.append(i)
            elif i == pivot:
                eq += 1
            else:
                more.append(i)

        return less + [pivot] * eq + more
        