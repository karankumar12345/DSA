class Solution {
public:


int Recu(int m,int n,vector<vector<int>>& obstacleGrid){
   
    if(m<0||n<0){
        return 0;
    }
    if(n==0&&m==0){
        return 1;
    }
     if(obstacleGrid[m][n]==1){
        return 0;
    }
   return Recu(m-1,n,obstacleGrid)+Recu(m,n-1,obstacleGrid);

}
int TopDown(int m,int n,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
   
    if(m<0||n<0){
        return 0;
    }
     if(obstacleGrid[m][n]==1){
        return 0;
    }
    if(n==0&&m==0){
        return 1;
    }

     if(obstacleGrid[m][n]==1){
        return 0;
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
 dp[m][n]=TopDown(m-1,n,obstacleGrid,dp)+TopDown(m,n-1,obstacleGrid,dp);
 return dp[m][n];

}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        // return Recu(m-1,n-1,obstacleGrid);
vector<vector<int>>dp(m,vector<int>(n,-1));
        return TopDown(m-1,n-1,obstacleGrid,dp);
    }
};