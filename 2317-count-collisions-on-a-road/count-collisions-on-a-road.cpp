class Solution {
public:
    int countCollisions(string directions) {
        int collision = 0;

        int i = 0;
        int n = directions.length();
        int j = n-1;      

        //remove the boundary cars
        while(i < n && directions[i] =='L'){
            i++;
        }

        while(j >= 0 && directions[j] == 'R'){
            j--;
        }

        while( i <= j){
            if(directions[i] != 'S'){
                collision++;
            }
            i++;
        }

        return collision;
    }
};