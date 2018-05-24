#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
int N;
int horse[100000];
bool value = false;
bool finish = false;
void input(){
	scanf("%d",&N);
	for(int i = 1 ; i <= N ; i ++) horse[i] = 1;
}
int backtracking(int x){
	int i=0, j=0;
	if(finish) return 0;
	if(N+1 == x) {
		for(int i = 1 ; i <= N ; i++) printf("%d\n",horse[i]);
		finish = true;
		return 0;
	}
	for(i = 1 ; i <= N ; i++){
		value = false;
		for(j = 1 ; j <= x-1 ; j++){
		
				if(i - j == horse[x-j] || i == horse[x-j] || i + j == horse[x-j]) {
					value = true;
					break;
				} 
			

		}
		if(!value){
			
			horse[x] = i;
			//printf("%d %d %d\n", i , j,horse[i]);
			backtracking(x+1);
			//horse[x] = 1;
		}
	}
}
int main(){
	input();
	backtracking(1);
	//for(int i = 1 ; i <= N ; i++) printf("%d\n",horse[i]);
	return 0;
}