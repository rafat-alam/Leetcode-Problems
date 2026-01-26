class Solution {
public:
    int numDecodings(string s) {

        vector<int> dp(s.size(), -1);
        
        function<int(int)> f = [&] (int i) -> int {
            if(i == s.size()) return 1;
            if(s[i] == '0') return 0;

            if(dp[i] != -1) return dp[i];

            int ans = f(i + 1);
            if(i < s.size() - 1) {
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if(num <= 26) {
                    ans += f(i + 2);
                }
            }

            return dp[i] = ans;
        };

        return f(0);
    }
};