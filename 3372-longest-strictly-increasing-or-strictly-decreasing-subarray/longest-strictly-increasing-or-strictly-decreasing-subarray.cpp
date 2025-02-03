class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incr = 1;
        int decr = 1;
        int result = 1;

        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                incr = incr +1;
                decr = 1;
                
            }
            else if(nums[i] < nums[i-1]){
                decr = decr+1;
                incr = 1;
            }
            else{
                decr = 1;
                incr = 1;
            }
            result = max({result,incr,decr});
        }
        return result;
    }
};