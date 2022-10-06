#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int count_=0;
static int callback_get_count(void* data, int argc, char** argv, char** colName){
    for(int i=0;i<argc;i++){
        count_ = atoi(argv[i]);
    }
    return 0;
}

vector<int> room_numbers;
static int callback_get_rooms(void* data, int argc, char** argv, char** colName){
    for(int i=0;i<argc;i++){
        room_numbers.push_back(stoi(argv[i]));
    }
    return 0;
}

int allotRoom(string room_type){
    sqlite3 *DB;
    int myCursor = 0;
    char *error;

    myCursor = sqlite3_open("AJAX HMS.db", &DB);
    //error handling
    if(myCursor){
        cerr << "Error While Loading Database!\n";
        cout << sqlite3_errmsg(DB) << "\n";
        return -1;
    }

    string query;
    query = "SELECT COUNT(ALL) FROM AJAX_DB WHERE ROOM_TYPE = '"+room_type+"';";
    myCursor = sqlite3_exec(DB, query.c_str(), callback_get_count, NULL, NULL);

    if(count_ == 0){
        if(room_type == "SINGLE") return 101;
        else if(room_type == "DOUBLE") return 201;
        else if(room_type == "SUITE") return 301;
        else if(room_type == "MURPHY") return 401;
        else if(room_type == "CABANA") return 501;
        else return 0;
    }
    else{
        query = "SELECT ROOM_NO FROM AJAX_DB WHERE ROOM_TYPE = '"+room_type+"';";
        myCursor = sqlite3_exec(DB, query.c_str(), callback_get_rooms, NULL, NULL);

        sort(room_numbers.begin(), room_numbers.end()); //Intrasort (std::sort)
        for(int i=0;i<room_numbers.size()-1;i++){
            if(room_numbers[i+1]-room_numbers[i] >= 2)
                return room_numbers[i]+1;
        }
        return room_numbers[room_numbers.size()-1]+1;
    }
}