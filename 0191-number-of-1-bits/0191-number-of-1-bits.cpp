class Solution {
public:
    int hammingWeight(int n) {
        long long int  count = 0;
        while (n > 1) {
            int result = n / 2;
            int reminder = n % 2;
            if (reminder == 1) {
               count=count+1;
            }
            n=result;
        }
        if(n==1){
            count++;
        }
        return count;
    }
};