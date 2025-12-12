class Solution {
public:
//     void applymessage(vector<int> &mentions, vector<int> &offlineUsers,
//        vector<string>& event ){
//         int timestamp = stoi(event[1]);
//         //if all then increment all id 
//         if(event[2] == "ALL"){
//             for(int i = 0; i < mentioclass Solution {
// public:
      void applymessage(vector<string>event, vector<int>&mentions, vector<int>&offlineUsers){

        int timestamp = stoi(event[1]);

        vector<string> ids;

        stringstream ss(event[2]);

        string token;
        while(ss >> token){
            ids.push_back(token);
        }

        //Process all IDs
        for(string id : ids) {
            if(id == "ALL") {
                for(int i = 0; i<mentions.size(); i++) {
                    mentions[i]++;
                }
            } else if(id == "HERE") {
                for(int i = 0; i < mentions.size(); i++){
                    if(offlineUsers[i] == 0 || offlineUsers[i] + 60 <= timestamp){
                        mentions[i]++;
                    }
                }
            } else {
                mentions[stoi(id.substr(2))]++; //fetch id value i.e. x from idx (id0, id1 etc)
            }
        }

    }

    /////////
    // void applymessage(vector<int> &mentions, vector<int> &offlineUsers,
    //    vector<string>& event ){
    //     int timestamp = stoi(event[1]);
    //     //if all then increment all id 
    //     if(event[2] == "ALL"){
    //         for(int i = 0; i < mentions.size(); i++){
    //             mentions[i]++;
    //         }
    //     }

    //     //if here then increment online user
    //     if(event[2] == "HERE"){
    //         for(int i = 0; i < offlineUsers.size(); i++){
    //             if(offlineUsers[i] == 0 || offlineUsers[i] + 60 <= timestamp){
    //                 mentions[i]++;
    //             }
    //         }
    //     }

    //     //if ids are mentioned
    //     else{
    //         stringstream ss(event[2]);
    //         string token;
    //         vector<string> ids;

    //         while(ss >> token){
    //             ids.push_back(token);
    //         }

    //         for(auto id: ids){
    //             int identity = stoi(id.substr(2));
    //             mentions[identity]++;
    //         }
    //     }
    // }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers);
        vector<int> offlineUsers(numberOfUsers);

        //sort the data
        auto lambda = [](vector<string> &vec1, vector<string> &vec2){
            int t1 = stoi(vec1[1]);
            int t2 = stoi(vec2[1]);

            if(t1 == t2){
                //offline first
                cout << vec1[0][0] << " vec2" << vec1[0][1];
                return vec1[0][0] > vec2[0][0];
            }
            return t1 < t2;
        };

        sort(events.begin(),events.end(),lambda);

        //simulation
        for(auto &event: events){
             cout << event[0][0] << " vec2 " << event[0][1];
            if(event[0] == "MESSAGE"){
                
                // applymessage(mentions, offlineUsers, event);
                applymessage(event, mentions, offlineUsers);
            }
            else if(event[0] == "OFFLINE"){
                int id = stoi(event[2]);
                offlineUsers[id] = stoi(event[1]);
            }
        }

        return mentions;
    }
};