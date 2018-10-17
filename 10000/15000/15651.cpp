#include <iostream>

using namespace std;

int N,M;
int arr[8];
void f(int m, int k){
	
	if(m == M) {
		for(int i = 0 ; i < M ; i++){
			printf("%d ",arr[i]+1);
		}
		printf("\n"); return;}
	if(k == N) return;
	for(int i = k ; i < N ; i ++){
			
			arr[m] = i;
			f(m+1, i);
			
	}
	return;
}

int main(){
	scanf("%d %d",&N,&M);
	f(0,0);

	return 0;
}