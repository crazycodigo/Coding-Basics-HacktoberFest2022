#include <bits/stdc++.h>
#include <string>

using namespace std;

static int callback_test(void *data, int argc, char **argv, char **colName){
    cout << argc;
    for (int i = 0; i < argc; i++){
        cout << colName[i] << " - " << argv[i];
    }
    // D.getData();
    return 0;
}

int refreshDB(){
    auto ztime = time(0);
    stringstream _time_date, _time_time;
    _time_date << put_time(localtime(&ztime), "%Y-%m-%d");
    string cur_date = _time_date.str();
    _time_time << put_time(localtime(&ztime), "%H:%M");
    string cur_time = _time_time.str();

    // cout << cur_date << " " << cur_time;
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
    query = "INSERT INTO AJAX_OLD_DB SELECT * FROM AJAX_DB WHERE '"+cur_date+"' > OUT_DATE;";
    myCursor = sqlite3_exec(DB, query.c_str(), NULL, NULL, &error);
    insertion_check(myCursor, error);

    query = "DELETE FROM AJAX_DB WHERE '"+cur_date+"' > OUT_DATE;";
    myCursor = sqlite3_exec(DB, query.c_str(), NULL, NULL, &error);

    string refreshing = "R E F R E S H I N G . . .";
    for(int i=0;i<refreshing.length();i++){
        cout << refreshing[i];
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout <<"\nDatabase Updated Successfully !!!\n\n";
    system("pause");
    return 0;
}