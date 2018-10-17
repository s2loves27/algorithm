#include <iostream>

using namespace std;

int N,M;
int ch[10];
int arr[8];
void f(int m){
	
	if(m == M) {
		for(int i = 0 ; i < M ; i++){
			printf("%d ",arr[i]);
		}
		printf("\n"); return;}
	for(int i = 1 ; i <= N ; i ++){
		if(ch[i]){
			ch[i] = 0;
			arr[m] = i;
			f(m+1);
			arr[m] = 0;
			ch[i] = 1;
		}
	}
	return;
}

int main(){
	scanf("%d %d",&N,&M);
	for(int i = 0 ; i < 8 ; i ++){
		ch[i+1] = 1;
	}
	f(0);

	return 0;
}