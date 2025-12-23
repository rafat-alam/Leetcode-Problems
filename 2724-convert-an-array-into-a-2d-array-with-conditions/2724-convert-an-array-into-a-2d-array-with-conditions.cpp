class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> mp;
        for(auto &aa : nums) mp[aa]++;

        vector<vector<int>> v;
        for(auto &[aa, bb] : mp) {
            for(int i = 0; i < bb; i++) {
                if(v.size() <= i) v.push_back({});
                v[i].push_back(aa);
            }
        }

        return v;
    }
};