class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;

        vector<int> a;
        function<void(int)> f = [&] (int i) -> void {
            if(i >= nums.size()) {
                ans.push_back(a);
                return;
            }

            a.push_back(nums[i]);
            f(i + 1);
            a.pop_back();
            f(i + 1);
        };

        f(0);

        return ans;
    }
};