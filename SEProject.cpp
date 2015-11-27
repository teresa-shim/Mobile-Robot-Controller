#include <stdio.h>
#include <list>

#define MapSize_x 10
#define MapSize_y 10
//���� MapSize�� ���ο� ���θ� ��Ÿ��.
#define TAR_X 7
#define TAR_Y 7
//Ž�� ��ǥ������ ��ǥ.
#define HAZ -1
//hazard�� �ο��ϴ� ��.
//��� �ӽ÷� ���� ��.
#define UNKNOWN 1000
//���� Ž������ ���� ������ ���� ��.

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

void InitDis()					//dis �ʱ�ȭ
{
	int i, j;
	
	for(i=1; i<MapSize_x; i++)
	{
		for(j=1; j<MapSize_y; j++)
			dis[i][j]=UNKNOWN;
	}
}

void CalPath(int x, int y)				//��θ� ����ϴ� �κ�.
{
	int i, j;

	if(map[x][y].kind==HAZ);			//hazard�� ������� ����.
	else
	{
		for(i=min(x, TAR_X); i<max(x, TAR_X); i++)
		{
			for(j=min(y, TAR_Y); j<max(y, TAR_Y); j++)
			{
				if((i==x)&&(j==y))					//�������� ���
					continue;
				if(dis[i+1][j]>dis[i][j]+1)			//������ �˻�
				{
					dis[i+1][j]=dis[i][j]+1;
					CalPath(i+1, j);
				}
				if(dis[i-1][j]>dis[i][j]+1)			//���� �˻�
				{
					dis[i-1][j]=dis[i][j]+1;
					CalPath(i-1, j);
				}
				if(dis[i][j+1]>dis[i][j]+1)			//���� �˻�
				{
					dis[i][j+1]=dis[i][j]+1;
					CalPath(i, j+1);
				}
				if(dis[i][j-1]>dis[i][j]+1)			//���� �˻�
				{
					dis[i][j-1]=dis[i][j]+1;
					CalPath(i, j-1);
				}
			}
		}
	}

}

void FindPath(int x, int y)					//��θ� �����ϴ� �κ�
{
	int i=TAR_X, j=TAR_Y;

	while((i!=x)&&(j!=y))					//�������� �Ÿ��� Ȯ���ϸ� ������������ ����������� ��θ� ����Ʈ�� ����.
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