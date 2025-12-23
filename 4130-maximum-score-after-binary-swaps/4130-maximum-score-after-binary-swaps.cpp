class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        multiset<int, greater<int>> st;
        int n = nums.size();

        long long sum = 0;
        for(int i = 0; i < n; i++) {
            st.insert(nums[i]);
            if(s[i] == '1') {
                int ma = *st.begin();
                st.erase(st.find(ma));
                sum += (long long) ma;
            }
        }

        return sum;
    }
};