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
	~Game();

	vector<vector<bool>> cellStatus;
	bool autoEvolution;

	void SetCellStatus();
	void UpdateCurrentStatus();
	int  GetNumberOfLivingCellsAround(int i, int j);
	liveStatus GetNextMomentCellStatus(int i, int j);
	bool IsInCellStatusVector(int i, int j);
	void Show();
private:


};