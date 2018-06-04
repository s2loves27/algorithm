#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
char n[101];
char m[101];
int jump[101];
int jump_ch[101];
int n_size = 0;
int m_size = 0;
vector<int> result;
void input(){
	char ch;
	while(1){
		scanf("%c",&ch);
		if(ch == '\n' || ch == '\0') break;
		n[n_size++] = ch;
	}
	while(1){
		int i = scanf("%c",&ch);
		if(i == -1) break;
		m[m_size++] = ch;
	}
	for(int i = 0 ; i < m_size ; i++) {jump[i] = 1;jump_ch[i] =0;}
}
void print(){
	printf("%d\n",result.size());
	for(int i = 0 ; i < result.size();i++) printf("%d",result[i]);
}
int f(){
	//jump[0] = 1;
	int a = 1;
	for(int i = 1 ; i < m_size ; i++){
		if(m[0] == m[i]){
			jump[i] = a;
			jump_ch[i] = 1;
			for(int j = 1 ; j < m_size - i + 1 ; j++ ){
				if(m[j] == m[i+j]){
					jump[i+j] = i;
					jump_ch[i+j] = j+1;  
				} 
				else {a++; break;};
			}
		}
		else jump[i] = ++a;
	}
	int n_count=0;
	int i = 0;
	int next = 0;
	while(n_count-m_size+1 < n_size){
		for(i = next ; i < m_size ; i++){
			if(m[i] == n[i+n_count]){
			}
			else break;
		}
		if(i == 0) {n_count += 1; next = 0;}
		else if(i == m_size) {
			result.push_back(n_count+1);
			n_count+=jump[i-1];
			next = jump_ch[i-1];
			}
		else {
			n_count+=jump[i-1];
			next = jump_ch[i-1];
		}
	}
	//printf("%d\n",a);
}
int main(){
	input();
	f();
	print();
	return 0 ;
}