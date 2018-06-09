#pragma once

enum liveStatus
{
	living = -1,
	keep = 0,
	dead = 1
};
class Cell
{
public:
	Cell();
	~Cell();
	int x;
	int y;
	bool blive;
private:

};

class Game
{
public:
	Game();
	~Game();
	bool cellStatus[3][3];
	int limit;
	
	void SetCellStatus()
	{

	}
	void GetCurrentStatus() 
	{
		return;
	};
	
	void UpdateCurrentStatus() 
	{

		// ���ݵ�ǰ״̬��
	};

	int  GetNumberOfLivingCellsAround(int i, int j)
	{
		int counter = 0;
		if (i - 1 >= 0)
		{
			if (cellStatus[i - 1][j - 1] == true)	counter++;
			if (cellStatus[i - 1][j] == true)		counter++;
			if (cellStatus[i - 1][j + 1] == true)	counter++;
		}

		if (j - 1 >=0)
		{
			if (cellStatus[i][j - 1] == true)		counter++;
		}
		
		if (j + 1 < 3)
		{
			if (cellStatus[i][j + 1] == true)		counter++;
		}
		
		if (i + 1 < 3)
		{
			if (cellStatus[i + 1][j - 1] == true)	counter++;
			if (cellStatus[i + 1][j] == true)		counter++;
			if (cellStatus[i + 1][j + 1] == true)	counter++;
		}
		return counter;
	}
	liveStatus GetNextMomentCellStatus(int i, int j)
	{
		/*
		ÿ�����ӵ�������ѭ�����ԭ��
		1�� ���һ��ϸ����Χ��3��ϸ��Ϊ����һ��ϸ����Χ����8��ϸ���������ϸ��Ϊ��������ϸ����ԭ��Ϊ������תΪ������ԭ��Ϊ�����򱣳ֲ��䣩 ��
		2�� ���һ��ϸ����Χ��2��ϸ��Ϊ�������ϸ��������״̬���ֲ��䣻
		3�� ����������£���ϸ��Ϊ��������ϸ����ԭ��Ϊ������תΪ������ԭ��Ϊ�����򱣳ֲ��䣩
		*/
		int counter = GetNumberOfLivingCellsAround(i, j);
		if (counter == 3)
			return living;
		else if (counter == 2)
			return keep;
		else
			return dead;
	}
private:


};