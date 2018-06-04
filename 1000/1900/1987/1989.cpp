#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;
int R,C;
char knite[22][22];
bool vowel[27];
int max_result = 0;
void input(){
	char ch;
	scanf("%d%d",&R,&C);
	for(int i = 0 ; i < 'Z' - 'A' +1; i++){
		vowel[i] = 0; 
	}
	vowel[26] =1;
	for(int i = 0 ; i <= R+1; i++){
		for(int j = 0 ; j <= C+1 ; j++){
		knite[i][j] = 91;
		}
	}
	for(int i = 1 ; i <= R; i++){
		for(int j = 1 ; j <= C ; j++){
			scanf("%c",&ch);
			if(ch == '\n') j--;
			knite[i][j] =ch;
			}
	}
}
int backtraking(int x, int y,int num){
	if(!vowel[knite[x+1][y] - 'A']){
		vowel[knite[x+1][y] - 'A'] = 1;
		backtraking(x+1,y,num+1);
		vowel[knite[x+1][y] - 'A'] = 0;
	}
	if(!vowel[knite[x-1][y] - 'A']){
		vowel[knite[x-1][y] - 'A'] = 1;
		backtraking(x-1,y,num+1);
		vowel[knite[x-1][y] - 'A'] = 0;
	}
	if(!vowel[knite[x][y+1] - 'A']){
		vowel[knite[x][y+1] - 'A'] = 1;
		backtraking(x,y+1,num+1);
		vowel[knite[x][y+1] - 'A'] = 0;
	}
	if(!vowel[knite[x][y-1] - 'A']){
		vowel[knite[x][y-1] - 'A'] = 1;
		backtraking(x,y-1,num+1);
		vowel[knite[x][y-1] - 'A'] = 0;
	}	
	if(max_result < num) max_result = num;
}
int main(){
	input();
	vowel[knite[1][1] - 'A'] = 1;
	backtraking(1,1,1);
	printf("%d\n",max_result);
	return 0;
}