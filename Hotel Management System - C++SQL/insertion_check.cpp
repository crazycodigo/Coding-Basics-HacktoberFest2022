#include<bits/stdc++.h>
#include<sqlite3.h>
#include<string>

using namespace std;

void insertion_check(int check, char *error){
    if(check != SQLITE_OK){
        cerr << "ERROR INSERTING DATA\n";
        cout << error << "\n";
    }
}