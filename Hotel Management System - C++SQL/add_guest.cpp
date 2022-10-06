#include <bits/stdc++.h>
#include <sqlite3.h>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

int ID;
int ID1;

static int callback(void* data, int argc, char** argv, char** colName){
    for(int i=0;i<argc;i++){
        ID = atoi(argv[i]);
    }
    return 0;
}

static int callback1(void* data, int argc, char** argv, char** colName){
    for(int i=0;i<argc;i++){
        ID1 = atoi(argv[i]);
    }
    return 0;
}

int addGuest(){
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

    string query, query1;
    // query = "SELECT COUNT(*) FROM AJAX_DB;";
    // query1 = "SELECT COUNT(*) FROM AJAX_OLD_DB;";

    // myCursor = sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
    // myCursor = sqlite3_exec(DB, query1.c_str(), callback, NULL, NULL);
    // if(ID == 0 && ID1 == 0){
    //     ID = 1;
    // }
    {
        query = "SELECT ID FROM AJAX_DB ORDER BY ID DESC LIMIT 1;";
        query1 = "SELECT ID FROM AJAX_OLD_DB ORDER BY ID DESC LIMIT 1;";
        myCursor = sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
        myCursor = sqlite3_exec(DB, query1.c_str(), callback, NULL, NULL);

        ID = max(ID, ID1) + 1;
    }

    int room_number,amount;
    string name, address, mobile, aadhar, check_in_date, check_in_time, check_out_date, check_out_time, room_type;
    cout << "Guest Number ->> " << ID << "\n";
    cout << "Enter the Name of Guest ->> ";
    fflush(stdin);
    getline(cin,name);
    fflush(stdin);
    cout << "Enter the Address of Guest ->> ";
    getline(cin,address);
    fflush(stdin);
    cout << "Enter the Mobile Number of Guest ->> ";
    getline(cin,mobile);
    fflush(stdin);
    cout << "Enter the Aadhaar Number of Guest ->> ";
    getline(cin,aadhar);
    fflush(stdin);
    cout << "Enter the Check Out Date of Guest (YYYY-MM-DD) ->> ";
    getline(cin,check_out_date);
    fflush(stdin);
    cout << "Enter the Check Out Time of Guest (HH:MM) ->> ";
    getline(cin,check_out_time);
    fflush(stdin);
    cout << "\nEnter The Type of Room Guest wants ->> \n";
    cout << "1. Single ( > 1 ) ->> \n";
    cout << "2. Double ( > 2 ) ->> \n";
    cout << "3. Suite  ( > 3 ) ->> \n";
    cout << "4. Murphy ( > 4 ) ->> \n";
    cout << "5. Cabana ( > 5 ) ->> \n";
    cout << "Enter Choice ->> ";
    cin >> room_type;
    room_type = room_type=="1" ? "SINGLE" : room_type=="2" ? "DOUBLE" : room_type=="3" ? "SUITE" : room_type=="4" ? "MURPHY" : room_type=="5" ? "CABANA" : "0";

    auto ztime = time(0);
    stringstream _time_date, _time_time;
    _time_date << put_time(localtime(&ztime), "%Y-%m-%d");
    check_in_date = _time_date.str();
    _time_time << put_time(localtime(&ztime), "%H:%M");
    check_in_time = _time_time.str();
    amount = calculateRent(check_in_date, check_out_date, room_type);
    
    cout << "Amount Payable ->> Rs." << amount;
    cout << "\n\n";
    cout << "Do you want to check in (Y/y)? ->> ";
    char choice;
    cin >> choice;
    if(choice == 'y' || choice == 'Y'){
        room_number = allotRoom(room_type);
        cout << "Alloted Room ->> " << room_number;

        Customer C;
        C.setData(ID,name,address,mobile,aadhar,check_in_date,check_in_time,check_out_date,check_out_time,room_number,room_type,amount);

        query = C.getData(true);
        myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
        insertion_check(myCursor, error);        
    }

    sqlite3_close(DB);
    return 0;
}