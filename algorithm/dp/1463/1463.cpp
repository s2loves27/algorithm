#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
int a[1000001];

int find_1(int N){
	if(N == 1){
		return 0;
	}
	if(a[N] != -1) return a[N];
	int result = find_1(N-1)+1;
	if(N%2 == 0){
		result = min(result , find_1(N/2)+1);
	}
	if(N%3 == 0){
		result = min(result, find_1(N/3)+1);
	}
	return a[N] = result;

	
	
}


int main(){
	int N;
	scanf("%d",&N);
	fill(a,a+1000001,-1);
	printf("%d\n",find_1(N));
}
