class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int c = 0, emp = 0;

        function<void (int, int, int)> f = [&](int i, int j, int cnt) -> void {
            if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == -1) return;

            if(grid[i][j] == 2) {
                if(cnt == emp + 1) c++;
                return;
            }

            grid[i][j] = -1;

            f(i + 1, j, cnt + 1);
            f(i - 1, j, cnt + 1);
            f(i, j + 1, cnt + 1);
            f(i, j - 1, cnt + 1);

            grid[i][j] = 0;
        };

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) emp++;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) f(i, j, 0);
            }
        }

        return c;
    }
};