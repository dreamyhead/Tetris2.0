#pragma once
#include <vector>
#include "Canvas.h"
#include "Figure.h"


struct Point
{
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	int x;
	int y;
};

class Figure
{
private:

	Point m_Position;
	Point m_PositionBackup;

	double m_TimeFromLastUpdate = 0;
	double m_TimeForUpdate = 1000;

	std::vector< std::vector<Point>> m_Body;

	size_t m_CurrentRotate = 0;
	size_t m_CurrentRotateBackup = 0;

public:
	Figure(Point position);
	void Update(double dt);
	void Draw(Canvas& canvas);
	void MoveRight();
	void MoveLeft();
	void Boost();
	void Rotate();

	void Backup();
	void Restore();

	const std::vector<Point>& GetBody() const;
	std::vector<std::vector<Point>> Generate();
	Point GetPosition() const;
	void SetPosition(Point position);
};

