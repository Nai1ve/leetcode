#include <iostream>
using namespace std;

int s[10][10];

void digital_tower(int n, int tower[10][10]){

    int step[n+1];

    for(int i=0;i<n;i++){
        s[0][i] = tower[0][i];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            s[i][j] = tower[i][j] + max(s[i-1][j], s[i-1][j+1]);
            if(s[i-1][j] >s[i-1][j+1]){
                step[i] = j + 1;
            }else{
                step[i] = j + 1 + 1;
            }
        }
    }         

    for (int i = 0; i < n+1; i++)
    {
        cout << "step[" << i << "] = " << step[i] << ' ';
    }
    
    cout<<endl;
}

void print_array(int n){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n-i;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n = 5;

    int tower[10][10];
    tower[0][0] = 4;
    tower[0][1] = 5;
    tower[0][2] = 2;
    tower[0][3] = 6;
    tower[0][4] = 5;
    tower[1][0] = 7;
    tower[1][1] = 12;
    tower[1][2] = 10;
    tower[1][3] = 22;
    tower[2][0] = 20;
    tower[2][1] = 13;
    tower[2][2] = 10;
    tower[3][0] = 23;
    tower[3][1] = 21;
    tower[4][0] = 30;

    digital_tower(n, tower);
    print_array(n);
}