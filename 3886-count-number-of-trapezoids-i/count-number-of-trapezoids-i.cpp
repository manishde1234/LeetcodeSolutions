class Solution {
public:
    typedef long long ll;
    int countTrapezoids(vector<vector<int>>& points) {
        ll result = 0;
        int M = 1e9+7;
        unordered_map<ll,ll> mp;
        for(auto it: points){
            ll y = it[1];
            mp[y]++;
        }

        ll prevlines = 0;

        for(auto it: mp){
            ll count = it.second;
            ll horizontallines = count *(count-1)/2; //combination
            ll totallines = horizontallines * prevlines;
            result =(result + totallines) % M ;
            prevlines += horizontallines;
        }

        return result;
    }
};