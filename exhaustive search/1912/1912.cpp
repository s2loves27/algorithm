//완전 탐색 1912
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	int a;
	int r_max = -1;
	int c1[100001];
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d",&c1[i]);
	}
	r_max = c1[0];
	for(int i = 0 ; i < n-1 ; i ++){
		if(c1[i+1] < c1[i+1] + c1[i]) c1[i+1] = c1[i+1] + c1[i];
		if(r_max < c1[i+1]) r_max = c1[i+1];

	}
	if(r_max <= -1){

		sort(c1,c1+n);
		r_max = c1[n-1];
	}
	printf("%d",r_max);
	return 0;
}
