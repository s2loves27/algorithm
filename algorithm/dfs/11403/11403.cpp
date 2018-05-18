#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<iostream>

using namespace std;
int N;
vector<int> graph_list[100];
vector<int> result[100];
bool visited[100];
void dfs(int start,int curr){

	visited[curr] = true;
	
	for(int i =0; i < graph_list[curr].size(); i++){
		result[start][graph_list[curr][i]] = 1;
		if(!visited[graph_list[curr][i]]){
			dfs(start,graph_list[curr][i]);
		}
	}
}
int main(){
	scanf("%d",&N);
	int a;

	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j< N ; j++){

			scanf("%d",&a);
			if(a == 1)
			graph_list[i].push_back(j);
			result[i].push_back(0);
		}
	}

	for(int i = 0 ; i < N ; i++){
		fill(visited,visited+100,false);
		dfs(i,i);
	}
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			printf("%d ",result[i][j]);
		}
		printf("\n");
	}
	return 0;
}