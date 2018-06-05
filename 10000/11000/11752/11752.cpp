#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define NUM 100000
using namespace std;
struct tree_value{
	int parent;
	vector<int> children;
};
int N;
vector<vector<int>> graph;
int vigited[NUM+1];
vector<tree_value> tree;
void input(){
	int temp_1,temp_2;
	scanf("%d",&N);
	graph.resize(N+1);
	tree.resize(N+1);
	for(int i = 0 ; i < N ; i++){
		scanf("%d%d",&temp_1,&temp_2);

		vigited[i+1] = 0;
		graph[temp_1].push_back(temp_2);
		graph[temp_2].push_back(temp_1);
	}

}
void make_tree(int root){
	vigited[root] = 1;
	for(int i = 0 ; i < graph[root].size() ; i++){
		if(!vigited[graph[root][i]]){
			tree[root].children.push_back(graph[root][i]);
			tree[graph[root][i]].parent = root; 
			make_tree(graph[root][i]);
		}
	}
}
void print(){
	for(int i = 2; i <= N ; i++){
		printf("%d\n",tree[i].parent);
	}
}

int main(){
	input();
	make_tree(1);
	print();
	return 0;
}
