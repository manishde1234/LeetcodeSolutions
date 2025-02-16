class Solution {
public:
    bool checkSum(string s, int n, int sum,int idx){
        if(sum > n){
            return false;
        }
        if(idx == s.length()){
            return n == sum;
        }

         bool possible = false;
        for(int j = idx; j < s.length(); j++){
            string sub = s.substr(idx, j-idx+1);
            int val = stoi(sub);

           

            possible = possible || checkSum(s,n,sum+val , j+1);
            if(possible == true){
                return true;
            }
        }
        return possible;
    }
    int punishmentNumber(int n) {
        int punish = 0;
        for(int i = 1; i <= n; i++){
            int sqr = i*i;
            string s = to_string(sqr);
            if(checkSum(s,i,0,0)){
                punish += sqr;
            }
        }

        return punish;
    }
};