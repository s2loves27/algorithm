#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
string input_car[1000];
string output_car[1000];

int N;
int ranking[1000];
void input(){
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		cin >> input_car[i];
	}
	for(int i = 0 ; i < N ; i++){
		cin >> output_car[i];
	}

}
// void print(){
// 	for(int i = 0 ; i < N ; i++) cout << input_car[i]<<endl;
// 	for(int i = 0 ; i < N ; i++) cout << output_car[i]<<endl;	
// }
int f(){
	int co = 0;
	int temp = 0;
	for(int i = 0 ; i < N  ;i++){
		for(int j = 0 ; j < N ; j++){
			if(input_car[i].compare(output_car[j]) == 0){
				ranking[j] = i;
				break;
			}
		}
	}
	int j;
	for(int i = 0 ; i < N ; i++){
		for(j = i+1 ; j < N ; j++){
			if(ranking[i] > ranking[j]){
				break;
			}
		}
		if(j != N) co++;
	}
	return co;

}

int main(){
	input();
	//print();
	printf("%d\n",f());
	return 0;
}