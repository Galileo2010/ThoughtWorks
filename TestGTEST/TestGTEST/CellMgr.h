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
	
	void SetAutoEvolution(bool autoEvolution_);
	bool GetAutoEvolution();
	void UpdateCurrentStatus();
	int  GetNumberOfLivingCellsAround(int i, int j);
	liveStatus GetNextMomentCellStatus(int i, int j);
	bool IsInCellStatusVector(int i, int j);
	void Init();
	void Show();
	void ReStart();
	void SetSize(int i_, int j_);
	void SetColor(int i, int j);

	void SetsleepTime(int sleeptime_);
	int GetsleepTime()  const;
private:

	bool autoEvolution;
	int rows;
	int columns;
	int sleepTime;
	int numberOfIterations;
	vector<vector<int>> ages;			// ÄêÁä
	
};