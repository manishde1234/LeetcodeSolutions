class Solution {
public:
    typedef long long ll;
    typedef pair<ll,int> P;
    int M = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        //create adjacency list
        unordered_map<int,vector<P>> adj(n);

        for(auto &road : roads){
            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<ll>result(n,LLONG_MAX);
        vector<int>count(n,0);

        result[0] = 0;
        count[0] = 1;

        priority_queue<P, vector<P>, greater<P>>pq;
        pq.push({0,0});//dist , node

        while(!pq.empty()){
            int node = pq.top().second;
            ll dist = pq.top().first;
            pq.pop();

            for(auto &vec: adj[node]){
                int adjnode = vec.first;
                ll wt = vec.second;

                if(dist + wt < result[adjnode]){
                    result[adjnode] = dist + wt;
                    pq.push({dist+wt, adjnode});
                    count[adjnode] = count[node];//count of the prev node
                }

                else if(dist + wt == result[adjnode]){
                    count[adjnode] = (count[adjnode] + count[node]) % M;
                }
            }
        }

        return count[n-1];

    }
};