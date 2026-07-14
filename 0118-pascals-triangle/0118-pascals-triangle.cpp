class Solution {
public:

vector<int>GenerateRow(int &num){
    long long ans=1;
    vector<int>ans1;
    ans1.push_back(ans);
    for(int i=1;i<num;i++){
        ans=ans* (num-i);
        ans=ans/i;
        ans1.push_back(ans);
    }
    return ans1;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(GenerateRow(i));
        }
        return ans;
    }
};