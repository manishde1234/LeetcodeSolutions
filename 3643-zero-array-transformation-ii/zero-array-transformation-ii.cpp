class Solution {
public:
typedef long long ll;
    bool solve(vector<int>& nums, vector<vector<int>>& queries, int mid, int &result){
        int m = queries.size();
        int n = nums.size();
        vector<int>diff(n+1,0);
        vector<int>prefixSum(n,0);
        
        for(int i = 0; i <= mid; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            diff[l] -= val;
            diff[r+1] += val;
        }

        //calculate the prefixsum
        prefixSum[0] = diff[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1] + diff[i];
        }

        int zeroCount = 0;
        for(int i = 0; i < n; i++){
            if(abs(prefixSum[i]) >= nums[i]){
                zeroCount++;
            }
        }
        if(zeroCount == n){
            result = min(result, mid);
        }
        return zeroCount == n;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        ll sum = accumulate(nums.begin(),nums.end(),0LL);
        if(sum == 0){
            return 0;
        }

        int l = 0, r = m-1;
        int result = INT_MAX;
        while(l <= r){
            int mid = l+(r-l)/2;
            bool flag = solve(nums, queries,mid,result);
            if(flag){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return result == INT_MAX ? -1: result+1;
    }
};