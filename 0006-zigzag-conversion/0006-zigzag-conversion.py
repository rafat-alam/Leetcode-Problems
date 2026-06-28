class Solution:
    def convert(self, s: str, num: int) -> str:
        if num == 1:
            return s

        f = ["" for _ in range(num)]

        for i in range(len(s)):
            rem = i % (2 * num - 2)
            if rem < num:
                f[rem] += s[i]
            else:
                f[2 * num - rem - 2] += s[i]

        return "".join(f)