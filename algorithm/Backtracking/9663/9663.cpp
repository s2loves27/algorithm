#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
int N;
int horse[16];
bool visited[16];
bool value = false;
bool finish = false;
int co = 0;
queue<int> a;
void input(){
	scanf("%d",&N);
	for(int i = 1 ; i <= N ; i ++) {horse[i] = 0; a.push(i);}
}
int backtracking(int x){
	//printf("%d\n",co++);
	int i=0, j=0;

	if(N+1 == x) {
		//for(int i = 1 ; i <= N ; i++) printf("%d\n",horse[i]);
		co++;
		return 0;
	}
	for(int z = 0 ; z < a.size() ; z++){
		int i = a.front();
		a.pop();
		value = false;
		for(j = 1 ; j <= x-1 ; j++){
		if(finish) return 0; 
				if(i - j == horse[x-j] || i == horse[x-j] || i + j == horse[x-j]) {
					value = true;
					break;
				}
				
		}
		if(!value){
			//printf("%d %d %d\n",x,i,co++);
			horse[x] = i;
			backtracking(x+1);
			a.push(i);
		
			
		}else a.push(i);

	}
}
int main(){
	input();
	backtracking(1);
	printf("%d\n",co);
	return 0;
}