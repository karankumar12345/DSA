class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || i > 0 && nums[i] != nums[i - 1]) {
                int lo = i + 1, h1 = nums.size() - 1, sum = 0 - nums[i];

                while (lo < h1) {
                    if (nums[lo] + nums[h1] == sum) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[h1]);
                        res.push_back(temp);

                        while(lo<h1 && nums[lo]==nums[lo+1]) 
                        lo++;
                        while(lo<h1 && nums[h1]==nums[h1-1])
                            h1--;
                         
                         lo++,h1--;
                    }
                    else if(nums[lo]+nums[h1]<sum){
                        lo++;
                    }
                    else{
                        h1--;
                    }
                }
            }
        }
        return res;
    }
};