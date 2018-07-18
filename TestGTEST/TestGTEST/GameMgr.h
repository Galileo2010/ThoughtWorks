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
	
	vector<vector<bool>> cellStatus;	// ´æ»î×´Ì¬
	
	void Init();
	void UpdateCurrentStatus();
	bool IsInCellStatusVector(int i, int j);
	int  GetNumberOfLivingCellsAround(int i, int j);
	liveStatus GetNextMomentCellStatus(int i, int j);
	
	
	void SetColor(int i, int j);
	void Show();
	void ReStart();

	void SetAutoEvolution(bool autoEvolution_);
	bool GetAutoEvolution();
	void SetsleepTime(int sleeptime_);
	int GetsleepTime()  const;
private:

	bool autoEvolution;
	int rows;
	int columns;
	int sleepTime;
	vector<vector<int>> ages;			// ÄêÁä
	
};