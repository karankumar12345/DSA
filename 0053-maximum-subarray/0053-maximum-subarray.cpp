class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int Sum=INT_MIN;
        int maxsum=0;
        for(int i=0;i<nums.size();i++){
            maxsum+=nums[i];
            Sum=max(Sum,maxsum);
            if(maxsum<0){
                maxsum=0;
            }
        }
        return Sum;
    }
};