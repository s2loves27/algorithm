#include <cstdio>
#include <algorithm>
#include <string.h>
#include <vector>
#define NUM 10000000
using namespace std;
struct Node{
	int val;
	int left;
	int right;
};
Node node;
vector<vector<Node>> tree;
int n,k;
int key[301];
void input(){
	scanf("%d",&n);
	scanf("%d",&k);
	tree.resize(k);
	for(int i = 0 ; i < k ;i++){
		scanf("%d",&key[i]);
	}
	sort(key,key+k);
}
void f(){

}
int make_tree(int root){
	
}
int main(){
	input();
	for(int i = 0 ; i < k; i++)
		tree[i].push_back()
		make_tree(key[i]);
	f();
	return 0;
}