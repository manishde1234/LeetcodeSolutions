class Solution {
public:
    typedef long long ll;

    bool possible( vector<int>& batteries,int n,ll  midpoint){
        ll totalsum = n*midpoint;
        ll sum = 0;

        for(int i = 0; i < batteries.size(); i++){
            sum += min((ll)batteries[i],midpoint);
            if( sum >= totalsum){
                return true;
            }
        } 
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll result = 0;

        //binary search on the ans
        ll l = *min_element(batteries.begin(),batteries.end());
        ll totalsum = accumulate(batteries.begin(),batteries.end(),0LL);

        ll r = totalsum/n;

        //l <= r cause we need to check the midpoint too
        while(l <= r){
            ll midpoint = l +(r-l)/2;
            if(possible(batteries,n,midpoint) == true){
                //find better ans
                result = midpoint;
                l = midpoint+1;
            }
            else{
                r = midpoint-1;
            }
        }
        return result;
    }
};