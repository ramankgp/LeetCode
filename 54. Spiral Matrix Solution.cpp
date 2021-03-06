class Solution {
public:
    // O(mn)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return {};
        
        vector<int> res, dx{0, 1, 0, -1}, dy{1, 0, -1, 0};
        int m = matrix.size(), n = matrix[0].size(), d = 0, x = 0, y = 0;
        for (int k = 0; k < m * n; ++k) {
            res.push_back(matrix[x][y]);
            matrix[x][y] = 0;
            int i = x + dx[d], j = y + dy[d];
            if (i < 0 || i >= m || j < 0 || j >= n || !matrix[i][j]) {
                d = (d + 1) % 4;
                i = x + dx[d];
                j = y + dy[d];
            }
            x = i;
            y = j;
        }
        return res;
    }
};
