class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& r, vector<int>& c) {
        vector<vector<int>> ans(r.size(), vector<int> (c.size(), 0));
        int j = 0;
        for(int i = 0; i < r.size(); i++) {
            int num = r[i];
            while(num > 0) {
                int mi = min(c[j], num);
                if(mi < c[j]) {
                    c[j] -= mi;
                    ans[i][j] += mi;
                } else {
                    ans[i][j] += mi;
                    j++;
                }
                num -= mi;
            }
        }
        return ans;
    }
};