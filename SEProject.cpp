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

void InitDis()										//dis �ʱ�ȭ
{
	int i, j;
	
	for(i=1; i<MapSize_x; i++)
	{
		for(j=1; j<MapSize_y; j++)
			dis[i][j]=UNKNOWN;
	}
}

void CalPath(int x, int y)							//��忡�� ��ǥ���������� �Ÿ��� ����ϴ� �κ�. ������ ��� �뵵�θ� ���� ��.
{
	int i, j;

	if(map[x][y].kind==HAZ);						//hazard�� ������� ����.
	else if((TAR_X<x)&&(TAR_Y<y))					//x, y�� �������� ��ǥ������ 3��и鿡 ���� ��
	{
		for(i=TAR_X; i<x; i++)
		{
			for(j=TAR_Y; j<y; j++)
			{
				if((i==TAR_X)&&(j==TAR_Y))			//�������� ���
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
	else if((TAR_X<x)&&(TAR_Y>y))					//x, y�� �������� ��ǥ������ 2��и鿡 ���� ��
	{
		for(i=TAR_X; i<x; i++)
		{
			for(j=TAR_Y; j>y; j--)
			{
				if((i==TAR_X)&&(j==TAR_Y))			//�������� ���
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
	else if((TAR_X>x)&&(TAR_Y<y))					//x, y�� �������� ��ǥ������ 4��и鿡 ���� ��
	{
		for(i=TAR_X; i>x; i--)
		{
			for(j=TAR_Y; j<y; j++)
			{
				if((i==TAR_X)&&(j==TAR_Y))			//�������� ���
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
	else if((TAR_X>x)&&(TAR_Y>y))					//x, y�� �������� ��ǥ������ 1��и鿡 ���� ��
	{
		for(i=TAR_X; i>x; i--)
		{
			for(j=TAR_Y; j>y; j--)
			{
				if((i==TAR_X)&&(j==TAR_Y))			//�������� ���
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
	else if(x==TAR_X)								//x, y�� ��ǥ������ x������ �������� �������� ��
	{
		if(y>TAR_Y)
		{
			for(j=y; j>TAR_Y; j--)					//x, y�� �������� ��ǥ������ �Ʒ��� ���� ��
				dis[x][j-1]=dis[x][j]+1;
		}
		else										//x, y�� �������� ��ǥ������ ���� ���� ��
		{
			for(j=y; j<TAR_Y; j++)
				dis[x][j+1]=dis[x][j]+1;
		}
	}
	else if(y==TAR_Y)								//x, y�� ��ǥ������ y������ �������� �������� ��
	{
		if(x>TAR_X)
		{
			for(i=x; i>TAR_X; i--)					//x, y�� �������� ��ǥ������ ���ʿ� ���� ��
				dis[i-1][y]=dis[i][y]+1;
		}
		else										//x, y�� �������� ��ǥ������ �����ʿ� ���� ��
		{
			for(i=x; i<TAR_X; i++)
				dis[i+1][y]=dis[i][y]+1;
		}
	}

}