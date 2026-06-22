class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxSum=0;
        int buy=prices[0];
        for(int i=0;i<prices.size();i++){
            if(buy>prices[i]){
               buy=prices[i];
            }
            else{
                maxSum=max(maxSum,prices[i]-buy);
            }
        }
        return maxSum;
    }
};