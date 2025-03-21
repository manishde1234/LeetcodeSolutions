class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int mask = 0;
        int i = 0, j = 0;
        int result = 1;
        int sum = 0;

        while(j < n){
            while((mask & nums[j]) != 0){
                mask = (mask ^ nums[i]);//remove from mask
                i++;
            }
            ;
           
                //find window
                result = max(result, j-i+1);
            
            mask = (nums[j] | mask);
            j++;
        }

        return result;
    }
};