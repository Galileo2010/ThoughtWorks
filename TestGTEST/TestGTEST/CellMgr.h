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
	// ϸ����ǰ����Ŀ
	// ��ǰ״̬����ȡ����ϸ����ǰ������״̬
	void GetCurrentStatus() {};
	// ����״̬
	void UpdateCurrentStatus() {};
private:

};

Container::Container()
{
}

Container::~Container()
{
}