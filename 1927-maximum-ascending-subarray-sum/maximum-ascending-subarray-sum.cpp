class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        int sum = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                sum += nums[i];
            }
            else{
               result = max(result,sum);
               sum = nums[i];
            }         
            
        }

        return max(result,sum);
    }
};