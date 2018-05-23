#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
const long long simul = 1000000000;
long long num[101][10];

long long f(int c,int digit){
	if(c == 0) return 0;
	if(c == 1) return num[c][digit] = 1;
	if(num[c][digit] != -1) return num[c][digit] % simul;
	if(digit == 0)
		return num[c][digit] = f(c-1,digit+1);
	else if(digit == 9)
		return num[c][digit] = f(c-1,digit-1);
	else return num[c][digit] = f(c-1,digit+1) + f(c-1,digit-1);
}
int main(){
	int N;
	long long sum = 0;
	for(int i = 0 ; i < 10 ; i++)
		for(int j = 0 ; j <= 100 ; j++)
			num[j][i] = -1;
	scanf("%d",&N);
	for(int i = 0 ; i < 10 ; i++) f(N,i);

	for(int i = 1 ; i < 10 ; i++) sum+= num[N][i];

	printf("%lld",sum%simul);
}