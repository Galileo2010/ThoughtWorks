#pragma once
#include <vector>
using namespace std;
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
	vector<vector<bool>> cellStatus;

	void SetCellStatus();

	void UpdateCurrentStatus();

	int  GetNumberOfLivingCellsAround(int i, int j);
	liveStatus GetNextMomentCellStatus(int i, int j);

	bool IsInCellStatusVector(int i, int j)
	{
		return i >= 0 && i < cellStatus.size() && j >= 0 && j < cellStatus[0].size();
	}
private:


};