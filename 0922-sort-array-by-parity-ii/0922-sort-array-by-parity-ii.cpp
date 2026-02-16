class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {

        // iska logic simple check karu index agar uska element odd raha tu even
        // index me swap kar dega are same opposite

  
        int n = nums.size();
        int evenIndex = 0;
        int oddIndex = 1;
        while (evenIndex < n && oddIndex < n) {
            if (nums[evenIndex] % 2 == 0) {
                evenIndex += 2;
            } else if (nums[oddIndex] % 2 != 0) {
                oddIndex += 2;
            } else {
                swap(nums[oddIndex],nums[evenIndex]);
                 oddIndex += 2;
                evenIndex += 2;
            }
        }
        return nums;
    }
};