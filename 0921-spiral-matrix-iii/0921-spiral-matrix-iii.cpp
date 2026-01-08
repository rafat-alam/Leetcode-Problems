class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int i = rStart, j = cStart;
        int step = 1;

        vector<vector<int>> ans;
        ans.push_back({i, j});

        for (int t = 1; ans.size() < rows * cols; t++) {
            // right
            for (int jj = j + 1; jj <= j + step; jj++) {
                if (i >= 0 && i < rows && jj >= 0 && jj < cols) {
                    ans.push_back({i, jj});
                }
            }
            j += step;

            // down
            for (int ii = i + 1; ii <= i + step; ii++) {
                if (ii >= 0 && ii < rows && j >= 0 && j < cols) {
                    ans.push_back({ii, j});
                }
            }
            i += step;
            step++;

            // left
            for (int jj = j - 1; jj >= j - step; jj--) {
                if (i >= 0 && i < rows && jj >= 0 && jj < cols) {
                    ans.push_back({i, jj});
                }
            }
            j -= step;

            // up
            for (int ii = i - 1; ii >= i - step; ii--) {
                if (ii >= 0 && ii < rows && j >= 0 && j < cols) {
                    ans.push_back({ii, j});
                }
            }
            i -= step;
            step++;
        }

        return ans;
    }
};
