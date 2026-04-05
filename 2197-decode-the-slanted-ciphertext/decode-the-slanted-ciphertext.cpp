class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int stringlen = encodedText.length();
        int column = stringlen/rows;
        string answer = "";
        
        // vector<vector<char>>matrix(rows,vector<char>(column));
        // //populate the matrix
        // int pointer = 0;
        // for(int i = 0; i < rows; i++){
        //     for(int j = 0; j < column; j++){
        //         matrix[i][j] = encodedText[pointer];
        //         pointer++;
        //     }
        // }

        // //now print the actual string
        // for(int col = 0; col < column; col++){
        //     int i = 0;
        //     int j = col;

        //     while(i < rows && j < column){
        //         answer += matrix[i][j];
        //         i++;
        //         j++;
        //     }
        // }

        //approach 2 -- no extra space

        for(int col = 0; col < column; col++){
            int i = col;

            while(i < stringlen){
                answer += encodedText[i];
                i = i+ column +1;
            }
        }

        //remove the trailing spaces
        while(!answer.empty() && answer.back() == ' '){
            answer.pop_back();
        }

        return answer;
    }
};