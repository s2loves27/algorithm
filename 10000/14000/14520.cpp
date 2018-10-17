#include<iostream>
#include<cstdio>
#include<vector>
#include<string>

#define F 0
#define R 1
#define B 2
#define L 3



using namespace std;



const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

struct node {
   int n_a;
   int n_b;
   node() { 
   n_a = 0;
   n_b = 0; 
	}
};



struct map_n {
   bool vis[4];
   map_n() { 
   		def(); 
   }
   void def() {
      vis[0] = false;
      vis[1] = false;
      vis[2] = false;
      vis[3] = false;
   }
};

struct pos {
   int y;
   int x;
   int a;
   void def(){
   	x = 0;
   	y = 0;
   	a = 2;
   }
};

vector<node> ndata[1 << 15];

vector<map_n> visit[1 << 15];

string line;

int result_x, result_y;

int main() {
   int N;
   scanf("%d ", &N);
   
   for (int y = 0; y < N; ++y) {
      getline(cin, line);
      ndata[y].resize(N + 1);
      visit[y].resize(N + 1);
      for (int x = 0; x < N; ++x) {
         int re_dir = 0;
         if (line[3 * x] == 'F') {
            re_dir = F;
         }
         else if (line[3 * x] == 'R') {
            re_dir = R;
         }
         else if (line[3 * x] == 'B') {
            re_dir = B;
         }
         else if (line[3 * x] == 'L') {
            re_dir = L;
         }
         ndata[y][x].n_b = re_dir;
         ndata[y][x].n_a = line[3 * x + 1] - '0';
      }
   } // input node info

   pos cu;
   cu.def();
   while (1) {
      cu.a = (cu.a + ndata[cu.y][cu.x].n_b) % 4;
      if (visit[cu.y][cu.x].vis[cu.a]) {
         result_x = cu.x; result_y = cu.y;
         break;
      }
      visit[cu.y][cu.x].vis[cu.a] = true;
      int next_y = cu.y + dy[cu.a] * ndata[cu.y][cu.x].n_a;
      int next_x = cu.x + dx[cu.a] * ndata[cu.y][cu.x].n_a;
      cu.y = next_y;
      cu.x = next_x;
   }

   printf("%d %d\n",result_x,result_y);
   
   return 0;
}
