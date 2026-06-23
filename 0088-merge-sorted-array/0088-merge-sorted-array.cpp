class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int N=m-1;
        int M=n-1;
        int K=m+n-1;


        while(N>=0 && M>=0){
            if(nums1[N]>nums2[M]){
                nums1[K]=nums1[N];
                N--;
            }
            else{
                nums1[K]=nums2[M];
                M--;
            }
            K--;
        }

        while(M>=0){
            nums1[K]=nums2[M];
            M--;
            K--;
        }

    }
};