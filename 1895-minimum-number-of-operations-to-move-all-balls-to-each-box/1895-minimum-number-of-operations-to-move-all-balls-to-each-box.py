class Solution(object):
    def minOperations(self, boxes):
        """
        :type boxes: str
        :rtype: List[int]
        """
        lis = [0] * len(boxes)
        for i in range(0, len(boxes)):
            for j in range(0, len(boxes)):
                if i == j: continue
                if boxes[j] == '1':
                    lis[i] += abs(j - i)
        
        return lis