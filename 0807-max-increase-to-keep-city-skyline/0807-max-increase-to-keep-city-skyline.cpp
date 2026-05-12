class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> h(n), v(n);

        for(int i = 0; i < n; i++) {
            int ma = grid[i][0];
            for(int j = 1; j < n; j++) {
                ma = max(ma, grid[i][j]);
            }
            h[i] = ma;
        }

        for(int i = 0; i < n; i++) {
            int ma = grid[0][i];
            for(int j = 1; j < n; j++) {
                ma = max(ma, grid[j][i]);
            }
            v[i] = ma;
        }

        int c = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                c += min(h[i], v[j]) - grid[i][j];
            }
        }

        return c;
    }
};