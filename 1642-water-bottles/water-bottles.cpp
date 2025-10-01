class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = 0;
        while(numBottles >= numExchange){
            numBottles += 1;
            numBottles -= numExchange;
            count += numExchange;
        }
        return count + numBottles;
    }
};