class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
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