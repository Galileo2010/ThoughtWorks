#pragma once
#include "stdafx.h"
#include "CellMgr.h"

Game::Game(){}

Game::Game(int i_,int j_):rows(i_ ), columns(j_)
{
	Init();
}

Game::~Game()
{
}

void Game::SetColor(int i, int j)
{
	int age = ages[i][j];
	switch (age)
	{
		case 1:{glColor3f(0, 0, 128.0/255);break;}
		case 2:{glColor3f(65/255.0, 105 / 255.0, 225 / 255.0);break;}
		case 3:{glColor3f(100 / 255.0, 149 / 255.0, 237 / 255.0);break;}
		case 4:{glColor3f(176 / 255.0, 196 / 255.0, 222 / 255.0);break;}
		default:{glColor3f(176 / 255.0, 196 / 255.0, 222 / 255.0);break;}
	}
}

void Game::Show()
{
	for (int i = 0; i < cellStatus.size(); i++)
		for (int j = 0; j < cellStatus[i].size(); j++)
			if (cellStatus[i][j] == true)
			{
				SetColor(i, j);
				glRecti(j - columns / 2, rows / 2 - i, j - columns / 2 + 1, rows / 2 - 1 - i);// i行j列对应的矩形坐标
			}		
}

void Game::UpdateCurrentStatus()
{
	vector<vector<liveStatus>> cellNextStatus;
	cellNextStatus.resize(cellStatus.size());
	for (int i = 0; i < cellStatus.size(); ++i)
		cellNextStatus[i].resize(cellStatus[0].size());

	for (int i = 0; i < cellStatus.size(); i++)
		for (int j = 0; j < cellStatus[i].size(); j++)
			cellNextStatus[i][j] = GetNextMomentCellStatus(i, j);

	for (int i = 0; i < cellStatus.size(); i++)
		for (int j = 0; j < cellStatus[i].size(); j++)
		{
			if (cellNextStatus[i][j] == living)
			{
				cellStatus[i][j] = true;
				ages[i][j]++;
			}
			else if (cellNextStatus[i][j] == dead)
			{
				cellStatus[i][j] = false;
				ages[i][j] = 0;
			}
			else
			{
				if (ages[i][j] > 0)
				{
					ages[i][j]++;
				}
			}
		}
};

int Game::GetNumberOfLivingCellsAround(int i, int j)
{
	int counter = 0;
	if (IsInCellStatusVector(i - 1, j - 1))
		if (cellStatus[i - 1][j - 1] == true)	counter++;
	if (IsInCellStatusVector(i - 1, j))
		if (cellStatus[i - 1][j] == true)		counter++;
	if (IsInCellStatusVector(i - 1, j + 1))
		if (cellStatus[i - 1][j + 1] == true)	counter++;
	if (IsInCellStatusVector(i, j - 1))
		if (cellStatus[i][j - 1] == true)		counter++;
	if (IsInCellStatusVector(i, j + 1))
		if (cellStatus[i][j + 1] == true)		counter++;
	if (IsInCellStatusVector(i + 1, j - 1))
		if (cellStatus[i + 1][j - 1] == true)	counter++;
	if (IsInCellStatusVector(i + 1, j))
		if (cellStatus[i + 1][j] == true)		counter++;
	if (IsInCellStatusVector(i + 1, j + 1))
		if (cellStatus[i + 1][j + 1] == true)	counter++;
	return counter;
}

/*
每个格子的生死遵循下面的原则：
1． 如果一个细胞周围有3个细胞为生（一个细胞周围共有8个细胞），则该细胞为生（即该细胞若原先为死，则转为生，若原先为生，则保持不变） 。
2． 如果一个细胞周围有2个细胞为生，则该细胞的生死状态保持不变；
3． 在其它情况下，该细胞为死（即该细胞若原先为生，则转为死，若原先为死，则保持不变）
*/
liveStatus Game::GetNextMomentCellStatus(int i, int j)
{
	int counter = GetNumberOfLivingCellsAround(i, j);
	if (counter == 3)
		return living;
	else if (counter == 2)
		return keep;
	else
		return dead;
}

bool Game::IsInCellStatusVector(int i, int j)
{
	return i >= 0 && i < cellStatus.size() && j >= 0 && j < cellStatus[0].size();
}

void Game::ReStart()
{
	Init();
}

void Game::Init()
{
	numberOfIterations = 0;
	autoEvolution = false;
	sleepTime = 200;
	cellStatus.resize(rows);
	ages.resize(rows);
	for (int k = 0; k < rows; ++k)
	{
		cellStatus[k].resize(columns);
		ages[k].resize(columns);
	}
	srand((unsigned)time(NULL));
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
		{
			if (rand() % 2 == 0)
			{
				cellStatus[i][j] = true;
				ages[i][j] = 1;
			}
			else
			{
				cellStatus[i][j] = false;
				ages[i][j] = 0;
			}
		}
}

void Game::SetAutoEvolution(bool autoEvolution_)
{
	autoEvolution = autoEvolution_;
}
bool Game::GetAutoEvolution()
{
	return autoEvolution;
}

void Game::SetsleepTime(int sleeptime_)
{
	sleepTime = sleeptime_;
}
int Game::GetsleepTime()  const
{
	return sleepTime;
}