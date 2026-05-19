class Solution {
public:
    int Recu(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        return Recu(n - 1) + Recu(n - 2);
    }

    int TopDown(int n, vector<int>& dp) {
        if (n == 0 || n == 1) {
            return n;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return TopDown(n - 1, dp) + TopDown(n - 2, dp);
    }
    int BottomUp(int n) {
        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n - 1];
    }

int SpaceOpt(int n){
     if(n==1) return 1;
    if(n==0) return 0;
    int current=1;
    int prev=0;
    for(int i=2;i<=n;i++){
        int temp=prev+current;
        prev=current;
        current=temp;
    }
    return current;
}
    int fib(int n) {
        // return Recu(n);

        // vector<int>dp(n+1,-1);
        // return TopDown(n,dp);

        // return BottomUp(n + 1);
        return SpaceOpt(n);
    }
};