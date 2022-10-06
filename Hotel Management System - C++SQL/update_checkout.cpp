#include <bits/stdc++.h>
#include <string>

using namespace std;

class CallBack{
    private:
        string initialDate;
        string roomType;
        int amt;
    public:
        void setDate(string initialDate){
            this->initialDate = initialDate;
        }
        string getDate(){
            return initialDate;
        }
        void setRoomType(string roomType){
            this->roomType = roomType;
        }
        string getRoomType(){
            return roomType;
        }
        void setAmount(int amt){
            this->amt = amt;
        }
        int getAmount(){
            return amt;
        }
        
};

CallBack C;
static int exit_;
static int callback_get_initalDate(void *data, int argc, char **argv, char **colName){
    if (argc == 0){
        exit_=-1;
        return -1;
    }
    for (int i = 0; i < argc; i++){
        C.setDate(argv[i]);
    }
    // D.getData();
    return 0;
}

static int callback_get_roomType(void *data, int argc, char **argv, char **colName){
    for (int i = 0; i < argc; i++){
        C.setRoomType(argv[i]);
    }
    // D.getData();
    return 0;
}

static int callback_get_initialAmount(void *data, int argc, char **argv, char **colName){
    for (int i = 0; i < argc; i++){
        C.setAmount(stoi(argv[i]));
    }
    // D.getData();
    return 0;
}

int count__=0;
static int callback_get_count1(void* data, int argc, char** argv, char** colName){
    for(int i=0;i<argc;i++){
        count__ = atoi(argv[i]);
    }
    return 0;
}

int updateCheckout(){
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

    int rno;
    cout << "Enter Room Number To Update Check-out Date ->> ";
    cin >> rno;
    string query;

    query = "SELECT COUNT (ALL) FROM AJAX_DB WHERE ROOM_NO = "+to_string(rno)+";";
    myCursor = sqlite3_exec(DB, query.c_str(), callback_get_count1, NULL, NULL);
    if(count__==0){
        cout << "No Guest Found\n";
        return 0;
    }

    query = "SELECT OUT_DATE FROM AJAX_DB WHERE ROOM_NO = "+to_string(rno)+";";
    myCursor = sqlite3_exec(DB, query.c_str(), callback_get_initalDate, NULL, NULL);

    query = "SELECT ROOM_TYPE FROM AJAX_DB WHERE ROOM_NO = "+to_string(rno)+";";
    myCursor = sqlite3_exec(DB, query.c_str(), callback_get_roomType, NULL, NULL);

    query = "SELECT AMOUNT FROM AJAX_DB WHERE ROOM_NO = "+to_string(rno)+";";
    myCursor = sqlite3_exec(DB, query.c_str(), callback_get_initialAmount, NULL, NULL);

    string newDate;
    cout << "Enter New Check-out Date (YYYY-MM-DD) ->> ";
    cin >> newDate;

    string newTime;
    cout << "Enter New Check-out Time (HH:MM) ->> ";
    cin >> newTime;

    int newAmount = calculateRent(C.getDate(),newDate,C.getRoomType());

    //YYYY-MM-DD
    int days, months, years;
    days = stoi(newDate.substr(8,10)) - stoi(C.getDate().substr(8,10));
    months = stoi(newDate.substr(5,7)) - stoi(C.getDate().substr(5,7));
    years = stoi(newDate.substr(0,4)) - stoi(C.getDate().substr(0,4));

    int nodStay = days + months*30 + years*12*30;

    char choice;
    cout << "Extra Amount To Pay For " << nodStay << " Days ->> Rs. " << newAmount << "\n";
    cout << "Do You Want To Confirm? (Y/y) ->> ";
    cin >> choice;

    int totalAmount = newAmount+C.getAmount();

    if(choice == 'Y' || choice == 'y'){
        query = "UPDATE AJAX_DB SET OUT_DATE = '"+newDate+"', OUT_TIME = '"+newTime+"', AMOUNT = "+to_string(totalAmount)+" WHERE ROOM_NO = "+to_string(rno)+";";
        char *error;
        myCursor = sqlite3_exec(DB, query.c_str(),NULL,NULL,&error);
        insertion_check(myCursor, error);
        cout << "DATA UPDATED SUCCESSFULLY !!!";
    }
    sqlite3_close(DB);
    return 0;
}