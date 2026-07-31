class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            long long int count = 0;
            int number = i;
            while (number > 1) {
                if (number % 2 == 1) {
                    count = count + 1;
                }
                number = number / 2;
            }
            if (number == 1) {
                count++;
            }
            ans.push_back(count);
            count = 0;
        }
        return ans;
    }
};