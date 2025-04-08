class Solution {
public:
    int t[201][20001];
    bool solve(vector<int>& nums, int sum , int idx){
        if(idx >= nums.size()){
            return sum == 0;
        }
          if(sum < 0){
            return false;
        }
        if(sum == 0){
            return true;
        }

        if(t[idx][sum] != -1){
            return t[idx][sum];
        }
        bool take = solve(nums, sum-nums[idx], idx+1);
        bool skip = solve(nums, sum, idx+1);

      

        return t[idx][sum] =(take || skip);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(),0);
        memset(t,-1,sizeof(t));

        if(totalSum % 2 != 0){
            return false;
        }

        return solve(nums,totalSum/2,0);
    }
};