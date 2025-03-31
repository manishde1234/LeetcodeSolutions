class Solution {
    typedef long long ll;
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        int m = n-1;

        ll minSum = 0, maxSum = 0;
        vector<ll>pairSum(n-1,0);

        for(int i = 0; i < m; i++){
            pairSum[i] = weights[i]+weights[i+1];
        }
        //sort
        sort(pairSum.begin(),pairSum.end());

        for(int i = 0; i < k-1; i++){
            minSum += pairSum[i];
            maxSum += pairSum[m-i-1];
        }

        return maxSum - minSum;

    }
};