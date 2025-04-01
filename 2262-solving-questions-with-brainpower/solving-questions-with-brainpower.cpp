class Solution {
public:
    typedef long long ll;
    ll solve(vector<vector<int>>& questions, vector<ll>&t, int n, int idx){
        if(idx >= n){
            return 0;

        }
        if(t[idx] != -1){
            return t[idx];
        }

        ll take = questions[idx][0] + solve(questions,t,n, idx +1 +questions[idx][1]);
        ll skip = solve(questions,t, n, idx+1);

        return t[idx] = max(take,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll>t(n+1,-1);

        return solve(questions,t,n,0);
    }
};