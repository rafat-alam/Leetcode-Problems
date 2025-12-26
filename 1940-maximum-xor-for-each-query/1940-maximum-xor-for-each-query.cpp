class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> pf(n, nums[0]);
        for(int i = 1; i < n; i++) {
            pf[i] = pf[i - 1] ^ nums[i];
        }

        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            ans[i] = ((1 << m) - 1) ^ pf[i];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};