#include<bits/stdc++.h>
#include<sqlite3.h>
#include<string>
#include <chrono>
#include <thread>

#include "insertion_check.cpp"
#include "query_exec.cpp"
#include "room.cpp"
#include "customer.cpp"
#include "room_allotment.cpp"
#include "calculate_rent.cpp"
#include "add_guest.cpp"
#include "update_checkout.cpp"
#include "refresh_db.cpp"

using namespace std;

int mainMenu(){
    int choice;
     int choice1;
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "\n";
    cout << "1.Add New Guest( > 1 ) ->> \n";
    cout << "2.View Room Specifications( > 2 ) ->> \n";
    cout << "3.Query( > 3 ) ->> \n";
    cout << "4.Update Check Out Time( > 4 ) ->> \n";
    cout << "5.Display Data of Old Customers( > 5 ) ->> \n";
    cout << "6.Refresh Database( > 6 ) ->> \n";
    cout << "7.Clear Screen ( > 7 ) ->> \n";
    cout << "8.Exit( > 8 ) ->> \n";
    cout << "\n";
    cout << "Enter Choice  ->> ";
    cin >> choice;
    cout << "\n";
    switch(choice){
        case 1 : {
            cout << "\n";
            addGuest();
        }
        break;
        case 2 : {
            this_thread::sleep_for(chrono::milliseconds(200));
            cout << "\n";
            cout << "--- ROOM SPECIFICATIONS ---\n\n";
            queryExec("SELECT * FROM ROOM_SPECIFICATIONS;");
        }
        break;
        case 3 : {
            int choice1;
            this_thread::sleep_for(chrono::milliseconds(200));
            cout.flush();
            cout << "\n";
            cout << "--- QUERY MENU ---\n\n";
            cout << "\n1. Get Guest Details Alphabetically... ( > 1 )->> \n";
            cout << "2. Get Guest Details ID Wise... ( > 2 )->> \n";
            cout << "3. Get Guest Details Check IN Date Wise... ( > 3 )->> \n";
            cout << "4. Get Guest Details Check OUT Date Wise... ( > 4 )->> \n";
            cout << "5. Get Guest Details Room Number Wise... ( > 5 )->> \n";
            cout << "6. Back To Main Menu... ( > 6 )->> \n";
            cout << "\nEnter Choice ->> ";
            cin >> choice1;
            cout << "\n";
            switch(choice1){
                case 1 : {
                    // cout << "\n";
                    cout << "--- GUEST DETAILS ---\n\n";
                    this_thread::sleep_for(chrono::milliseconds(200));
                    queryExec("SELECT * FROM AJAX_DB ORDER BY NAME ASC;");
                    this_thread::sleep_for(chrono::milliseconds(200));
                }
                break;
                case 2 : {
                    int search_ID;
                    cout << "\n";
                    cout << "Enter Guest ID to search ->> ";
                    cin >> search_ID;
                    this_thread::sleep_for(chrono::milliseconds(200));
                    // cout << "\n";
                    cout << "--- GUEST DETAILS ---\n\n";
                    this_thread::sleep_for(chrono::milliseconds(200));
                    queryExec("SELECT * FROM AJAX_DB WHERE ID = "+to_string(search_ID)+";");
                }
                break;
                case 3 : {
                    string search_check_in_date;
                    cout << "\n";
                    cout << "Enter Check IN Date to search (YYYY-MM-DD) ->> ";
                    cin >> search_check_in_date;
                    this_thread::sleep_for(chrono::milliseconds(200));
                    // cout << "\n";
                    cout << "--- GUEST DETAILS ---\n\n";
                    this_thread::sleep_for(chrono::milliseconds(200));
                    queryExec("SELECT * FROM AJAX_DB WHERE IN_DATE = '"+search_check_in_date+"';");
                }
                break;
                case 4 : {
                    string search_check_out_date;
                    cout << "\n";
                    cout << "Enter Check OUT Date to search (YYYY-MM-DD) ->> ";
                    cin >> search_check_out_date;
                    this_thread::sleep_for(chrono::milliseconds(200));
                    // cout << "\n";
                    cout << "--- GUEST DETAILS ---\n\n";
                    this_thread::sleep_for(chrono::milliseconds(200));
                    queryExec("SELECT * FROM AJAX_DB WHERE OUT_DATE = '"+search_check_out_date+"';");
                }
                break;
                case 5 : {
                    int search_rno;
                    cout << "\n";
                    cout << "Enter Room Number to search ->> ";
                    cin >> search_rno;
                    this_thread::sleep_for(chrono::milliseconds(200));
                    cout << "\n";
                    cout << "--- GUEST DETAILS ---\n\n";
                    this_thread::sleep_for(chrono::milliseconds(200));
                    queryExec("SELECT * FROM AJAX_DB WHERE ROOM_NO = "+to_string(search_rno)+";");
                }
                break;
                case 6 : //continue
                break;
                default : cout << "Sorry, Wrong Choice !!!\n"; 
            }
        }
        break;
        case 4 : {
            cout << "\n";
            updateCheckout();
            cout << "\n";
            system("pause");
        }
        break;
        case 5 : {
            this_thread::sleep_for(chrono::milliseconds(200));
            cout << "\n";
            cout <<"--- GUEST DETAILS ---\n\n";
            this_thread::sleep_for(chrono::milliseconds(200));
            queryExec("SELECT * FROM AJAX_OLD_DB;");
        }
        break;
        case 6 : {
            cout << "\n\n";
            refreshDB();
        }
        break;
        case 7 : system("cls");
        break;
        case 8 : {
            cout << "\nTHANK YOU ";
            this_thread::sleep_for(chrono::milliseconds(200));
            cout << "FOR USING ";
            this_thread::sleep_for(chrono::milliseconds(200));
            cout << "CLOUD_9 HOTEL MANAGEMENT SYSTEM !!!\n";
            this_thread::sleep_for(chrono::milliseconds(5000));
            return 1;
        }
        break;
        default : {
            cout << "Sorry, Wrong Choice !!!\n";
            system("pause");
        }
        break;
    }
    return 0;
}

int main(){
    Room R;
    Customer C(true);
    while(true){
        cout << "\n";
        int exit = mainMenu();
        if(exit) return 0;
    }
}