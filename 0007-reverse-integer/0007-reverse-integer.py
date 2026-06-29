class Solution:
    def reverse(self, x: int) -> int:
        is_neg = False

        if x < 0:
            if x == -2 ** 31:
                return 0
            is_neg = True
            x = -x
        
        num = 0

        while x > 0:
            if num > ((2 ** 31 - 1) - (x % 10)) / 10:
                return 0
            num *= 10
            num += x % 10
            x //= 10
        
        if is_neg:
            return -num
        return num