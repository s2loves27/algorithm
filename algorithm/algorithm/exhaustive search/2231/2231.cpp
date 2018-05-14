//완전 탐색 2231
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
int main(){
	
	int n;
	int init;
	int ch;
	int i;
	int max = 0;
	scanf("%d",&n);
	for(i = 1 ; i < n ; i++){
		max = 0;
		ch = i;
		init = i;
		while(ch!=0){
			max+=ch % 10;
			ch = ch/10;
		}
		max += init;
		if(max == n)
		{
			break;
		}
	}

	if(i == n){
		printf("0");
	}
	else{
		printf("%d",i);
	}
	return 0;
}