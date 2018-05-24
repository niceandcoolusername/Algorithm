#include<iostream>
using namespace std;

#define N 8
 

int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };

bool inside(int x,int y){
	return (x>=0 and x<N and y>=0 and y<N);
}

int knightremains(int start_x,int start_y,int steps)
{
	double dp[N][N][N];  //dp[x][y][steps]
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			dp[i][j][0]=1;  //dp[x][y][steps]
		}
	}

	for(int s=1;s<=steps;s++){
		for(int x=0;x<N;x++){
			for(int y=0;y<N;y++){
				double prob=0.0;
				for(int i=0;i<8;i++){
					int nx=x+dx[i];
					int ny=y+dy[i];
					if(inside(nx,ny))
						prob+=dp[nx][ny][s-1]/8.0;
				}
				dp[x][y][s]=prob;

			}
		}
	}
	return dp[start_x][start_y][steps];
}

int main()
{
    // number of steps
    int K = 3;
 
    cout << knightremains(0, 0, K) << endl;
 
    return 0;
}