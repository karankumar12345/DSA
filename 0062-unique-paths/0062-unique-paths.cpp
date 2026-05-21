class Solution {
public:
    int Recu(int m, int n) {
        if (n < 0 || m < 0) {
            return 0;
        }
        if (n == 0 && m == 0) {
            return 1;
        }
        return Recu(m - 1, n) + Recu(m, n - 1);
    }

    int TopDown(int m, int n, vector<vector<int>>& dp) {
        if (n < 0 || m < 0) {
            return 0;
        }
        if (n == 0 && m == 0) {
            return 1;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }

        dp[m][n]=TopDown(m-1,n,dp)+TopDown(m,n-1,dp);
        return dp[m][n];
    }
    int uniquePaths(int m, int n) {
        // return Recu(m - 1, n - 1);

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return TopDown(m - 1, n - 1, dp);
    }
};