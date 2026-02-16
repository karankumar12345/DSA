class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>numsIndex;
        for(int i=0;i<nums.size();i++){

            int needValue=target-nums[i];
            if(numsIndex.find(needValue)!=numsIndex.end()){
                return {numsIndex[needValue],i};
            }
            numsIndex[nums[i]]=i;
        }
        return {};

    }
};