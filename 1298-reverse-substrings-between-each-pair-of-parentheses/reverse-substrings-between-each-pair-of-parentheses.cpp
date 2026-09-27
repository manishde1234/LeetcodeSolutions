class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int>resLen;
        string res ="";

        for(auto &it: s){
            if(it == '('){
                resLen.push(res.length());//keep it for reversal
            }
            else if(it == ')'){
                int l = resLen.top();
                resLen.pop();
                reverse(res.begin()+l, res.end());
            }
            else{
                res.push_back(it);
            }
        }

        return res;
    }
};