class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> ro(m, 0), co(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ro[i]++;
                    co[j]++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int rz = n - ro[i];
                int cz = m - co[j];
                grid[i][j] = ro[i] + co[j] - rz - cz;
            }
        }

        return grid;
    }
};
