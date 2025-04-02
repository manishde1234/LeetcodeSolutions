class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    long long ans = ((nums[i]-nums[j])*(long long)nums[k]);
                    result =  max<long long>(result, ans);
                }
            }
        }

        return result;
    }
};