class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        bool result = false;
        if(s1 == s2){
            return true;
        }
        int n = s1.length();
        if(n != s2.length()){
            return false;
        }
        int count = 0;
        int firstidx = 0, secondidx = 0;
        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]){
                count++;

                if(count > 2){
                    return false;
                }

                if(count == 1){
                    firstidx = i;
                }
                if(count == 2){
                    secondidx = i;
                }
            }
        }
        if(count == 1){
            return false;
        }
        return s1[firstidx] == s2[secondidx] && s2[firstidx] == s1[secondidx];
    }
};