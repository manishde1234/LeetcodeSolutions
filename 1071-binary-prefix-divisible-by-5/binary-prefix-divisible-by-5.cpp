class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool>result(n);

        int remainder = 0;
        for(int i = 0; i < n; i++){
            remainder = ((remainder*2)+nums[i])%5;
            result[i] = (remainder == 0);
        }

        return result;

    }
};