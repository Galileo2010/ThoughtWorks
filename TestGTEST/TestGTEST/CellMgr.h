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

		// 根据当前状态，
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
		每个格子的生死遵循下面的原则：
		1． 如果一个细胞周围有3个细胞为生（一个细胞周围共有8个细胞），则该细胞为生（即该细胞若原先为死，则转为生，若原先为生，则保持不变） 。
		2． 如果一个细胞周围有2个细胞为生，则该细胞的生死状态保持不变；
		3． 在其它情况下，该细胞为死（即该细胞若原先为生，则转为死，若原先为死，则保持不变）
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