#include<cstdio>
#include<map>
#include<string>
#include<vector>
#include <cstdlib>

using namespace std;

map<string,int> s1;
char s2[100002][21];
int N,M;
void input(){
	scanf("%d",&N);
	scanf("%d",&M);
	
	//s11.push_back("0");
	for(int i = 1 ; i <= N ; i++){
		scanf("%s",s2[i]);
		s1.insert(pair<char*,int>(s2[i],i));

	}

}
void f(){
	int intValue;
	char temp[20];
	map<string,int>::iterator iter_m;
	for(int i = 0 ; i < M ; i++){
		scanf("%s",temp);
		if(temp[0] >= 'A' && temp[0] <='Z'){
			printf("%d\n",s1.find(temp)->second);
		}
		else{
			intValue =atoi(temp);
			printf("%s\n",s2[intValue]);
		}
	}
}

int main(){
	input();
	f();
	return 0;
}