class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find pivot
        int reverse1 = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                reverse1 = i;
                break;
            }
        }

        // Step 2: If no pivot, reverse whole array
        if (reverse1 == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find rightmost greater element
        int index = n - 1;
        for (int i = n - 1; i > reverse1; i--) {
            if (nums[i] > nums[reverse1]) {
                index = i;
                break;
            }
        }

        // Step 4: Swap
        swap(nums[reverse1], nums[index]);

        // Step 5: Reverse suffix
        reverse(nums.begin() + reverse1 + 1, nums.end());
    }
};