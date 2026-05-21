class Solution {
public:
    int Recu(int m, int n, vector<vector<int>>& grid) {
        if (m < 0 || n < 0) {
            return 1e9;
        }
        if (n == 0 && m == 0) {
            return grid[0][0];
        }

        int up = grid[m][n] + Recu(m, n - 1, grid);

        int right = grid[m][n] + Recu(m - 1, n, grid);
        return min(up, right);
    }
    int TopDown(int m, int n, vector<vector<int>>& grid,vector<vector<int>>& dp) {
        if (m < 0 || n < 0) {
            return 1e9;
        }
        if (n == 0 && m == 0) {
            return grid[0][0];
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }

        int up = grid[m][n] + TopDown(m, n - 1, grid,dp);

        int right = grid[m][n] + TopDown(m - 1, n, grid,dp);
        dp[m][n]=min(up, right);
        return dp[m][n];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();

        int n = grid[0].size();
        // return Recu(m - 1, n - 1, grid);
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return TopDown(m-1,n-1,grid,dp);
    }
};