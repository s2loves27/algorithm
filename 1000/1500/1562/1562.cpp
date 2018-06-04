#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstring>
using namespace std;
#define MAX 1000000000
int N;
long long dp[10][100][1<<10];
int co = 0;
long long f(int cur,int pos,int visited){
	if(pos+1 == N){
		visited = visited | (1 << cur);
		if(visited == (1 << 10)-1) {return 1;}
		else return 0;
		return 1;
	} 
	long long value;
	if(dp[cur][pos][visited] != -1) return dp[cur][pos][visited];
	if(cur == 0) value = f(cur+1,pos+1,visited | (1 << cur))%MAX ;
	else if(cur == 9)  value = f(cur-1,pos+1,visited | (1 << cur))%MAX ;
	else value = f(cur+1,pos+1,visited | (1 << cur))%MAX + f(cur-1,pos+1,visited | (1 << cur))%MAX;
	return dp[cur][pos][visited] = value%MAX;
	
}
int main(){
	
	long long aa = 0;
	scanf("%d",&N);
	long long result=0;
	long long te=0;
	for(int i = 1 ; i < 10 ; i++){
	memset(dp , -1 , sizeof(dp));
	long long temp = f(i,0,0);
	result += temp;
	}
	result %= MAX;
	printf("%u",result); 
	return 0;
}