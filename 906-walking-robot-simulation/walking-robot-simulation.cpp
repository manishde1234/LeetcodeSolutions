class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string>st;
        for(auto &obst : obstacles){
            string key = to_string(obst[0]) + "_" + to_string(obst[1]);
            st.insert(key);
        }

        int x = 0;
        int y = 0;
        int maxDist = 0;

        pair<int,int>dir = {0,1};//north

        for(int i = 0; i < commands.size(); i++){
            if(commands[i] == -2){
                dir = {-dir.second,dir.first};
            }
            else if(commands[i] == -1){
                dir = {dir.second,-dir.first};
            }
            else{
                for(int steps = 0; steps < commands[i]; steps++){
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    string newKey = to_string(newX) + "_" + to_string(newY);
                    if(st.find(newKey) != st.end()){
                        //element in st
                        break;
                    }
                    x = newX;
                    y = newY;
                }
            }
            maxDist = max(maxDist, x*x + y*y);
        }
        return maxDist;
    }
};