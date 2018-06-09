#pragma once
#include <vector>
using namespace std;
enum liveStatus
{
	living = -1,
	keep = 0,
	dead = 1
};
class Game
{
public:
	Game();
	Game(int i, int j);
	~Game();
	
	vector<vector<int>> ages;// 存放存活的次数
	vector<vector<bool>> cellStatus;

	bool autoEvolution;
	int rows;
	int columns;
	int sleepTime;
	int numberOfIterations;

	void SetCellStatus();
	void UpdateCurrentStatus();
	int  GetNumberOfLivingCellsAround(int i, int j);
	liveStatus GetNextMomentCellStatus(int i, int j);
	bool IsInCellStatusVector(int i, int j);
	void Show();
	void ReStart();
	void SetSizeofij(int i_, int j_);
	void SetColor(int i, int j);
private:


};