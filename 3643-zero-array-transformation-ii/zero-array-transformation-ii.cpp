class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        auto check = [&](int mid){
            vector<int> diff(n + 1, 0);
            for(int i = 0; i <= mid; ++i){
                vector<int> q = queries[i];
                // cout << q[0] << " " << q[1] << " " << q[2] << " |";
                diff[q[0]] -= q[2];
                diff[q[1] + 1] += q[2]; 
            }
            for(int i = 1; i < n; ++i) diff[i] += diff[i - 1];

            int zeroCount = 0;

            for(int i = 0; i < n; ++i){
                if(abs(diff[i]) >= nums[i]) zeroCount++;
            }
            return zeroCount == nums.size();

        };
        long long int sum = accumulate(nums.begin(), nums.end(), 0LL);
        if(sum == 0){
            return 0;
        }
        int l = 0, r = m - 1;
        int ans = INT_MAX;
        while(l <= r){
            int mid = l + (r - l)/2;

            if(check(mid)){
                // cout << mid << " ";
                ans = min(ans, mid);
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans == INT_MAX ? -1 : ans + 1;
    }
};