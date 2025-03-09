class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        
        int result = 0;
        vector<int> nums = colors;
        for(int i = 0; i < k-1; i++){
            nums.push_back(colors[i]);
        }
        int n = nums.size();

        int i = 0, j = 1, length = 1;
        while(j < n){
            if(nums[j] == nums[j-1]){
                //not alternating
                i = j;
                length = 1;
                j++;
                continue;
            }
            if(j-i+1 == k){
                result++;
                i++;
            }

            j++;

        }

        return result;
    }
};