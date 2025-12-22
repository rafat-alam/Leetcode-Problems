class Solution(object):
    def minOperations(self, boxes):
        """
        :type boxes: str
        :rtype: List[int]
        """
        n = len(boxes)
        lis = [0] * len(boxes)
        pf = [0] * (n + 1)
        pfe = [0] * (n + 1)
        suf = [0] * (n + 1)
        sufe = [0] * (n + 1)

        for i in range(0, n):
            if boxes[i] == '1':
                pf[i + 1] = pf[i] + pfe[i] + 1
                pfe[i + 1] = pfe[i] + 1
            else:
                pf[i + 1] = pf[i] + pfe[i]
                pfe[i + 1] = pfe[i]

        for i in range(n - 1, -1, -1):
            if boxes[i] == '1':
                suf[i] = suf[i + 1] + sufe[i + 1] + 1
                sufe[i] = sufe[i + 1] + 1
            else:
                suf[i] = suf[i + 1] + sufe[i + 1]
                sufe[i] = sufe[i + 1]

        for i in range(0, n):
            lis[i] = pf[i] + suf[i + 1]

        return lis