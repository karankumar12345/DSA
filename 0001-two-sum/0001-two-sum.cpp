class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int>numIndexMap;
        for(int i=0;i<nums.size();i++){
            int needValue=target-nums[i];
            if(numIndexMap.find(needValue)!=numIndexMap.end()){
                return {numIndexMap[needValue],i};
            }
           numIndexMap[nums[i]]=i;
        }
        return {};
    }
};