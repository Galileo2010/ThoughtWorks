#pragma once
#include "stdafx.h"
#include "CellMgr.h"

Game::Game(){}

Game::Game(int i_,int j_):rows(i_ ), columns(j_)
{
	numberOfIterations = 0;
	autoEvolution = false;
	sleepTime = 200;
	cellStatus.resize(rows);
	for (int k = 0; k < rows; ++k)
		cellStatus[k].resize(columns);

	srand((unsigned)time(NULL));
	
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
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

void Game::SetSizeofij(int i_, int j_)
{
	rows = i_;
	columns = j_;
}

void Game::SetCellStatus()
{

}

void Game::Show()
{
	//glColor4f(0.7, 0.7, 0.7, log(1 + numberOfIterations));
	glColor4f(0.7, 0.7, 0.7, 1);
	for (int i = 0; i < cellStatus.size(); i++)
		for (int j = 0; j < cellStatus[i].size(); j++)
			if (cellStatus[i][j] == true)
				glRecti(j - columns / 2, rows / 2 - i, j - columns / 2 - 1, rows / 2 - 1 - i);
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

	numberOfIterations++;
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

bool Game::IsInCellStatusVector(int i, int j)
{
	return i >= 0 && i < cellStatus.size() && j >= 0 && j < cellStatus[0].size();
}

void Game::ReStart()
{
	autoEvolution = false;
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