class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& r, vector<int>& diff) {
        vector<int> a(n, INT_MAX);
        a[0] = 0;
        for(auto &res : r) {
            a[res[0]] = min(a[res[0]], res[1]);
        }

        for(int i = 0; i < diff.size(); i++) {
            a[i + 1] = min(a[i + 1], a[i] + diff[i]);
        }

        for(int i = diff.size() - 1; i >= 0; i--) {
            a[i] = min(a[i], a[i + 1] + diff[i]);
        }

        return *max_element(a.begin(), a.end());
    }
};