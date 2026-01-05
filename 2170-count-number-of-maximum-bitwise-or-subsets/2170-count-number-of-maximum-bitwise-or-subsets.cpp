class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int ma = 0;
        int c = 0;
        function<void (int, int)> f = [&] (int i, int val) -> void {
            if(i == nums.size()) {
                if(val > ma) {
                    ma = val;
                    c = 1;
                } else if(val == ma) {
                    c++;
                }
                return;
            }
            f(i + 1, val);
            f(i + 1, nums[i] | val);
        };

        f(0, 0);

        return c;
    }
};