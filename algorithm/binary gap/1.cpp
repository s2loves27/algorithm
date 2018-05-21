// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <algorithm>
#include <cstdio>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;
int solution(int N) {
    int max = 0;
    int c_max = 0;
    while(N != 1){
        if(N%2 == 1) c_max =0;
        else if(N%2 == 0) c_max+=1;
        if(c_max > max) max = c_max;
        N = N/2;
    }
    // write your code in C++14 (g++ 6.2.0)
    printf("%d",max);
    return 0;
}
int main(){
    int N;
    scanf("%d",&N);
    solution(N);
}