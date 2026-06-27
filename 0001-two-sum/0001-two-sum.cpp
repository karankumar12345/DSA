class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       

       unordered_map<int,int>numIndex;
       for(int i=0;i<nums.size();i++){
        int needValue=target-nums[i];
        if(numIndex.find(needValue)!=numIndex.end()){
            return {numIndex[needValue],i};
        }
        numIndex[nums[i]]=i;
       }
       return {};
    }
};