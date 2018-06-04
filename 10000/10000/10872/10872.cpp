//시간 복잡도 10872

#include<stdio.h>
#include<iostream>
using namespace std;
//공간 복잡도 생각 안함.
// int main(){
//     int N,X;
//     int A[10000];
//     scanf("%d %d",&N,&X);
//     for(int i = 0 ; i < N ; i ++){
//         scanf("%d",&A[i]);
//     }
//     for(int i = 0 ; i < N ; i ++){
//         if(A[i] < X){
//             printf("%d",A[i]);
//             printf(" ");
//         }
//     }

// }
//공간 복잡도 생각함
int main(){
    int N,X,A;
    scanf("%d %d",&N,&X);
    for(int i = 0 ; i < N ; i ++){
        scanf("%d",&A);
        if(A < X){
        	printf("%d ",A);
        }
    }


}