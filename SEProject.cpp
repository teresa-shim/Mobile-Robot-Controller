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

void InitDis()					//dis 초기화
{
	int i, j;
	
	for(i=1; i<MapSize_x; i++)
	{
		for(j=1; j<MapSize_y; j++)
			dis[i][j]=UNKNOWN;
	}
}

void CalPath(int x, int y)				//경로를 계산하는 부분.
{
	int i, j;

	if(map[x][y].kind==HAZ);			//hazard면 계산하지 않음.
	else
	{
		for(i=min(x, TAR_X); i<max(x, TAR_X); i++)
		{
			for(j=min(y, TAR_Y); j<max(y, TAR_Y); j++)
			{
				if((i==x)&&(j==y))					//시작점인 경우
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

}

void FindPath(int x, int y)					//경로를 저장하는 부분
{
	int i=TAR_X, j=TAR_Y;

	while((i!=x)&&(j!=y))					//노드까지의 거리를 확인하며 도착지점부터 출발지점까지 경로를 리스트에 저장.
	{
		if(dis[i][j]==dis[i+1][j]+1)
		{
			path.push_front(*map[i+1][j]);
			i++;
		}
		else if(dis[i][j]==dis[i-1][j]+1)
		{
			path.push_front(*map[i-1][j]);
			i--;
		}
		else if(dis[i][j]==dis[i][j+1]+1)
		{
			path.push_front(*map[i][j+1]);
			j++;
		}
		else if(dis[i][j]==dis[i][j-1]+1)
		{
			path.push_front(*map[i][j-1]);
			j--;
		}
	}
}