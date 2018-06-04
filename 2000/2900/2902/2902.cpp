#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> v;
int main(){

	string a;
	string substring;
	cin >> a;
	int pos;
	while((pos = a.find("-")) != string::npos){
	substring = a.substr(0,pos);
	a = a.substr(pos+1,a.size() - pos -1);
	cout << substring.at(0);
	}
	cout << a.at(0);
	
	return 0;
}