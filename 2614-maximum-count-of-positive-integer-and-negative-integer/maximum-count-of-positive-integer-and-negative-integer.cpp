class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int firstPositive = lower_bound(nums.begin(),nums.end(),1) - nums.begin();
        int firstNegative = lower_bound(nums.begin(),nums.end(),0) - nums.begin();
        int result = max(n- firstPositive, firstNegative);
        return result;
    }
};