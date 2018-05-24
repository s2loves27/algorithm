#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int T;
int Sudoku[9][9] = {0};
int vigited[10] = {0};
void input(){
	for(int i = 0 ; i < 9 ;i ++)
		for(int j = 0 ; j < 9 ; j++)
			scanf("%d",&Sudoku[i][j]);
}
int f(){
	int co;
	for(int i = 0 ; i < 9 ; i++){
		co = 0;
		memset(vigited,0,sizeof(int) * 10);
		for(int j = 0 ; j < 9 ; j++){
			if(!vigited[Sudoku[i][j]]){
				co++;
				vigited[Sudoku[i][j]] = 1;
			} 
		}
		if(co != 9) return 0;
	}
	
	for(int i = 0 ; i < 9 ; i++){
		co = 0;
		memset(vigited,0,sizeof(int) * 10);
		for(int j = 0 ; j < 9 ; j++){
			if(!vigited[Sudoku[j][i]]){
				co++;
				vigited[Sudoku[j][i]] = 1;
			} 
		}
		if(co != 9) return 0;
	}
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			co =0;
			memset(vigited,0,sizeof(int) * 10);
			for(int ii = i*3 ; ii < i*3 +3 ; ii++ ){
				for(int jj = j*3 ; jj < j*3 +3 ; jj++){
					if(!vigited[Sudoku[ii][jj]]){
						co++;
						vigited[Sudoku[ii][jj]] = 1;
						} 
				}
			}
		if(co != 9) return 0;

		}
	}
	return 1;

}

void print(){
	for(int i = 0 ; i < 9 ;i ++){
		for(int j = 0 ; j < 9 ; j++){
			printf("%d ",Sudoku[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main(){
	scanf("%d",&T);
	for(int i = 0 ; i < T ; i++){
		input();
		int a = f();
		//print();
		if(a) printf("Case %d: CORRECT\n",i+1);
		else printf("Case %d: INCORRECT\n",i+1);
	}
	return 0;
}