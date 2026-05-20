class Solution {
public:
    int Recu(vector<int>& freq, int i) {
        if (i < 0)
            return 0;
        if (i == 0)
            return i * freq[i];

        int take = (i * freq[i]) + Recu(freq, i - 2);
        int skip = Recu(freq, i - 1);
        return max(take, skip);
    }

    int TopDown(vector<int>& freq, int i, vector<int>& dp) {
        if (i < 0)
            return 0;
        if (i == 0)
            return i * freq[i];
        if (dp[i] != -1) {
            return dp[i];
        }
        int take = (i * freq[i]) + TopDown(freq, i - 2, dp);
        int skip = TopDown(freq, i - 1, dp);
        dp[i] = max(take, skip);
        return dp[i];
    }

  int BottomUp(vector<int>& freq, int maxVal) {

        vector<int> dp(maxVal + 1, 0);

        dp[0] = 0;
        dp[1] = freq[1] * 1;

        for(int i = 2; i <= maxVal; i++) {

            int take = (i * freq[i]) + dp[i - 2];
            int skip = dp[i - 1];

            dp[i] = max(take, skip);
        }

        return dp[maxVal];
    }

   
    int Space(vector<int>& freq, int maxVal) {

        int prev2 = 0;
        int prev1 = freq[1] * 1;

        for(int i = 2; i <= maxVal; i++) {

            int take = (i * freq[i]) + prev2;
            int skip = prev1;

            int curr = max(take, skip);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int deleteAndEarn(vector<int>& nums) {

        int max_value = *max_element(nums.begin(), nums.end());

        vector<int> freq(max_value + 1, 0);

        for (int x : nums) {
            freq[x]++;
        }

        // return Recu(freq, max_value);

        // vector<int> dp(max_value + 1, -1);

        // return TopDown(freq, max_value, dp);

        // return BottomUp(freq, max_value);

        return Space(freq,max_value);
    }
};