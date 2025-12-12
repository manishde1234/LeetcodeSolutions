class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        //create 2 map for storing the values
        unordered_map<int,pair<int,int>>xToMinMaxY;
        unordered_map<int,pair<int,int>>yToMinMaxX;

        //first for loop for populating the map
        for(auto &building: buildings){
            int x = building[0];
            int y = building[1];

            if(!xToMinMaxY.count(x)){
                xToMinMaxY[x] = {INT_MAX,INT_MIN};
            }

            if(!yToMinMaxX.count(y)){
                yToMinMaxX[y] = {INT_MAX,INT_MIN};
            }

            //set the values
            xToMinMaxY[x] = {min(xToMinMaxY[x].first, y),
             max(xToMinMaxY[x].second,y)};

            yToMinMaxX[y] = {min(yToMinMaxX[y].first,x),
             max(yToMinMaxX[y].second,x)};
        }

        //now compare the values
        int count = 0;
        for(auto &building: buildings){
            int x = building[0];
            int y = building[1];

            auto &xmap = xToMinMaxY[x];
            auto &ymap = yToMinMaxX[y];

            if(xmap.first < y  && y < xmap.second &&
                ymap.first < x && x < ymap.second){
                count++;
            }
        }

        return count;
    }
};