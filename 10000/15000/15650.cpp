#include <iostream>

using namespace std;

int N,M;
int ch[10];
int check[10];
int arr[8];
void f(int m, int n){
	if(m == M) {
		for(int i = 0 ; i < M ; i++){
			printf("%d ",arr[i]+1);
		}
		printf("\n"); return;}
	if(n == N) return ;
	for(int i = n; i < N ; i ++){
	
		if(ch[i]){
			ch[i] = 0;
			arr[m] = i;
			f(m+1,i+1);
			ch[i] = 1;
			
		}
	}
}

int main(){
	scanf("%d %d",&N,&M);
	for(int i = 0 ; i < 8 ; i ++){
		ch[i] = 1;
		check[i] = 1;
	}
	f(0,0);

	return 0;
}