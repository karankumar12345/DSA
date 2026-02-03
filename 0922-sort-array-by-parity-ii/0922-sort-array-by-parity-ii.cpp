class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        //iska logic simple check karu index agar uska element odd raha tu even index me swap kar dega are same opposite 

        // In This Question we can simply have a check if even index have a odd numebr then  swap to even number 

        int n=nums.size();
        int evenindex=0;
        int oddindex=1;
        while(evenindex<n && oddindex<n){
            if(nums[evenindex]%2==0){
                evenindex +=2;
            }
            else if(nums[oddindex]%2!=0){
                oddindex+=2;
            }
            else{
                swap(nums[evenindex],nums[oddindex]);
                oddindex+=2;
                evenindex+=2;
                
            }
        }
        return nums;
    }
};