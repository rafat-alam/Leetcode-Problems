class Solution:
    def groupThePeople(self, g: List[int]) -> List[List[int]]:
        mp = {}
        for i in range(0, len(g)):
            if g[i] not in mp:
                mp[g[i]] = []
            mp[g[i]].append(i)
        
        lis = []
        for aa, bb in mp.items():
            temp = []
            for i in bb:
                temp.append(i)
                if len(temp) == aa:
                    lis.append(temp)
                    temp = []
        
        return lis
