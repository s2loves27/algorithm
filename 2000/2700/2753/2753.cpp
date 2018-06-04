#include <cstdio>
using namespace std;
int N;
void input(){
	scanf("%d",&N);
}
int f(){
	if(!(N % 400)) return 1;
	if(!(N % 100)) return 0;
	if(!(N % 4)) return 1;
	return 0;
}
int main() {
	input();
	printf("%d",f());
	return 0;
}