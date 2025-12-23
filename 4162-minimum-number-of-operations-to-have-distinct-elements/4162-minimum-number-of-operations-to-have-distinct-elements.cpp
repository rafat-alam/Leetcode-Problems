class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n, 0), pf(n, 0);

        map<int, int> mp;
        for(int i = n - 1; i >= 0; i--) {
            a[i] = mp[nums[i]];
            mp[nums[i]]++;
            if(i == n - 1) pf[i] = a[i];
            else pf[i] = pf[i + 1] + a[i];
        }

        int cnt = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(pf[i] == 0) cnt++;
        }

        int left = n - cnt;

        return (left + 2) / 3;
    }
};