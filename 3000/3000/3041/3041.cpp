#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
char alpha[4][4];
void input(){
	char temp;
	for(int i = 0 ; i < 4 ; i++){
		for(int j = 0 ; j < 4 ; j++){
			scanf("%c",&temp);
			if(temp != '\n') alpha[i][j] = temp;
			else j--;  
		}
	}
}
int f(){
	int count = 0;
	for(int i = 0 ; i < 4 ; i++){
		for(int j = 0 ; j < 4 ; j++){
			int num;
			if(alpha[i][j] == '.') continue;
			num = alpha[i][j] - 'A';
			int a1 = abs((num / 4) - ((4*i + j)/4));
			int a2 = abs((num % 4) - ((4*i + j)%4));
			count += a1 + a2;
			//printf("%d\n",a1+a2);
		}
	}
	return count;
}
int main(){
	input();
	printf("%d\n",f());
	return 0;
}