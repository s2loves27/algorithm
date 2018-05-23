#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int L,C;
char letter[15];
char temp[16];

void input(){
	char ch;
	scanf("%d%d",&L,&C);
	for(int i = 0 ; i < C ; i++) {
		scanf("%c",&ch);
		if(ch == '\n') i--;
		else if(ch == ' ') i--;
		else letter[i] = ch; 
	}

}
int backtracking(int location,int prev,int ja,int mo){
	if(location > C) return 0;
	if(ja+mo == L) {
		if(ja >= 2 && mo >= 1){
			for(int i = 0 ; i < L ; i++){
				printf("%c",temp[i]);
			}
			printf("\n");
			return 0;
		}
	}

	for(int i = prev+1 ; i < C ; i++){
		temp[location] = letter[i];
		if((letter[i] == 'a') || (letter[i] == 'e') || (letter[i] == 'i' )|| (letter[i] == 'o') || (letter[i] == 'u')  )
			backtracking(location+1,i,ja,mo+1);
		else backtracking(location+1,i,ja+1,mo);
	}
}
int main(){
	input();
	sort(letter, letter+C);
	backtracking(0,-1,0,0);
	return 0;
}