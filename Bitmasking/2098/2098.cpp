#include <cstdio>
#include <algorithm>
#include <cstring>
#define IMPASSABLE  1000000000;
using namespace std;
int N,W[16][16],dp[16][1<<16];

void input(){
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i ++){
		for(int j = 0 ; j < N ; j++){
			scanf("%d", &W[i][j]);
		}
	}

}
void print(){
	for(int i = 0 ; i < N ; i ++){
		for(int j = 0 ; j < N ; j++){
			printf("%d ",W[i][j]);
		}
		printf("\n");
	}	

}
int f(int cur , int visit){
	//printf("%d",cur);
	if(dp[cur][visit] != -1) return dp[cur][visit];
	if(visit == (1 << N) -1) {
		if(W[cur][0] != 0) return W[cur][0];
		else return IMPASSABLE;
	}
	
		

	int result = IMPASSABLE;
	for(int i = 0 ; i < N ; i++){
		if(W[cur][i] != 0 && !(visit & (1 << i))) result = min(result , f(i,visit|(1 << i)) + W[cur][i]);
	} 

	return dp[cur][visit] = result;
}
int main(){
	memset(W,0,sizeof(W));
	memset(dp,-1,sizeof(dp));
	input();
	printf("%d\n",f(0,1));
	return 0 ;
}