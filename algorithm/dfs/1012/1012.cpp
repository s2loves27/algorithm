// #include <iostream>
// #include <vector>
// #include <cstdio>
// #include <algorithm>
// using namespace std;

// vector<int> graphList[100];
// vector<bool> visited;
// int n,m;
// int dfs(int inf){
// 	int node = 1;
// 	visited[inf] = true;
// 	cout << "node " << inf << " visited" << endl;
// 	for(int i = 0 ; i < graphList[inf].size() ; i ++){
// 		if(visited[graphList[inf][i]] == false){
// 			node+=dfs(graphList[inf][i]);
// 		}	
// 	}
// 	return node;

// }
//  dfs_all(){
// 	fill(visited.begin(), visited.end(), false);
// 	int components = 0;
// 	for(int i=0; i<n; i++){
//             if(!visited[i]){
//                 cout << "-- new DFS begins --" << endl;
//                 int nodes = dfs(i);
//                 components++;
//                 cout << "size: " << nodes << endl << endl;
//             }
//         }
//     return components;
// }
// int main()
// {
//     //input
//     scanf("%d%d",&n,&m);
//     for(int i=0; i<m; i++){
//         int s,e;
//         scanf("%d%d",&s,&e);
//         graphList[s].push_back(e);
//         graphList[e].push_back(s);
//     }
//     //output
//     printf("\n==인접리스트 구현 완료==\n");
//     for(int i=0; i<n; i++){
//         printf("%d : ",i);
//         for(int j=0; j<graphList[i].size(); j++){
//             printf("%d ",graphList[i][j]);            //vector 배열은 이렇게 2차원 배열처럼[]연산자를 사용해서 표현가능
//         }
//         printf("\n");
//     }
//   	visited.resize(n);
//   	fill(visited.begin(),visited.end(),false);
//  	printf("all components = %d" , dfs_all());
//     return 0;
// }


//// 함수 이용
// #include <cstdio>
// #include <iostream>
// #include <cmath>
// #include <algorithm>
// #include <vector>
// using namespace std;

// vector<vector<int>> graphList;
// vector<bool> visited;
// bool ca[53][53];
// int col,raw;
// int T,M,N,K;
// int dfs(int col,int raw){
// 	ca[col][raw] = false;
// 	if(ca[col+1][raw]){
// 		dfs(col+1,raw);
// 	}
// 	if(ca[col-1][raw]){
// 		dfs(col-1,raw);
// 	}
// 	if(ca[col][raw+1]){
// 		dfs(col,raw+1);
// 	}
// 	if(ca[col][raw-1]){
// 		dfs(col,raw-1);
// 	}
// 	return 0;
// }
// int dfs_all(){
// 	int components = 0;
// 	for(int i = 1; i <= M+1 ; i++){
// 		for(int j = 1 ; j <= N+1; j++){
// 			if(ca[i][j] == true) {
// 				dfs(i,j);
// 				components++;
// 			}
// 		}
// 	}
// 	return components;
// }
// int main(){

// 	for(int i = 0 ; i < 53 ; i ++){
// 		for(int j = 0 ; j <53 ; j++){
// 			ca[i][j] = false;
// 		}
// 	}
// 	scanf("%d",&T);
// 	for(int j = 0 ; j < T ; j++){
// 	scanf("%d%d%d",&M,&N,&K);

// 	for(int i = 0 ; i < K ; i++){
// 		scanf("%d%d",&col,&raw);
// 		ca[col+1][raw+1] = true;	
// 	}
// 	printf("%d\n",dfs_all());
// 	}


// 	return 0;
// }
//// stack 이용
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int T;
int M,N,K;
int start_x,start_y;
int ca[2502][2502];
int visited[2502][2502];

struct point{
	int x;
	int y;
};

vector<point> cabbage;
stack<point> cur;

int dfs(){
	point temp;
	int x,y;
	int num=0;
	while(!cabbage.empty()){
		temp = cabbage.back();
		cabbage.pop_back();
		cur.push(temp);
		if(!visited[temp.x][temp.y]){
			visited[temp.x][temp.y] = 1;
			num++;
			while(!cur.empty()){
				temp = cur.top();
				cur.pop();
				x = temp.x; y = temp.y;

				if(ca[x+1][y] == 1 && visited[x+1][y] ==0){
					visited[x+1][y] =1;
					temp.x = x+1;
					temp.y = y;
					cur.push(temp);
				}
				if(ca[x-1][y] == 1 && visited[x-1][y] ==0){
					visited[x-1][y] =1;
					temp.x = x-1;
					temp.y = y;
					cur.push(temp);
				}
				if(ca[x][y+1] == 1 && visited[x][y+1] ==0){
					visited[x][y+1] =1;
					temp.x = x;
					temp.y = y+1;
					cur.push(temp);
				}
				if(ca[x][y-1] == 1 && visited[x][y-1] ==0){
					visited[x][y-1] =1;
					temp.x = x;
					temp.y = y-1;
					cur.push(temp);
				}
				
			}
		}
		else cur.pop();
	}
	return num;
}
void input(){
	int x,y;
	point temp; 
	scanf("%d%d%d",&M,&N,&K);

	for(int i = 1 ; i <= M ; i++){
		for(int j = 1 ; j <= N ; j++){
			ca[i][j] = 0;
			visited[i][j] = 0;
		}
	}
	for(int i = 0 ; i < K ; i++){
		scanf("%d%d",&x,&y);
		temp.x = x+1; temp.y = y+1;
		cabbage.push_back(temp);
		ca[x+1][y+1] = 1;
	}

}
int main(){

	scanf("%d",&T);
	for(int i = 0 ; i < T ; i++){
		input();
		int result = dfs();
		printf("%d\n",result);
	}

	return 0;
}