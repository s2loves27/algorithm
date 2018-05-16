#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;
int p[1001];
int result[1001];
int N;
int f(int co){
	if(co <= 0) return 0;
	if(result[co] != -1) return result[co];
	int temp = co;
	int res = f(co - 1) + p[1];
	for(int i = 2 ; i <= co ; i ++)
		res = max(f(co - i)+p[i],res);
	return result[co] = res;
}

int main(){
	
	fill(result,result+1001,-1);
	scanf("%d",&N);
	for(int i = 1 ; i <= N ; i++){
		scanf("%d",&p[i]);
	}
	
	
	printf("%d\n",f(N));
	for(int i = 1 ; i <= N ; i++){
		printf("%d\n",result[i]);
	}
	return 0;

}