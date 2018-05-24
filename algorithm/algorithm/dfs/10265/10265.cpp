#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
int N ,K ;
int people[1001];
bool visit[1001],finish[1001];
int result_ch[1001];
int result_cnt[1001];
int max_cnt=0;
int temp;
int ch;
int cnt;
int result[1001];

int dfs(int curr){
	cnt = 0;
	ch ++;
	visit[curr] = true;
	int next = people[curr];
	if(visit[next]){
		if(!finish[next]){
			for(int i = next ; i != curr ; i = people[i]) cnt++;
			cnt++; 
		}
	}
	else dfs(next);
	
	finish[curr] = true;
	
	return 0;
}
int dp(int curr){
	if(curr <= 0) return 0;
	if(result[curr] != -1) return result[curr];
	
	
}
int main(){
	scanf("%d%d",&N,&K);
	temp = K;
	for(int i = 1 ; i <= N;i++){
		scanf("%d",&people[i]);
	}
	fill(visit,visit+N+1,false);
	fill(finish,finish+N+1,false);
	fill(result,result+N+1,-1);
	for(int i = 1 ; i <= N ;i++){
		fill(visit,visit+N+1,false);
		fill(finish,finish+N+1,false);
		ch = 0;
		if(!visit[i]) {

			dfs(i);
			result_ch[i] = ch;
			result_cnt[i] = cnt;
		}
		
	}
	dp(12);
	for (int i = 0 ; i <= N; i++){
		printf("%d,%d,%d\n",result_cnt[i] , result_ch[i],result[i]);
	}

	return 0 ;
}
