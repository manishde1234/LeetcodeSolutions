class Solution {
public:
    int digitSum(int num){
        int ans = 0;
        
        while(num != 0){
            ans += num % 10;
            num = num/10;
        }

        return ans;
    }
    int maximumSum(vector<int>& nums) {
        int result = -1;
        int n = nums.size();
        map<int,int>mp;

        for(int i = 0; i < n; i++){
            int digit = digitSum(nums[i]);
            if(mp.find(digit) != mp.end()){
                result = max(result, nums[i] + mp[digit]);
            }

            //update map
            mp[digit] = max(mp[digit],nums[i]);
        }
        return result;
    }
};