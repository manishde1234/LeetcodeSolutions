class Solution {
public:

    bool checkBit(int &x, int bit){
        return x &(1 << bit);
    }
    bool setBit(int &x, int bit){
        return x |= (1 << bit);
    }
    bool unsetBit(int &x, int bit){
        return x &= ~(1 << bit);
    }
    int minimizeXor(int num1, int num2) {
        int x = num1;
        int requiredBit = __builtin_popcount(num2);
        int currentBit = __builtin_popcount(num1);
        int bit = 0;//start from least sig bit

        if(requiredBit < currentBit){
            while(requiredBit < currentBit){
                if( checkBit(x,bit)){
                    //bit is not set
                    unsetBit(x,bit);
                    currentBit--;
                }
                
                    
                    bit++;
                
            }
        }
        else if(currentBit < requiredBit){
            while(currentBit < requiredBit){
                if(!checkBit(x,bit)){
                    //unset it 
                    setBit(x,bit);
                    currentBit++;
                }
                bit++;
            }
        }

        return x;
    }
};