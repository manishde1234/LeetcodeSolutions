class Solution {
public:
    bool isPossible(vector<int>& nums, int n, int mid,int k){
        int house = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] <= mid){ //take house
                house++;
                i++;//skip house
            }
        }

        return house >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *min_element(nums.begin(),nums.end());
        int r = *max_element(nums.begin(),nums.end());

        int result = INT_MAX;
        while(l <= r){
            int mid = l +(r-l)/2;
            if(isPossible(nums,n,mid,k)){
                r = mid-1;
                result = min(result, mid);
            }
            else{
                l = mid +1;
            }
        }

        return result;
    }
};