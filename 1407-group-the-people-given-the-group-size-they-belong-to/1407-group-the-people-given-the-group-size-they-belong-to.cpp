class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        map<int, vector<int>> mp;
        vector<vector<int>> ans;
        for(int i = 0; i < g.size(); i++) {
            mp[g[i]].push_back(i);
            if(mp[g[i]].size() == g[i]) {
                vector<int> temp;
                int c = g[i];
                while(c--) {
                    temp.push_back(mp[g[i]].back());
                    mp[g[i]].pop_back();
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};