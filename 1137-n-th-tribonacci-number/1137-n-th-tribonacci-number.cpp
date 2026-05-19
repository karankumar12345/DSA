class Solution {
public:
    int Recu(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 1;
        }
        return Recu(n - 3) + Recu(n - 2) + Recu(n - 1);
    }
    int TopDown(int n,vector<int>&dp) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]= TopDown(n - 3,dp) + TopDown(n - 2,dp) + TopDown(n - 1,dp);
        return dp[n];
    }
    int tribonacci(int n) {
        //  return Recu(n);

         vector<int>dp(n+1,-1);
         return TopDown(n,dp);
         
          }
};