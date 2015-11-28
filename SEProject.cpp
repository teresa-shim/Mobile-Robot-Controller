#include <stdio.h>
#include <list>

#define MapSize_x 10
#define MapSize_y 10
//각각 MapSize의 가로와 세로를 나타냄.
#define TAR_X 7
#define TAR_Y 7
//탐사 목표지점의 좌표.
#define HAZ -1
//hazard에 부여하는 값.
//모두 임시로 넣은 값.
#define UNKNOWN 1000
//아직 탐사하지 않은 지역에 대한 값.

using namespace std;

int dis[MapSize_x+1][MapSize_y+1]={0};
list<Mapnode*> path;
Mapnode map[MapSize_x][MapSize_y];

class Mapnode
{
protected:
	int posX, posY;
	bool IsDetected;
};

void InitDis()										//dis 초기화
{
	int i, j;
	
	for(i=1; i<MapSize_x; i++)
	{
		for(j=1; j<MapSize_y; j++)
			dis[i][j]=UNKNOWN;
	}
}

void CalPath(int x, int y)							//노드에서 목표지점까지의 거리를 계산하는 부분. 방향을 잡는 용도로만 쓰일 듯.
{
	int i, j;

	if(map[x][y].kind==HAZ);						//hazard면 계산하지 않음.
	else if((TAR_X<x)&&(TAR_Y<y))					//x, y를 기준으로 목표지점이 3사분면에 있을 때
	{
		for(i=TAR_X; i<x; i++)
		{
			for(j=TAR_Y; j<y; j++)
			{
				if((i==TAR_X)&&(j==TAR_Y))			//시작점인 경우
					continue;
				if(dis[i+1][j]>dis[i][j]+1)			//오른쪽 검사
				{
					dis[i+1][j]=dis[i][j]+1;
					CalPath(i+1, j);
				}
				if(dis[i-1][j]>dis[i][j]+1)			//왼쪽 검사
				{
					dis[i-1][j]=dis[i][j]+1;
					CalPath(i-1, j);
				}
				if(dis[i][j+1]>dis[i][j]+1)			//위쪽 검사
				{
					dis[i][j+1]=dis[i][j]+1;
					CalPath(i, j+1);
				}
				if(dis[i][j-1]>dis[i][j]+1)			//밑쪽 검사
				{
					dis[i][j-1]=dis[i][j]+1;
					CalPath(i, j-1);
				}
			}
		}
	}
	else if((TAR_X<x)&&(TAR_Y>y))					//x, y를 기준으로 목표지점이 2사분면에 있을 때
	{
		for(i=TAR_X; i<x; i++)
		{
			for(j=TAR_Y; j>y; j--)
			{
				if((i==TAR_X)&&(j==TAR_Y))			//시작점인 경우
					continue;
				if(dis[i+1][j]>dis[i][j]+1)			//오른쪽 검사
				{
					dis[i+1][j]=dis[i][j]+1;
					CalPath(i+1, j);
				}
				if(dis[i-1][j]>dis[i][j]+1)			//왼쪽 검사
				{
					dis[i-1][j]=dis[i][j]+1;
					CalPath(i-1, j);
				}
				if(dis[i][j+1]>dis[i][j]+1)			//위쪽 검사
				{
					dis[i][j+1]=dis[i][j]+1;
					CalPath(i, j+1);
				}
				if(dis[i][j-1]>dis[i][j]+1)			//밑쪽 검사
				{
					dis[i][j-1]=dis[i][j]+1;
					CalPath(i, j-1);
				}
			}
		}
	}
	else if((TAR_X>x)&&(TAR_Y<y))					//x, y를 기준으로 목표지점이 4사분면에 있을 때
	{
		for(i=TAR_X; i>x; i--)
		{
			for(j=TAR_Y; j<y; j++)
			{
				if((i==TAR_X)&&(j==TAR_Y))			//시작점인 경우
					continue;
				if(dis[i+1][j]>dis[i][j]+1)			//오른쪽 검사
				{
					dis[i+1][j]=dis[i][j]+1;
					CalPath(i+1, j);
				}
				if(dis[i-1][j]>dis[i][j]+1)			//왼쪽 검사
				{
					dis[i-1][j]=dis[i][j]+1;
					CalPath(i-1, j);
				}
				if(dis[i][j+1]>dis[i][j]+1)			//위쪽 검사
				{
					dis[i][j+1]=dis[i][j]+1;
					CalPath(i, j+1);
				}
				if(dis[i][j-1]>dis[i][j]+1)			//밑쪽 검사
				{
					dis[i][j-1]=dis[i][j]+1;
					CalPath(i, j-1);
				}
			}
		}
	}
	else if((TAR_X>x)&&(TAR_Y>y))					//x, y를 기준으로 목표지점이 1사분면에 있을 때
	{
		for(i=TAR_X; i>x; i--)
		{
			for(j=TAR_Y; j>y; j--)
			{
				if((i==TAR_X)&&(j==TAR_Y))			//시작점인 경우
					continue;
				if(dis[i+1][j]>dis[i][j]+1)			//오른쪽 검사
				{
					dis[i+1][j]=dis[i][j]+1;
					CalPath(i+1, j);
				}
				if(dis[i-1][j]>dis[i][j]+1)			//왼쪽 검사
				{
					dis[i-1][j]=dis[i][j]+1;
					CalPath(i-1, j);
				}
				if(dis[i][j+1]>dis[i][j]+1)			//위쪽 검사
				{
					dis[i][j+1]=dis[i][j]+1;
					CalPath(i, j+1);
				}
				if(dis[i][j-1]>dis[i][j]+1)			//밑쪽 검사
				{
					dis[i][j-1]=dis[i][j]+1;
					CalPath(i, j-1);
				}
			}
		}
	}
	else if(x==TAR_X)								//x, y가 목표지점과 x축으로 일직선상에 놓여있을 때
	{
		if(y>TAR_Y)
		{
			for(j=y; j>TAR_Y; j--)					//x, y를 기준으로 목표지점이 아래에 있을 때
				dis[x][j-1]=dis[x][j]+1;
		}
		else										//x, y를 기준으로 목표지점이 위에 있을 때
		{
			for(j=y; j<TAR_Y; j++)
				dis[x][j+1]=dis[x][j]+1;
		}
	}
	else if(y==TAR_Y)								//x, y가 목표지점과 y축으로 일직선상에 놓여있을 때
	{
		if(x>TAR_X)
		{
			for(i=x; i>TAR_X; i--)					//x, y를 기준으로 목표지점이 왼쪽에 있을 때
				dis[i-1][y]=dis[i][y]+1;
		}
		else										//x, y를 기준으로 목표지점이 오른쪽에 있을 때
		{
			for(i=x; i<TAR_X; i++)
				dis[i+1][y]=dis[i][y]+1;
		}
	}

}