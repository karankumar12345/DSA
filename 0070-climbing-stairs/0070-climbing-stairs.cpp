class Solution {
public:
    int Recursion(int n) {
        if (n == 0 || n == 1)
            return 1;

        return Recursion(n - 1) + Recursion(n - 2);
    }
    int TopDown(int n, vector<int>& dp) {
        if (n == 0 || n == 1)
            return 1;
        if (dp[n] != -1) {
            return dp[n];
        }
        dp[n] = TopDown(n - 1, dp) + TopDown(n - 2, dp);
        return dp[n];
    }
    int BottomUp(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <n; i++) {
            dp[i]=dp[i-2]+dp[i-1];
        }
        return dp[n-1];
    }

int SpaceOpt(int n){
    int current=1;
    int prev=1;
    for(int i=2;i<=n;i++){
        int temp=current+prev;
        prev=current;
        current=temp;
    }
 return current;
}
    int climbStairs(int n) {
        //  return Recursion(n);
        // vector<int> dp(n + 1, -1);
        // return TopDown(n, dp);

        // return BottomUp(n+1);

        return SpaceOpt(n);
    }
};