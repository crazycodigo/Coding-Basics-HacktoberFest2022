#include<bits/stdc++.h>
#include<sqlite3.h>
#include<string>

using namespace std;

class Customer{
    private:
        int createTable();
        int addCustomerDetails();
        int ID,room_number,amount;
        string name, address, mobile, aadhar, check_in_date, check_in_time, check_out_date, check_out_time, room_type;
        string data;
    public:
        Customer(bool flag){
            createTable();
        }
        Customer(){
            string getData(bool flag);

            void setData(int ID, string name, string address, string mobile, string aadhar, string check_in_date, string check_in_time, string check_out_date, string check_out_time, int room_number, string room_type, int amount);
        }
        void setData(int ID, string name, string address, string mobile, string aadhar, string check_in_date, string check_in_time, string check_out_date, string check_out_time, int room_number, string room_type, int amount){
            this->ID=ID;
            this->name=name;
            this->address=address;
            this->mobile=mobile;
            this->aadhar=aadhar;
            this->check_in_date=check_in_date;
            this->check_in_time=check_in_time;
            this->check_out_date=check_out_date;
            this->check_out_time=check_out_time;
            this->room_number=room_number;
            this->room_type=room_type;
            this->amount=amount;
        }
        string getData(bool flag){
            data = "INSERT INTO AJAX_DB VALUES("+to_string(ID)+", '"+name+"', '"+address+"', '"+mobile+"', '"+aadhar+"', '"+check_in_date+"', '"+check_in_time+"', '"+check_out_date+"', '"+check_out_time+"', "+to_string(room_number)+", '"+room_type+"', "+to_string(amount)+");";
            
            return data;
        }
};

int Customer :: createTable(){
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

    string query = "CREATE TABLE IF NOT EXISTS AJAX_DB(ID INT PRIMARY KEY NOT NULL, " 
                                                    "NAME TEXT NOT NULL, "
                                                    "ADDRESS TEXT, "
                                                    "MOBILE TEXT NOT NULL, "
                                                    "AADHAR TEXT NOT NULL, "
                                                    "IN_DATE TEXT NOT NULL, "
                                                    "IN_TIME TEXT NOT NULL, "
                                                    "OUT_DATE TEXT NOT NULL, "
                                                    "OUT_TIME TEXT NOT NULL, "
                                                    "ROOM_NO INT NOT NULL, "
                                                    "ROOM_TYPE TEXT NOT NULL, "
                                                    "AMOUNT INT NOT NULL);";

    myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
    if(myCursor != SQLITE_OK){
        cerr << "ERROR CREATING CUSTOMER INFORMATION TABLE\n";
        cout << error << "\n";
        sqlite3_free(error);
    }

    query = "CREATE TABLE IF NOT EXISTS AJAX_OLD_DB(ID INT PRIMARY KEY NOT NULL, " 
                                                    "NAME TEXT NOT NULL, "
                                                    "ADDRESS TEXT, "
                                                    "MOBILE TEXT NOT NULL, "
                                                    "AADHAR TEXT NOT NULL, "
                                                    "IN_DATE TEXT NOT NULL, "
                                                    "IN_TIME TEXT NOT NULL, "
                                                    "OUT_DATE TEXT NOT NULL, "
                                                    "OUT_TIME TEXT NOT NULL, "
                                                    "ROOM_NO INT NOT NULL, "
                                                    "ROOM_TYPE TEXT NOT NULL, "
                                                    "AMOUNT INT NOT NULL);";

    myCursor = sqlite3_exec(DB, query.c_str(), NULL, 0, &error);
    if(myCursor != SQLITE_OK){
        cerr << "ERROR CREATING CUSTOMER INFORMATION TABLE\n";
        cout << error << "\n";
        sqlite3_free(error);
    }

    sqlite3_close(DB);
    return 0;
}