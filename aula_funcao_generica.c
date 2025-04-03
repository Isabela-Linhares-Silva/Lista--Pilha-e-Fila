#include<stdio.h>

int soma(int a,int b);
int sub(int a, int b);
void exec (int a, int b, int (*func)(int,int));

int main(){
    exec (4,2,soma);
    exec (4,2,sub);
    return 0;
}

int soma(int a,int b){
    return a+b;
}
int sub(int a, int b){
    return a-b;
}
void exec (int a, int b, int (*func)(int,int)){
    printf("%d\n",func(a,b));
}
