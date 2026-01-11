class Solution {
public:
    bool e(set<int>& st, int i, int j) {
        auto it = st.lower_bound(i);
        return (it != st.end() && *it <= j);
    }
    int centeredSubarrays(vector<int>& nums) {
        map<int, set<int>> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].insert(i);
        }

        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i; j < nums.size(); j++) {
                int sum = 0;
                for(int k = i; k <= j; k++) {
                    sum += nums[k];
                }

                if(e(mp[sum], i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};