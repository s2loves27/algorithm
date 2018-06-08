#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int T,n;
int preorder[1001];
int inorder[1001];
int postorder[1001];
int ch = 0;
int f(int start , int end,int ch){
	if(start+1 == end)  {return inorder[start];}
	for(int i = start ; i < end ; i++){
		
			if(preorder[ch] == inorder[i]){
				printf("%d ",f(start,i,start+1));
				printf("%d ",f(i,end,i+1));

				//f(start,i);
				//f(i,end);
				printf("%d ",inorder[i]);
				return 0;
			}
		}
}
void print(){
	for(int i = 0 ; i < n ; i++){
		printf("%d ",postorder[i]);
	}
	printf("\n");
}
int main(){
	scanf("%d",&T);
	for(int i = 0 ; i < T ; i++){
		scanf("%d",&n);
		for(int j = 0 ; j < n ; j++ ){
			scanf("%d",&preorder[j]);
		}
		for(int j = 0 ; j < n ; j++ ){
			scanf("%d",&inorder[j]);
		}
		f(0,n,0);
		//print();
	}
	return 0 ;
}