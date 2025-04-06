class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>& subsets
        ,vector<int>& currSubset,int i){
        if(i == nums.size()){
            subsets.push_back(currSubset);
            return;
        }
        currSubset.push_back(nums[i]);
        solve(nums,subsets,currSubset,i+1);
        //not take
        currSubset.pop_back();
        solve(nums,subsets,currSubset,i+1);

     
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>>subsets;
        vector<int>currSubset;

        solve(nums,subsets,currSubset,0);//make the subsets

        int result = 0;
        for(auto& subset:subsets){
            int XOR = 0;
            for(auto& num:subset){
                XOR = XOR ^ num;
            }
            result += XOR;
        }
        return result;
    }
};