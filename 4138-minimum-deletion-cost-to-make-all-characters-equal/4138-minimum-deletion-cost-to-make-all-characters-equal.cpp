class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long t = accumulate(cost.begin(), cost.end(), 0LL);

        map<char, long long> mp;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]] += cost[i];
        }

        long long ma = 1e18;
        for(auto &[aa, bb] : mp) {
            ma = min(ma, t - bb);
        }

        return ma;
    }
};