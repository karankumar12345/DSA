class Solution {
public:
    int Recu(vector<int>& cost, int n) {
        if (n == 0) {
            return cost[0];
        }
        if (n == 1) {
            return cost[1];
        }

        return cost[n] + min(Recu(cost, n - 1), Recu(cost, n - 2));
    }
    int TopDown(vector<int>&cost,int n,vector<int>&dp){
         if (n == 0) {
            return cost[0];
        }
        if (n == 1) {
            return cost[1];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
       dp[n]=cost[n]+min(TopDown(cost,n-1,dp),TopDown(cost,n-2,dp));
       return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // return min(Recu(cost, n - 1), Recu(cost, n - 2));
        vector<int>dp(n+1,-1);
        return min(TopDown(cost,n-1,dp),TopDown(cost,n-2,dp));
    }
};