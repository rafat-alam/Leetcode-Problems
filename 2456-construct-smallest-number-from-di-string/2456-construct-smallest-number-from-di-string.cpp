class Solution {
public:
    string smallestNumber(string p) {
        int n = p.size();
        string ans = string(n + 1, '-');

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] == 'I') {
                ans[i] = (++cnt) + '0';
                int j = i - 1;
                while(j >= 0 && p[j] == 'D') {
                    ans[j] = (++cnt) + '0';
                    j--;
                }
            }
        }

        if (p[n - 1] == 'I') {
            ans[n] = (++cnt) + '0';
        } else {
            ans[n] = (++cnt) + '0';
            int j = n - 1;
            while(j >= 0 && p[j] == 'D') {
                ans[j] = (++cnt) + '0';
                j--;
            }
        }

        return ans;
    }
};