class Solution {
public:
    bool rotateString(string s, string goal) {
        set<string>st;
        int n = s.size();
        st.insert(s);
        for(int i = 0; i < n; i++){
            char temp = s[n-1];
            s.pop_back();
            s = temp + s;
            st.insert(s);
            
        }
        if(st.find(goal) == st.end()){
            return false;
        }
        else{
            return true;
        }
    }
};