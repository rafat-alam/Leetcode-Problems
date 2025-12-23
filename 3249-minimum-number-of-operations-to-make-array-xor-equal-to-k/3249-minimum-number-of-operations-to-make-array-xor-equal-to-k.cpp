class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xo = k;
        for(auto &num : nums) {
            xo ^= num;
        }
        return __builtin_popcount(xo);
    }
};