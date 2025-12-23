class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> mp, ans;
        for(int i = m; i > 0; i--) {
            mp.push_back(i);
        }

        for(auto &aa : queries) {
            int idx = -1;
            for(int i = 0; i < mp.size(); i++) {
                if(mp[i] == aa) idx = i;
            }
            mp.push_back(mp[idx]);
            mp.erase(mp.begin() + idx, mp.begin() + idx + 1);
            ans.push_back(m - 1 - idx);
        }

        return ans;
    }
};