class Solution {
public:
    bool checkZero(vector<int>& nums){
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                return false;
            }
        }
        return true;
    }

    bool checkDiffArray(vector<int>& nums, vector<vector<int>>& queries, int mid){
        int n = nums.size();
        vector<int> diff(n+1,0);

        for(int i = 0; i <= mid; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            diff[l] += val;
            diff[r+1] -= val;
        }

        //cumulative sum
        int cumSum = 0;
        for(int i = 0; i < n; i++){
            diff[i] = cumSum + diff[i];
            cumSum = diff[i];
        }

        //check
        for(int i = 0; i < n; i++){
            if(nums[i] - diff[i] > 0){
                return false;
            }
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        int l = 0, r = m-1;
        int ans = -1;

        bool flag = checkZero(nums);
        if(flag == true){
            return 0;
        }

        while(l <= r){
            int mid = l+(r-l)/2;

            if(checkDiffArray(nums, queries, mid)){
                //check for better ans 
                r = mid -1;
                ans = mid+1;
            }
            else{
                l = mid +1;
            }
        }

        return ans;
    }
};