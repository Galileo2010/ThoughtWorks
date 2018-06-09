#pragma once
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

Cell::Cell()
{
}

Cell::~Cell()
{
}

class Container
{
public:
	Container();
	~Container();
	// 细胞当前的数目
	// 当前状态，获取所有细胞当前的生存状态
	void GetCurrentStatus() {};
	// 更新状态
	void UpdateCurrentStatus() {};
private:

};

Container::Container()
{
}

Container::~Container()
{
}