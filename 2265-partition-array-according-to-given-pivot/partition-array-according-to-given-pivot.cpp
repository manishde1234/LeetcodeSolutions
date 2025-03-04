class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>result(n);

        int less = 0, equal = 0, more = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == pivot){
                equal++;
            }
            else if(nums[i] < pivot){
                less++;
            }
            else{
                more++;
            }
        }      

        int i = 0, j = less, k = less + equal;

        for(int m = 0; m < n; m++){
            if(nums[m] < pivot){
                result[i] = nums[m];
                i++;
            }
            else if(nums[m] == pivot){
                result[j] = nums[m];
                j++;
            }
            else{
                result[k] = nums[m];
                k++;
            }
        }

        return result;
    }
};