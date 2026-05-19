class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        set<int>st;
        for(int i = 0; i < n; i++){
            st.insert(nums1[i]);
        }      
        int m = nums2.size();
        int minelement = INT_MAX;
        for(int i = 0; i < m; i++){
            if(st.find(nums2[i]) != st.end()){
                if(minelement >= nums2[i]){
                    minelement = nums2[i];
                }
            }
        }

        return minelement == INT_MAX? -1: minelement;
    }
};