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
    int TopDown(int n, vector<int>& dp) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 1;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        dp[n] = TopDown(n - 3, dp) + TopDown(n - 2, dp) + TopDown(n - 1, dp);
        return dp[n];
    }
    int BottomUp(int n){
        vector<int>dp(n,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<n;i++){
            dp[i]=dp[i-3]+dp[i-2]+dp[i-1];
        }
        return dp[n-1];
    }
    int SpaceOpt(int n){
          if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 1;
        }
        int next=1;
        int current=1;
        int prev=0;
        for(int i=3;i<=n;i++){
            int temp=next+current+prev;
            int temp1=current;
            current=next;
            prev=temp1;
            next=temp;
        }
        return next;
    }
    int tribonacci(int n) {
        //  return Recu(n);

        // vector<int> dp(n + 1, -1);
        // return TopDown(n, dp);

        // return BottomUp(n+1);
        return SpaceOpt(n);
    }
};