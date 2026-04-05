class Solution {
public:
    bool judgeCircle(string moves) {
        map<char,int>mp;
        int n = moves.length();

        for(auto ch: moves){
            if(ch == 'U'){
                mp[ch]++;
            }
            else if(ch == 'D'){
                mp['U']--;
            }
            else if(ch == 'L'){
                mp[ch]++;
            }
            else{
                mp['L']--;
            }
          
        }

        bool flag = true;

        for(auto it: mp){
            if(it.second > 0 || it.second < 0){
                flag = false;
                break;
            }
        }

        return flag;
    }
};