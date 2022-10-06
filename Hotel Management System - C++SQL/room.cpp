#include<bits/stdc++.h>
#include<sqlite3.h>
#include<string>

using namespace std;

// void insertion_check(int check, char *error){
//     if(check != SQLITE_OK){
//         cerr << "ERROR INSERTING DATA\n";
//         cout << error << "\n";
//     }
// }

class Room{
    private:
        int addRoomInfoToDB();
        int addRoomInfoToDB(bool isData, sqlite3* DB);
    public:
        Room(){
            addRoomInfoToDB();
        }
};

int Room :: addRoomInfoToDB(bool isData, sqlite3 *DB){
    if(true){
        int myCursor = 0;
        char *error;
        string query;

        query = "INSERT INTO ROOM_SPECIFICATIONS VALUES('AJAX1', 'SINGLE', 1, 'YES', 'YES', 'NO', 'NO', 3000);";
        // query = "INSERT INTO ROOM_SPECIFICATIONS (ID, TYPE, BEDS, AC, WiFi, AI, POOL, RENT) SELECT 'AJAX1', 'SINGLE', 1, 'YES', 'YES', 'NO', 'NO', 3000 FROM ROOM_SPECIFICATIONS WHERE NOT EXISTS(SELECT * FROM ROOM_SPECIFICATIONS WHERE ID = 'AJAX1');";
        myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
        insertion_check(myCursor, error);

        query = "INSERT INTO ROOM_SPECIFICATIONS VALUES('AJAX2', 'DOUBLE', 2, 'YES', 'YES', 'NO', 'NO', 4500);";
        // query = "INSERT INTO ROOM_SPECIFICATIONS (ID, TYPE, BEDS, AC, WiFi, AI, POOL, RENT) SELECT 'AJAX2', 'DOUBLE', 2, 'YES', 'YES', 'NO', 'NO', 4500 FROM ROOM_SPECIFICATIONS WHERE NOT EXISTS(SELECT * FROM ROOM_SPECIFICATIONS WHERE ID = 'AJAX2');";
        myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
        insertion_check(myCursor, error);

        query = "INSERT INTO ROOM_SPECIFICATIONS VALUES('AJAX3', 'SUITE', 2, 'YES', 'YES', 'YES', 'NO', 6000);";
        // query = "INSERT INTO ROOM_SPECIFICATIONS (ID, TYPE, BEDS, AC, WiFi, AI, POOL, RENT) SELECT 'AJAX3', 'SUITE', 2, 'YES', 'YES', 'YES', 'NO', 6000 FROM ROOM_SPECIFICATIONS WHERE NOT EXISTS(SELECT * FROM ROOM_SPECIFICATIONS WHERE ID = 'AJAX3');";
        myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
        insertion_check(myCursor, error);

        query = "INSERT INTO ROOM_SPECIFICATIONS VALUES('AJAX4', 'MURPHY', 4, 'YES', 'YES', 'YES', 'NO', 8000);";
        // query = "INSERT INTO ROOM_SPECIFICATIONS (ID, TYPE, BEDS, AC, WiFi, AI, POOL, RENT) SELECT 'AJAX4', 'MURPHY', 4, 'YES', 'YES', 'YES', 'NO', 8000 FROM ROOM_SPECIFICATIONS WHERE NOT EXISTS(SELECT * FROM ROOM_SPECIFICATIONS WHERE ID = 'AJAX4');";
        myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
        insertion_check(myCursor, error);

        query = "INSERT INTO ROOM_SPECIFICATIONS VALUES('AJAX5', 'CABANA', 2, 'YES', 'YES', 'YES', 'YES', 10000);";
        // query = "INSERT INTO ROOM_SPECIFICATIONS (ID, TYPE, BEDS, AC, WiFi, AI, POOL, RENT) SELECT 'AJAX5', 'CABANA', 2, 'YES', 'YES', 'YES', 'YES', 10000 FROM ROOM_SPECIFICATIONS WHERE NOT EXISTS(SELECT * FROM ROOM_SPECIFICATIONS WHERE ID = 'AJAX5');";
        myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
        insertion_check(myCursor, error);

        system("cls");

    }
    return 0;
}

int Room :: addRoomInfoToDB(){
    sqlite3 *DB;
    int myCursor = 0;
    char *error;
    myCursor = sqlite3_open("AJAX HMS.db", &DB);

    if(myCursor){
        cerr << "Error While Loading Database!\n";
        cout << sqlite3_errmsg(DB) << "\n";
        return -1;
    }

    string query = "CREATE TABLE IF NOT EXISTS ROOM_SPECIFICATIONS(ID TEXT PRIMARY KEY NOT NULL, "
                                                                 "TYPE TEXT NOT NULL, BEDS INT NOT NULL, "
                                                                 "AC TEXT NOT NULL, WiFi TEXT NOT NULL, "
                                                                 "AI TEXT NOT NULL, POOL TEXT NOT NULL, "
                                                                 "RENT INT NOT NULL);";

    myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);

    if(myCursor != SQLITE_OK){
        cerr << "ERROR CREATING ROOM SPECIFICATION TABLE\n";
        cout << error << "\n";
        sqlite3_free(error);
    }

    addRoomInfoToDB(true, DB);//insert values in database

    cout << "Successfully Created/Loaded Hotel Management System Environment!\n\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << setw(60) << "--- HOTEL DETAILS ---\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << setw(60) << "--- HOTEL CLOUD_9 ---\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << setw(72) << "--- THE HOTEL IS SITUATED UP ABOVE IN SPACE ---\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << setw(88) << "--- THE MODE OF GOING TO HOTEL IS BY INTERGALECTIAL LIFT DEVELOPED BY SPACEX ---\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << setw(74) << "--- THE HOTEL IS FULLY ARTIFICIAL INTELLIGENCE ---\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << setw(68) << "--- THERE ARE SO MANY OTHER FEATURES ---\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    sqlite3_close(DB);
    return 0;
}