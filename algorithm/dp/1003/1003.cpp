#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>

using namespace std;
int count_0=0, count_1=0;
int count_b0[42], count_b1[42];
int fibonacci(int n){
	if(n == 0 ){
		count_0++;
		count_b0[n] = count_0;
		count_b1[n] = count_1;
		
		return 1;
	}else if(n == 1){
		count_1++;
		count_b0[n] = count_0;
		count_b1[n] = count_1;
		
		return 0;
	}
	 else if(count_b0[n] != -1){
		count_0 += count_b0[n];
		count_1 += count_b1[n];
		return 2;
	}
	else {

		fibonacci(n-1);
		fibonacci(n-2);
		count_b0[n] = count_0;
		count_b1[n] = count_1;
	}
}

int main(){
	int T;
	int a;
	int b;
	int N;
	scanf("%d",&T);
	for(int i = 0 ; i < 41 ; i++){
		count_b0[i] = -1;
		count_b1[i] = -1;
	}
	for(int i = 0 ; i < T ; i++){
		count_0 = 0;
		count_1 = 0;
		scanf("%d",&N);
		fibonacci(N);
		printf("%d %d\n",count_b0[N],count_b1[N]);
	}

	return 0;
}