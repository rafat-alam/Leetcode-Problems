class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        long long sum = 0;
        map<int, int> mp;
        int ans = nums.size() + 1;

        int left = 0;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;

            if(mp[nums[i]] == 1) {
                sum += nums[i];
            }

            while(sum >= k) {
                ans = min(ans, i - left + 1);

                mp[nums[left]]--;
                if(mp[nums[left]] == 0) {
                    sum -= nums[left];
                }
                left++;
            }
        }

        if(ans == nums.size() + 1) return -1;

        return ans;
    }
};