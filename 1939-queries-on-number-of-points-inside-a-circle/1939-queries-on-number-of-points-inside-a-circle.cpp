class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& p, vector<vector<int>>& q) {
        vector<int> ans;
        for(auto &aa: q) {
            int cnt = 0;
            for(auto &bb : p) {
                int dis = (bb[0] - aa[0]) * (bb[0] - aa[0]) + (bb[1] - aa[1]) * (bb[1] - aa[1]);
                if(dis <= aa[2] * aa[2]) cnt++;
            }
            ans.push_back(cnt);
        }

        return ans;
    }
};