#pragma once
#include "stdafx.h"
#include "CellMgr.h"
Cell::Cell()
{
}

Cell::~Cell()
{
}


Game::Game()
{
	cellStatus.resize(14);//r��
	for (int k = 0; k < 14; ++k) {
		cellStatus[k].resize(14);//ÿ��Ϊc��
	}
	cellStatus[0][1] = true;
	cellStatus[0][2] = true;
	cellStatus[1][0] = true;
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
				glRecti(j - 7, 7 - i, j - 6, 6 - i);
		}
}

void Game::UpdateCurrentStatus()
{
	vector<vector<liveStatus>> cellNextStatus;
	cellNextStatus.resize(cellStatus.size());
	for (int i = 0; i < cellStatus.size(); ++i) {
		cellStatus[i].resize(cellStatus[0].size());
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