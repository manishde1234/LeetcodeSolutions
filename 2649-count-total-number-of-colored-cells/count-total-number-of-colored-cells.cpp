class Solution {
public:
    long long coloredCells(int n) {
        long long cells = 1;
        // while(n > 1){
        //     cells += n*(n-1)/2;
        //     n--;
        // }
        return 1+ 4*((long long)n*(n-1))/2;
    }
};