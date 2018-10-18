#include <iostream>

using namespace std;
int N,M;
int map[102][102];
int vigit[102];
int result;

void f1(){
	bool flag = true;
	int cnt = 0;
	for(int i = 1 ; i <= N ; i++){
		flag = true;
		cnt = 1;
		for(int j = 1 ; j < N ; j++ ){
			// 이전과 같다.
			if(map[i][j+1] == map[i][j]){
				cnt++;
			}
			// 1크다.
			if(map[i][j+1] - map[i][j] == 1){
				if(cnt >= M) cnt = 1;
				else { flag = false; break;}
			}
			// 1작다.
			if(map[i][j+1] - map[i][j] == -1){
				for(int z = j + 1 ; z < j + M ; z++){
					if(z> N) {flag = false; break;}
					if(map[i][z] != map[i][z+1]){
						flag = false;
						break;
					}

				}
				if(flag == true){j += M-1; cnt = 0; continue;}
			}

			// 1이상크다
			if(abs(map[i][j+1] - map[i][j]) > 1){

				flag = false;
				break;
			}
			if(flag == false) break;

		}
		if(flag == true) {result++;}
	}
}
void f2(){
	bool flag = true;
	int cnt = 0;
	for(int j = 1 ; j <= N ; j++){
		flag = true;
		cnt = 1;
		for(int i = 1 ; i < N ; i++ ){
			// 이전과 같다.
			if(map[i+1][j] == map[i][j]){
				cnt++;
			}
			// 1크다.
			if(map[i+1][j] - map[i][j] == 1){
				if(cnt >= M) cnt = 1;
				else { flag = false; break;}
			}
			// 1작다.
			if(map[i+1][j] - map[i][j] == -1){
				for(int z = i + 1 ; z < i + M ; z++){
					if(z > N) {flag = false; break;}
					if(map[z][j] != map[z+1][j]){
						flag = false;
						break;
					}

				}
				if(flag == true){i += M-1; cnt = 0; continue;}
			}

			// 1이상크다
			if(abs(map[i+1][j] - map[i][j]) > 1){

				flag = false;
				break;
			}
			if(flag == false) break;

		}
		if(flag == true) {result++;}
	}
}


int main(){
	scanf("%d %d",&N,&M);
	for(int i = 0 ; i <= N+1 ; i++){
		for(int j = 0 ; j <= N+1 ; j++){
			map[i][j] = -1;
		}
	}
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			scanf("%d",&map[i+1][j+1]);
		}
	}

	f1();
	f2();
	printf("%d\n",result);
	return 0;
}