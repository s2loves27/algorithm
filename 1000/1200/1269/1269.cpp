#include <iostream>
#include <set>

using namespace std;
set<int> s1;
set<int> s2;
int A,B;
void input(){
	int temp;
	cin >> A;
	cin >> B;
	for(int i = 0 ; i < A ; i++){
		cin >> temp;
		s1.insert(temp);
	}
	for(int i = 0 ; i < B ; i++){
		cin >> temp;
		s2.insert(temp);
	}
}

int f(){
	set<int>::iterator iter;
	int co=0;
	for(iter = s1.begin() ; iter != s1.end() ; ++iter) {
		if(s2.count(*iter) == 1) co++; 
	}
	return s1.size() + s2.size() - (2*co);

}
void print(){
	set<int>::iterator iter;
	for(iter = s1.begin(); iter != s1.end() ; ++iter) cout << *iter<<" ";
	cout << endl;
	for(iter = s2.begin(); iter != s2.end() ; ++iter) cout << *iter<<" ";
	cout << endl;
}


int main(){
	input();
	cout << f() << endl;
	return 0;
}