class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        for(int i = n - 1; i >= 0; i--) {
            vector<int> a;
            for(int j = 0; ; j++) {
                if(i + j < n && j < m) {
                    a.push_back(grid[i + j][j]);
                } else {
                    break;
                }
            }
            sort(a.rbegin(), a.rend());
            for(int j = 0; ; j++) {
                if(i + j < n && j < m) {
                    grid[i + j][j] = a[j];
                } else {
                    break;
                }
            }
        }

        for(int i = 1; i < m; i++) {
            vector<int> a;
            for(int j = 0; ; j++) {
                if(j < m && i + j < n) {
                    a.push_back(grid[j][i + j]);
                } else {
                    break;
                }
            }
            sort(a.begin(), a.end());
            for(int j = 0; ; j++) {
                if(j < m && i + j < n) {
                    grid[j][i + j] = a[j];
                } else {
                    break;
                }
            }
        }

        return grid;
    }
};