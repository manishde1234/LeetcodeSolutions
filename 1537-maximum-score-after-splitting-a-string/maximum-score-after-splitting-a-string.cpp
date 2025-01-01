/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int>zeroes(n,0);
        vector<int>ones(n,0);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                zeroes[i] = count+1;
                count++;
            }
            else{
                zeroes[i] = count;
            }
        }
            count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                ones[i] = count+1;
                count++;
            }
            else{
                ones[i] = count;
            }
        }
        for(int i = 0; i < n; i++){
            cout << zeroes[i] << " ";
        }
        cout << endl;
        for(auto it: ones){
            cout << it << " ";
        }
        cout << endl;
        int maxCount = 0;
        for(int i = 0; i < n-1; i++){
            count = zeroes[i] + ones[n-1] - ones[i];
            maxCount = max(maxCount,count);
        }
        return maxCount;
        
    }
};


