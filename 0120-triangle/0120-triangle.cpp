class Solution {
public:
    int Recursion(int i, int j, int n, vector<vector<int>>& triangle) {
        if (i == n - 1) {
            return triangle[i][j];
        }

        int down = Recursion(i + 1, j, n, triangle) + triangle[i][j];
        int diagonal  = Recursion(i+1, j + 1, n, triangle) + triangle[i][j];

        return min(down, diagonal);
    }
    int Memo(int i,int j,int n,vector<vector<int>>&triangle,vector<vector<int>>&dp){
        if(i==n-1)  return triangle[i][j];
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        int down=Memo(i+1,j,n,triangle,dp)+triangle[i][j];
        int diagnol=Memo(i+1,j+1,n,triangle,dp)+triangle[i][j];

        dp[i][j]= min(down,diagnol);
       return dp[i][j];

    }
    int Tabl(int i,int j,int n,vector<vector<int>>&triangle){
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j = 0; j < n; j++) {
        dp[n-1][j] = triangle[n-1][j];
    }

 
    for(int i = n-2; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            int down = dp[i+1][j];
            int diag = dp[i+1][j+1];

            dp[i][j] = triangle[i][j] + min(down, diag);
        }
    }
    return dp[0][0];

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // return Recursion(0, 0, n, triangle);

        // vector<vector<int>>dp(n,vector<int>(n,-1));

        // return Memo(0,0,n,triangle,dp);
      return Tabl(0,0,n,triangle);
    }
};