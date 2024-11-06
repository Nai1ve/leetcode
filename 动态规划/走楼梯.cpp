#include <iostream>
using namespace std;

// 两级台阶的情况

int climbStairs(int n,int cost[100]) {
    int result[n+1];
    result[0] = 0;
    result[1] = cost[0];
    result[2] = max(cost[0] + cost[1],cost[1]);

    for(int i = 2;i<n;i++){
        result[i+1] = max(cost[i] + result[i-1],cost[i] + result[i]);
        
    }
    

    return result[n];
}

int main() {
    int n = 5;
    int cost[100] = {10,15,-20,-100,40};
    cout<<climbStairs(n,cost)<<endl;
    return 0;
}