class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            int needValue=target-nums[i];
            if(map.find(needValue)!=map.end()){
              return {map[needValue],i};
            }
          
            map[nums[i]]=i;
        }
        return {};

    }
};