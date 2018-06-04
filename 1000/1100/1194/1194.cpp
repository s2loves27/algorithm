#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef struct vi{
	int raw;
	int col;
	int count;
	int key;

}vigit;
int raw_va[4];
int col_va[4];
int N,M;
char map[52][52];
queue<vigit> Q;
bool bit[1<<6][52][52];
void input();
void input(){
	vigit start;
	char temp;
	// N 세로 M 가로
	scanf("%d %d",&N,&M);
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= M ; j++){
			scanf("%c",&temp);
			if(temp != '\n') map[i][j] = temp;
			else j--;
			if(temp == '0') {
				start.raw = i;
				start.col = j;
				start.count = 1;
				start.key = 0;
				Q.push(start);
			}
		}
	}
}
// void print(){
// 	printf("%d %d\n",N,M);
// 	for(int i = 0 ; i < N ; i++){
// 		for(int j = 0 ; j < M ; j++){
// 			printf("%c",map[i][j]);
// 		}
// 		printf("\n");
// 	}
// }
void init(){

	raw_va[0]=1;    col_va[0]=0;   raw_va[1]=0;   col_va[1]=1;
	raw_va[2]=-1;   col_va[2]=0;   raw_va[3]=0;   col_va[3]=-1;

}
int f(){
	vigit temp;
	while(!Q.empty()){
		temp = Q.front();
		Q.pop();
		int raw = temp.raw;
		int col = temp.col;
		int count = temp.count;
		int key = temp.key;
		//printf("%d %d %d\n",raw,col,count);
		for(int i = 0 ; i < 4 ; i++){
			if(!bit[key][raw+raw_va[i]][col+col_va[i]] && map[raw+raw_va[i]][col+col_va[i]] == '1' ){
				//printf("end");
				return count;
			}
			if(!bit[key][raw+raw_va[i]][col+col_va[i]]  && map[raw+raw_va[i]][col+col_va[i]] == '.'){
				bit[key][raw+raw_va[i]][col+col_va[i]]= true;
				temp.raw = raw+raw_va[i];
				temp.col = col+col_va[i];
				temp.count = count+1;
				temp.key = key;
				Q.push(temp);
			}
			if(!bit[key][raw+raw_va[i]][col+col_va[i]] && map[raw+raw_va[i]][col+col_va[i]] == '0'){
				bit[key][raw+raw_va[i]][col+col_va[i]] = true;
				temp.raw = raw+raw_va[i];
				temp.col = col+col_va[i];
				temp.count = count+1;
				temp.key = key;
				Q.push(temp);
			}
			if(!bit[key][raw+raw_va[i]][col+col_va[i]] && map[raw+raw_va[i]][col+col_va[i]] >= 'a' && map[raw+raw_va[i]][col+col_va[i]] <= 'f' ){
				int bit_cal = map[raw+raw_va[i]][col+col_va[i]]-'a';
				bit[key][raw+raw_va[i]][col+col_va[i]] =true;
				temp.raw = raw+raw_va[i];
				temp.col = col+col_va[i];
				temp.count = count+1;
				temp.key = (1<<bit_cal) | key;
				Q.push(temp);
			}
			if(!bit[key][raw+raw_va[i]][col+col_va[i]]  && map[raw+raw_va[i]][col+col_va[i]] >= 'A' && map[raw+raw_va[i]][col+col_va[i]] <= 'F' ){
				int bit_cal = map[raw+raw_va[i]][col+col_va[i]] - 'A';
				//printf("%d %d %d\n",bit_cal,key,count);
				if((key & (1 << bit_cal)) == (1 << bit_cal)){
					bit[key][raw+raw_va[i]][col+col_va[i]] = true;
					temp.raw = raw+raw_va[i];
					temp.col = col+col_va[i];
					temp.count = count+1;
					temp.key = key;
					Q.push(temp);
				}
			}
			
		}


	}

	return 0;
}
int main(){
	memset(bit,false,sizeof(bit));
	memset(map,'2',sizeof(map));
	init();
	input();
	int result = f();
	if(result==0) printf("-1\n");
	else printf("%d\n",result);
	return 0;
}