#include<cmath>
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,cnt;
int graph_list[100000];
bool visited[100000],finish[100000];
void dfs(int curr){
	visited[curr] = true;
	int next = graph_list[curr];
	if(visited[next]){
		if(!finish[next]){
			for(int temp = next ; temp !=curr ; temp = graph_list[temp]) cnt++;
			cnt++;
		}
	}
	else dfs(next);
	finish[curr] = true;
}

int main(){
	scanf("%d",&T);
	int va;
	for(int i = 0 ; i < T ; i++){
		cnt =0;
		scanf("%d",&N);
		for(int i = 0 ; i < N ; i++){
		scanf("%d",&graph_list[i]);
		graph_list[i]--;
		}
		fill(visited , visited + N , false);
		fill(finish , finish + N , false);
		for(int i = 0 ; i < N ; i++)
			if(visited[i] == false) dfs(i);
		printf("%d\n" , N - cnt);
	}

	return 0;
}