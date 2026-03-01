class Solution {
public:
    int minPartitions(string n) {
        int counter = 0;

        while(true){
            bool change = false;

            
                for(char &ch : n){
                    if(ch != '0'){
                        ch--; // -1 
                        change = true;

                    }
                }
            

            if(change == false){
                break;
            }
            counter++;
        }

        return counter;
    }
};