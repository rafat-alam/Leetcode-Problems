from sortedcontainers import SortedList

class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        mp = {}
        ans = []

        for i in range(0, len(A)):
            if A[i] not in mp:
                mp[A[i]] = 0
            mp[A[i]] += 1
            if B[i] not in mp:
                mp[B[i]] = 0
            mp[B[i]] -= 1

            cnt = 0
            for aa, bb in mp.items():
                cnt += abs(bb)
            
            ans.append(int((i + 1) - (cnt / 2)))

        return ans
