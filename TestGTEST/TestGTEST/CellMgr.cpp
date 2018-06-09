#pragma once
#include "stdafx.h"
#include "CellMgr.h"

Game::Game()
{
	autoEvolution = false;
	cellStatus.resize(14);
	for (int k = 0; k < 14; ++k)
		cellStatus[k].resize(14);

	srand((unsigned)time(NULL));
	
	for (int i = 0; i < cellStatus.size(); i++)
		for (int j = 0; j < cellStatus[i].size(); j++)
		{
			if (rand() % 2 == 0)
				cellStatus[i][j] = true;
			else
				cellStatus[i][j] = false;
		}
}

Game::~Game()
{
}

void Game::SetCellStatus()
{

}

void Game::Show()
{
	for (int i = 0; i < cellStatus.size(); i++)
		for (int j = 0; j < cellStatus[i].size(); j++)
		{
			if (cellStatus[i][j] == true)
			{
				srand((unsigned)time(NULL));
				glColor3i(rand() % 255, rand() % 255, rand() % 255);
				glRecti(j - 7, 7 - i, j - 6, 6 - i);
			}
				
		}
	glColor3f(0, 0, 0);
}

void Game::UpdateCurrentStatus()
{
	vector<vector<liveStatus>> cellNextStatus;
	cellNextStatus.resize(cellStatus.size());
	for (int i = 0; i < cellStatus.size(); ++i) {
		cellNextStatus[i].resize(cellStatus[0].size());
	}

	for (int i = 0; i < cellStatus.size(); i++)
		for (int j = 0; j < cellStatus[i].size(); j++)
			cellNextStatus[i][j] = GetNextMomentCellStatus(i, j);

	for (int i = 0; i < cellStatus.size(); i++)
		for (int j = 0; j < cellStatus[i].size(); j++)
		{
			if (cellNextStatus[i][j] == living)
				cellStatus[i][j] = true;
			else if (cellNextStatus[i][j] == dead)
				cellStatus[i][j] = false;
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
liveStatus Game::GetNextMomentCellStatus(int i, int j)
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

bool Game::IsInCellStatusVector(int i, int j)
{
	return i >= 0 && i < cellStatus.size() && j >= 0 && j < cellStatus[0].size();
}