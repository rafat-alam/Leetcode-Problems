class Solution:
    def validStrings(self, n: int) -> List[str]:
        lis = []

        def f(s: str):
            nonlocal lis
            if len(s) >= n:
                lis.append(s)
                return
            if s and s[-1] == '0':
                f(s + '1')
            else:
                f(s + '0')
                f(s + '1')
        
        f("")
        return lis
