class Solution {
public:

int Recu(int n){
    if(n==0||n==1){
        return n;
    }
    return Recu(n-1)+Recu(n-2);
}

int TopDown(int n,vector<int>&dp){
   if(n==0||n==1){
    return n;
   }
   if(dp[n]!=-1){
    return dp[n];
   }
   return TopDown(n-1,dp)+TopDown(n-2,dp);
}

    int fib(int n) {
        // return Recu(n);

        vector<int>dp(n+1,-1);
        return TopDown(n,dp);
    }
};