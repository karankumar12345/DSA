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
        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        dp[m][n] = TopDown(m - 1, n, dp) + TopDown(m, n - 1, dp);
        return dp[m][n];
    }
   int BottomUp(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (i == 0 && j == 0) continue;

            int up = 0;
            int left = 0;

            if (i > 0)
                up = dp[i - 1][j];

            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }

    return dp[m - 1][n - 1];
}
    int uniquePaths(int m, int n) {
        // return Recu(m - 1, n - 1);

        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return TopDown(m - 1, n - 1, dp);

        return BottomUp(m, n);
    }
};