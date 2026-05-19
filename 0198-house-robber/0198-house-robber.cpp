class Solution {
public:
    int Recu(vector<int>& nums, int n) {
        if (n < 0) {
            return -1;
        }
        if (n == 0) {
            return nums[0];
        }
        int incl = Recu(nums, n - 2) + nums[n];
        int excl = Recu(nums, n - 1) + 0;
        return max(incl, excl);
    }
    int TopDown(vector<int>&nums,int n, vector<int>&dp){
          if (n == 1) {
            return max(nums[0],nums[1]);
        }
        if (n == 0) {
            return nums[0];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int incl=TopDown(nums,n-2,dp)+nums[n];
        int excl=TopDown(nums,n-1,dp);
        return max(incl,excl);
    }

    int BottomUp(vector<int>&nums,int n){
        vector<int>dp(n+1,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
            int incl=BottomUp(nums,n-2)+nums[i];
            int excl=BottomUp(nums,n-1)+0;
            dp[i]=max(incl,excl);
        }
        return dp[n];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // prev2 = dp[i-2], prev1 = dp[i-1]
        int prev2 = 0;
        int prev1 = nums[0];

        for (int i = 1; i < n; i++) {

            int incl = nums[i] + prev2; // take current
            int excl = prev1;           // skip current

            int curr = max(incl, excl);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

};