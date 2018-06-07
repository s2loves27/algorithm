#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct Node{
	int left;
	int right;
	int present;
};
int sa[16][2];
int deep(int root , int count);
Node node[10001];
int N;
void input(){
	scanf("%d",&N);
	int temp;
	for(int i = 1 ; i <= N ; i++){
		node[i].present = -1;
	}
	for(int i = 0 ; i <N ;i++){
		scanf("%d",&temp);
		scanf("%d%d",&node[temp].left,&node[temp].right);
		if(node[temp].left != -1)
			node[node[temp].left].present = temp;
		if(node[temp].right != -1)
			node[node[temp].right].present = temp;
	}
	memset(sa,-1,sizeof(sa));
}
int num=1;
int start_1;
int last_1;
void dfs(int root,int lay,int start){

	if(node[root].right != -1) {
		num =1;
		if(node[node[root].right].left != -1) 
			last_1 = start + deep(node[node[root].right].left,1)+1;
		else last_1 = start +1;
		num =1; 
		dfs(node[root].right,lay+1,last_1);
	}
	if(node[root].left != -1) {
		num =1; 
		if(node[node[root].left].right != -1) 
			start_1 = start - deep(node[node[root].left].right,1)-1;
		else start_1 = start -1;
		num =1; 

		dfs(node[root].left,lay+1,start_1);
	}
	
	
	if(sa[lay][0] == -1){
		sa[lay][0] = start;
		sa[lay][1] = start+1;
	}
	else{
		if(start < sa[lay][0]){
			sa[lay][0] = start;
		}
		else if(start > sa[lay][1]) {
			sa[lay][1] = start;
		}
	}
	
}

int deep(int root , int count){
	if(node[root].left != -1) {num++;deep(node[root].left,count+1);}
	if(node[root].right != -1) {num++;deep(node[root].right,count+1);}
	return num;
}
void f(){
	
	int temp;
	int col = -1;
	int area = -1;
	for(int i = 1 ; i < 16 ; i++){
		temp =  sa[i][1] - sa[i][0];
		//printf("%d %d %d\n",i, sa[i][0] , sa[i][1]);
		if(temp > area){
			area = temp;
			col = i;
		}
	}
	printf("%d %d\n",col , area);
}
int find_root(int start){
	if(node[start].present == -1) return start;
	else  find_root(node[start].present);
}
int main(){
	input();
	num = 1;
	dfs(find_root(1),1,N);
	f();
	return 0;
}