class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        vector<long long> pf(nums.size(), nums[0]), pf2(nums.size() + 1, 2e18);
        for(int i = 1; i < nums.size(); i++) {
            pf[i] = pf[i - 1] + nums[i];
        }
        for(int i = nums.size() - 1; i >= 0; i--) {
            pf2[i] = min(pf2[i + 1], (long long) nums[i]);
        }

        long long ma = -2e18;
        for(int i = 0; i < nums.size() - 1; i++) {
            ma = max(ma, pf[i] - pf2[i + 1]);
        }
        return ma;
    }
};