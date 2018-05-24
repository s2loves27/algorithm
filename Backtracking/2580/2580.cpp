#include <cstdio>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;
struct zero_point{
	int x;
	int y;
};
void print();
int Sudoku[9][9] = {0};
stack<zero_point> zero;
zero_point temp;
bool is_value = false;
int raw,col,box_raw,box_col,i;
bool finish =false;
void input(){
	int x;
	for(int i = 0 ; i < 9 ; i ++){
		for(int j = 0 ; j < 9 ; j++){
			scanf("%d",&x);
			if(x == 0){
				temp.x = i;
				temp.y = j;
				zero.push(temp);
			}
			Sudoku[i][j] = x;
		}
	}

}
int co = 0;
int backtracking(int x){
	
	if(zero.empty()){
		print();
		finish = true;
		return 0;
	} 
	zero_point temp_1;
	temp_1 = zero.top();
	
	for(int i = 1 ; i < 10 ; i ++){
		is_value = false;
		for(raw = 0 ; raw < 9 ; raw ++){
			if(Sudoku[temp_1.x][raw] == i){
				is_value = true;
				break;
			}
		}
		if(is_value) continue;
		for(col = 0 ; col < 9 ; col++){
			if(Sudoku[col][temp_1.y] == i){
				is_value = true;
				break;
			}
		}
		if(is_value) continue;
		for(box_raw = 3*(temp_1.x/3) ; box_raw < 3*(temp_1.x/3) + 3 ; box_raw++){
			for(box_col = 3*(temp_1.y/3) ; box_col < 3*(temp_1.y/3) + 3 ; box_col++){
				if(Sudoku[box_raw][box_col] == i){
					is_value = true;
					break;
				}
			}
		}
		if(is_value) continue;
		if((raw == 9) && (col == 9) && !is_value){
			
			zero.pop();
			Sudoku[temp_1.x][temp_1.y] = i;
			backtracking(x+1);
			if(finish) return 0;
			zero.push(temp_1);
			Sudoku[temp_1.x][temp_1.y] = 0;

		}

	}


}
void print(){
	for(int i = 0 ; i < 9; i++){
		for(int j = 0 ; j < 9 ; j ++){
			printf("%d ",Sudoku[i][j]);
		}
		printf("\n");
	}
}
int main(){
	input();
	backtracking(0);
	//print();
	return 0;
}