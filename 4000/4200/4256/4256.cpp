#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int T,n;
int preorder[1001];
int inorder[1001];
int inpos[1001];
int ch = 0;
void f(int start , int end){
	if(start == end)  {return;}
	int root = preorder[ch++];
	int i = inpos[root];
	f(start,i);
	f(i+1,end);
	printf("%d ",root+1);		

}

int main(){
	scanf("%d",&T);
	for(int i = 0 ; i < T ; i++){
		ch = 0;
		scanf("%d",&n);
		for(int j = 0 ; j < n ; j++ ){
			scanf("%d",&preorder[j]);
			preorder[j]--;
		}
		for(int j = 0 ; j < n ; j++ ){
			scanf("%d",&inorder[j]);
			inorder[j]--;
			inpos[inorder[j]] = j; 
		}
		f(0,n);
		printf("\n");
	}
	return 0 ;
}