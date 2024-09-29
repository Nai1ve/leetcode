#include<stdio.h>


void move(int a,int b){
    printf("将%d移动到%d\n",a,b);
}

void hanio(int n,int a,int b,int c){
    if (n > 0)
    {
        hanio(n-1,a,c,b);
        move(a,b);
        hanio(n-1,c,b,a);
    }
    
}

int main(){
    hanio(5,1,2,3);
}