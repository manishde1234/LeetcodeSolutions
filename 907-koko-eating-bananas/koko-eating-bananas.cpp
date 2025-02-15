class Solution {
public:
    bool canEat(int mid, vector<int>& piles, int h, int n){
        int currentHour = 0;
        //count if possible with mid
        for(auto it: piles){
            currentHour += it/mid;
            if(it % mid != 0){
                currentHour++;
            }
        }
        return currentHour <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());

        while(l < r){
            int mid = l +(r-l)/2;
            //check if this is possible
            if(canEat(mid,piles,h,n)){
                //check for lower value
                r = mid;
            }
            else{
                l = mid+1 ;
            }
        }
        return r;
    }
};