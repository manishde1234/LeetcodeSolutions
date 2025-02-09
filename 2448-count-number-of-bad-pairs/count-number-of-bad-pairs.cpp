class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<long long, long long> mp;
      long long n = nums.size();
      for(int i=0; i<n; i++) {
        mp[nums[i] - i]++;
      }
      long long sum = 0;
      for(auto &[a,b]:mp) {
        sum += (b * (b-1)/2); 
      }
      return (n * (n-1)/2) - sum; 
    }
};