#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
struct Node{
	int left;
	int right;
};

vector<int> layer[16]; 
Node node[10001];
int N;
void input(){
	scanf("%d",&N);
	for(int i = 0 ; i <N ;i++){
		int temp;
		scanf("%d",&temp);
		scanf("%d%d",&node[temp].left,&node[temp].right);
	}
}
void print(){

	for(int i = 1 ; i <N ;i++){
		printf("%d %d\n",node[i].left,node[i].right);
	}
}
int dfs(int root,int lay,int count){
	if(node[root].left != -1) dfs(node[root].left,lay+1,count-1);
	if(node[root].right != -1) dfs(node[root].right,lay+1,count+1);
	layer[lay].push_back(count);
	printf("root = %d lay = %d count = %d\n",root,lay,count);
	return count;
}
int num=0;
int deep(int root , int count){
	if(node[root].left != -1) {num++;deep(node[root].left,count+1);}
	if(node[root].right != -1) {num++;deep(node[root].right,count+1);}
	return num;
}

int main(){
	input();
	//print();
	//dfs(1,1,10);
	deep(1,0);
	printf("%d\n",num);
	// deep(2,0);
	// printf("%d\n",num);
	// deep(3,0);
	// printf("%d\n",num);
	return 0;
}