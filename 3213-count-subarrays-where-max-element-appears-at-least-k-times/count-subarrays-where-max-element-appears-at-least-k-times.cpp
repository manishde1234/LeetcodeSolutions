class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxelement = *max_element(nums.begin(),nums.end());

        int n = nums.size();
        int i = 0;
        int j = 0;

        long long result = 0;
        int count = 0;
        while(j < n){
            if(nums[j] == maxelement){
                count++;
            }
            while(count >= k){
                  result += n-j;
                if(nums[i] == maxelement){
                    count--;
                  

                }
                i++;
                
            }
            j++;
        }
        return result;
    }
};