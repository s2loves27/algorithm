#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct tree_node{
	int parent;
	int left;
	int right;
};

int N;
char tree_value[36][3];
vector<vector<int>> graph;
vector<tree_node> tree;
int vigited[36];
void input(){
	char temp;
	scanf("%d",&N);
	graph.resize(N);
	tree.resize(N);
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < 3 ; j++){
			scanf("%c",&temp);
			if(temp == ' ') j--;
			else if(temp == '\n')j--;
			else tree_value[i][j] = temp;
		}
	}

}
void make_tree(){
	for(int i = 0 ; i < N ; i++){
		if(tree_value[i][1] != '.') tree[tree_value[i][0] - 'A'].left = tree_value[i][1] - 'A';
		else if(tree_value[i][1] == '.') tree[tree_value[i][0] - 'A'].left = -1;
		if(tree_value[i][2] != '.') tree[tree_value[i][0] - 'A'].right = tree_value[i][2] - 'A';
		else if(tree_value[i][2] == '.') tree[tree_value[i][0] - 'A'].right = -1;
		if(tree_value[i][1] != '.') tree[tree_value[i][1] - 'A'].parent = tree_value[i][0] - 'A';
		if(tree_value[i][2] != '.') tree[tree_value[i][2] - 'A'].parent = tree_value[i][0] - 'A';
	}
}

void print_tree(){
	for(int i = 0 ; i < N ; i++){
		printf("Node = %c" ,'A' +i);
		if(tree[i].parent != -1)
			printf("parent Node = %c",'A' +tree[i].parent);
		printf("children Node = (");
		if(tree[i].left != -1)
		printf("%c",'A' +tree[i].left);
		if(tree[i].right != -1)
		printf("%c",'A' +tree[i].right);
		printf(")\n");
	}
}
void preorder(int start){
	printf("%c",'A' + start);
	vigited[start] =1;
	for(int j = 0 ; j < 2;j++)
	if(tree[start].left != -1 && !vigited[tree[start].left])
		preorder(tree[start].left);
	if(tree[start].right != -1 && !vigited[tree[start].right])
		preorder(tree[start].right);
}
void inorder(int start){
	vigited[start] =1;
	if(tree[start].left != -1 && !vigited[tree[start].left])
		inorder(tree[start].left);
	printf("%c",'A' + start);
	if(tree[start].right != -1 && !vigited[tree[start].right])
		inorder(tree[start].right);
}
void postorder(int start){
	vigited[start] =1;
	if(tree[start].left != -1 && !vigited[tree[start].left])
		postorder(tree[start].left);
	if(tree[start].right != -1 && !vigited[tree[start].right])
		postorder(tree[start].right);
	printf("%c",'A' + start);

}

int main(){memset(vigited,0,sizeof(vigited));
	input();
	make_tree();
	//print_tree();
	memset(vigited,0,sizeof(vigited));
	preorder(0);
	printf("\n");
	memset(vigited,0,sizeof(vigited));
	inorder(0);
	printf("\n");
	memset(vigited,0,sizeof(vigited));
	postorder(0);
	return 0;
}
