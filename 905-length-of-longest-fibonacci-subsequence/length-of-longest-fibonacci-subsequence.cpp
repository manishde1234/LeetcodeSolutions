class Solution {
public:

    int solve(vector<int>& arr ,map<int,int>& mp, int i, int j, vector<vector<int>>& t){
        int target = arr[j] - arr[i];
        if(t[i][j] != -1){
            return t[i][j];
        }
        if(mp.find(target) != mp.end() && mp[target] < i){
            return t[i][j] = solve(arr, mp, mp[target],i,t) + 1;//for this curr element
        }

        return t[i][j] = 2;//for the existing 2 elements
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        map<int,int> mp;
        vector<vector<int>> t(n+1, vector<int>(n+1,-1));

        for(int i = 0; i < n; i++){
            mp[arr[i]] = i;
        }

        int max_length = 0;

        for(int i = 1; i < n; i++){
            for(int j = i+1; j < n; j++){
                int length = solve(arr, mp, i, j,t);
                if(length >= 3){
                    max_length = max(max_length, length);
                }
            }
        }

        return max_length;
    }
};