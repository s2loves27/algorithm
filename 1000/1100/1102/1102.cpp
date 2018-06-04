#include <cstdio>
#include <algorithm>
#include <cstring>
#define IMPASSIBLE 1000000000
using namespace std;

int N,P;
int fac[16][16];
int dp[1<<16];
bool can_visit[1<<16];
char state[16];
void input(){
	char a;
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			scanf("%d",&fac[i][j]);
		}
	}
	for(int i = 0 ; i < N ; i++){
		scanf("%c",&a);
		if(a != '\n') state[i] = a;
		else i--;
	}
	scanf("%d",&P);
}
void print(){
	printf("%d\n",N);
	for(int i = 0 ; i < N ; i ++){
		for(int j = 0 ; j < N ; j++){
			printf("%d ",fac[i][j]);
		}
		printf("\n");
	}
	for(int i = 0 ; i < N ; i++){
		printf("%c",state[i]);
	}
	printf("\n");
	printf("%d\n",P);

}
int f(int cur , int visited , int num){
	if(num >= P) return 0;
	if(dp[visited] != -1) return dp[visited];
	int result = IMPASSIBLE;
	for(int i = 0 ; i < N ; i++){
		if(state[i] == 'Y'){

			for(int j = 0 ; j < N ; j++){
				if(((visited & (1 << j)) == 0 )&& (i != j) && (state[j] == 'N')){
					state[j] = 'Y';
					result = min(result , f(j,visited | (1 << j) ,num+1) + fac[i][j]);
					state[j] = 'N';
				}
			}	
		}
	} 
	return dp[visited] = result;
}
void init(){
	for(int i = 0 ; i < N ; i++) if(state[i] == 'Y') P--;
}
int main(){
	memset(dp,-1,sizeof(dp));
	input();
	init();
	int reuslt = f(0,0,0);
	if(reuslt == IMPASSIBLE) printf("-1\n");
	else printf("%d\n",reuslt);
	return 0;
}