#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class Data_Query{
    private:
        vector <string> column_names;
        vector <pair<string,string>> query_data;
    public:
        void setData(string value, string col){
            int temp=0;
            // cout << value << " " << col << "\n";
            for(int i=0;i<column_names.size();i++){
                // cout <<type_info(column_names[i]) << " " << type_info(col) << "\n";
                // cout <<column_names[i] << " " << col << "\n";
                if(column_names[i] == col){
                    temp = 1;
                    break;
                }
            }
            if(!temp) column_names.push_back(col);
            // cout << col << " " << value << "\n";
            query_data.push_back(make_pair(col,value));
        }
        void getData(){
            // cout << "kal";
            if(query_data.size() == 0){
                cout << "No Guest Found !!!\n";
            }
            else{
                cout << "\n";
                for(int i=0;i<column_names.size();i++){
                    if(i==0){
                        cout << left << setw(9) << column_names[i];
                    }
                    else if(i!=column_names.size()-1)
                    cout << left << setw(13.5) << column_names[i];
                    else
                    cout << column_names[i] << "\n";
                }

                for(int i=0;i<column_names.size();i++){
                    if(i==0){
                        cout << left << setw(9) << "-------";
                    }
                    else if(i!=column_names.size()-1)
                    cout << left << setw(13.5) << "----------";
                    else
                    cout << "----------\n";
                }

                for(int i=0,j=0;i<query_data.size();i++,j++){
                    if(j==column_names.size()) {
                        j=0;
                        cout << "\n";
                    }
                    if(query_data[i].first == column_names[j] && j==0)
                        cout << left << setw(9) << query_data[i].second;
                    else if(query_data[i].first == column_names[j])
                        cout << left << setw(13.5) << query_data[i].second;
                }
                cout << "\n\n";
                system("pause");
            }
            query_data.clear();
            column_names.clear();
        }
};

Data_Query D;

static int callback_get_queryData(void* data, int argc, char** argv, char** colName){
    for(int i=0;i<argc;i++){
        D.setData(string(argv[i] ? argv[i] : "NULL"), (string)colName[i]);
    }
    // D.getData();
    return 0;
}

int queryExec(string query){
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
    
    myCursor = sqlite3_exec(DB, query.c_str(), callback_get_queryData, NULL, NULL);
    // Data_Room_Specs D;
    D.getData();

    sqlite3_close(DB);
    return 0;    
}