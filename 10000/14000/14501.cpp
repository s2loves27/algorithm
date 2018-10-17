#include <iostream>

using namespace std;
int N;
int T[16];
int P[16];
int dp[16];
int max(int a, int b){
	if(a>=b) return a;
	else return b;
}

int f(int k){
	if(k >= N) return 0;
	if(dp[k] != 0) return dp[k];
	int result = 0;
	for(int i = 1 ; i < N ; i++)
		result = max(result ,f(k+i));
	
	if(k + T[k] <= N)
		result = max(result , f(k+T[k]) + P[k]);
	

	return dp[k] = result;
}

int main(){
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++){
		scanf("%d %d",&T[i],&P[i]);
	}
	printf("%d\n",f(0));


	return 0;
}