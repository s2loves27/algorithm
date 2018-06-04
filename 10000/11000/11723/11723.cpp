#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int M;
int input_value=0;
char str[8];
int value;
void f(){
	//cout << str << input_value<<endl;
	if(strcmp(str,"add") == 0){
		input_value =  input_value | (1<<value);
	}
	else if(strcmp(str,"remove") == 0){
		if(((1<<value) & input_value) == 1<<value) input_value = ~(1<<value) & input_value;
	}
	else if(strcmp(str,"check") == 0){
		if(((1<<value) & input_value) == 1<<value) printf("1\n");
		else printf("0\n");
	}
	else if(strcmp(str,"toggle") == 0){
		if(((1<<value) & input_value)==1<<value) input_value = ~(1<<value) & input_value;
		else input_value = 1<<value | input_value;;
	}
	else if(strcmp(str,"all") == 0){
		input_value = ((1<<20) -1) | input_value;
	}
	else if(strcmp(str,"empty")== 0){
		input_value = ~((1<<20) -1) & input_value;
	}
}
int main(){
	scanf("%d",&M);
	for(int i = 0 ; i < M ;i ++){
		scanf("%s",str);
		if(strcmp(str,"all") != 0 && strcmp(str,"empty") != 0) scanf("%d",&value);
		else value = -1;
		//cout << value<<endl;
		value--;
		f();
	}


}