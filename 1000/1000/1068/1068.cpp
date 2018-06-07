//경우는 



#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
struct node{
	int parent;
	vector<int> children;
};
int co = 0;
int N,del;
int root;
node tree[51];
int vigited[51];
void input(){
	int temp;
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++){
		vigited[i] = 0;
		scanf("%d",&temp);
		if(temp == -1) { root = i;continue;}
		else {
			tree[i].parent = temp;
			tree[temp].children.push_back(i);
		}

	}
	scanf("%d",&del);
}
int count_leaf(int root){
	vigited[root] =1;
	int count = 0;
	if(root == del) return 0;
	for(int i = 0 ; i < tree[root].children.size(); i++){
		if(!vigited[tree[root].children[i]] && tree[root].children[i] != del){
			count_leaf(tree[root].children[i]);
			count++;
		}
	}
	if(count == 0) co++;
}

int main(){
	memset(vigited,0,sizeof(vigited));
	input();
	count_leaf(root);
	printf("%d\n",co);
	return 0;
}