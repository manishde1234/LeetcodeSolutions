class Solution {
public:
    bool isPrefixAndSuffix(string &pat,string &txt){
        if(pat.length() > txt.length()){
            return false;
        }
        int m = pat.length();
        string prefix = txt.substr(0,m);
        int idx = txt.length() - m;
        string suffix = txt.substr(idx,m);

        if(suffix == pat && prefix == pat){
            return true;
        }
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int result = 0;
        for(int i = 0; i < n; i++){
            string word1 = words[i];
            for(int j = i+1; j < n; j++){
                if(j >= n){
                    break;
                }
                string word2 = words[j];
                if(isPrefixAndSuffix(word1,word2)){
                    result++;
                }
            }
        }
        return result;
    }
};