class Solution {
public:
    int Recu(vector<int>& nums, int n) {
        if (n < 0)
            return -1;
        if (n == 0)
            return nums[0];

        int incl = Recu(nums, n - 2) + nums[n];
        int excl = Recu(nums, n - 1) + 0;
        int ans = max(incl, excl);
        return ans;
    }

    int Memo(vector<int>&nums,int n,vector<int>&dp){
        if(n<0) return -1;
        if(n==0) return nums[0];
        if(dp[n]!=-1){
            return  dp[n];
        }
        int incl=Memo(nums,n-2,dp) + nums[n];
        int excl=Memo(nums,n-1,dp)+0;
        dp[n]=max(incl,excl);
        return dp[n];

    }
    int solve2(vector<int>& nums, int n) {
              vector<int>dp(n+1,0);
    dp[0]=nums[0];
    for(int i=1;i<=n;i++){
             int incl = nums[i] + (i >= 2 ? dp[i - 2] : 0);
        int excl=dp[i-1]+0;
        dp[i]=max(incl,excl);
    }
    return dp[n];
    }


    int SpaceOpt(vector<int>&nums,int n){
              int   prev2=0;
  int  prev1=nums[0];
       for(int i=1;i<=n;i++){
        int incl=prev2+nums[i];
        int excl=prev1+0;
        int ans=max(incl,excl);
        prev2=prev1;
        prev1=ans;
       
    }
    return prev1;
    }
    int rob(vector<int>& nums) {

        int n = nums.size();
        // return Recu(nums, n - 1);
        // vector<int>dp(n,-1);
        // return Memo(nums,n-1,dp);


    //  int ans=solve2(nums,n-1);
    //     return ans;

    return  SpaceOpt(nums,n-1);

    }
};