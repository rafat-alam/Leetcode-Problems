class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        lst = []
        for i in bank:
            c = i.count('1')
            if c:
                lst.append(c)

        c = 0
        for i in range(1, len(lst)):
            c += lst[i - 1] * lst[i]
        
        return c