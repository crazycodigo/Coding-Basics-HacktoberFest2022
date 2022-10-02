/*Link to the Question->https://www.hackerrank.com/challenges/variable-sized-arrays/problem*/
#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int N,q;
    cin>>N>>q;
    vector<int> v[N];
    for(int i=0;i<N;i++)
    {
        int n;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            v[i].push_back(x);
        }
    }
    vector<int> z;
    int r, s;
    for(int k = 0; k < q; k++)
    {
        cin >> r >> s;
        int x;
        x=v[r][s];
        z.push_back(x);
    }
    for(int ele:z)
    {
        cout<<ele<<endl;
    }
    

    return 0;
}
