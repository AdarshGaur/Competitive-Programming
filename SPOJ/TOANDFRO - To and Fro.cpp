#include <bits/stdc++.h>
#define endl "\n"
#define ll long LONG
#define mod 1000000007
#define MAX 100001

using namespace std;

void reverse_string(string &str){
    int n = str.length();

    for (int i = 0; i < n / 2; i++){
        swap(str[i], str[n - i - 1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int counter=0;
    while(true){
        int N;cin>>N;
        if(N==0){
            return 0;
        }
        if(counter!=0){
            cout<<endl;
        }
        string str, temp;
        cin>>str;
        counter++;
        int row = (str.length()/N);
        char a[row][N];
        for(int i=0; i<row; i++){
            temp = str.substr(i*N, N);
            if(i%2!=0){
                reverse_string(temp);
            }
            for(int j=0; j<N; j++){
                a[i][j]=temp.at(j);
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<row; j++){
                cout<<a[j][i];
            }
        }
    }
}