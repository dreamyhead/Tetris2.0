#include "Figure.h"

Figure::Figure(Point position)
{
	m_Position = position;
	m_Body = Generate();
}
std::vector<std::vector<Point>> Figure::Generate()
{
	switch (rand() % 7)
	{
	case 0: return { {Point(0,0), Point(1,0), Point(2,0), Point(3,0)},
					 {Point(1,0), Point(1,1), Point(1,2), Point(1,3)} };

	case 1: return { {Point(0,0), Point(1,0), Point(2,0), Point(1,1)},
					 {Point(1,0), Point(1,1), Point(1,2), Point(0,1)},
					 {Point(0,1), Point(1,1), Point(2,1), Point(1,0)},
					 {Point(0,0), Point(0,1), Point(0,2), Point(1,1)} };

	case 2: return { {Point(0,0), Point(1,0), Point(2,0), Point(2,1)},
					 {Point(1,0), Point(1,1), Point(1,2), Point(0,2)},
					 {Point(0,1), Point(0,2), Point(1,2), Point(2,2)},
					 {Point(0,0), Point(0,1), Point(0,2), Point(1,0)} };
	
	case 3: return { {Point(0,1), Point(1,1), Point(2,1), Point(2,0)},
					 {Point(1,0), Point(2,0), Point(2,1), Point(2,2)},
					 {Point(0,0), Point(0,1), Point(1,0), Point(2,0)},
					 {Point(0,0), Point(0,1), Point(0,2), Point(1,2)} };

	case 4: return { {Point(0,0), Point(0,1), Point(1,1), Point(1,2)},
				     {Point(0,1), Point(1,0), Point(1,1), Point(2,0)}};

	case 5: return { {Point(0,3), Point(0,2), Point(1,2), Point(1,1)},
					 {Point(0,0), Point(1,0), Point(1,1), Point(2,1)} };

	case 6: return { {Point(0,0), Point(0,1), Point(1,0), Point(1,1)} };
	}
}

void Figure::Update(double dt)
{
	m_TimeFromLastUpdate += dt;
	if (m_TimeFromLastUpdate <= m_TimeForUpdate) return;
	m_TimeFromLastUpdate = 0;

	++m_Position.y;
}

void Figure::Draw(Canvas& canvas)
{
	for (const Point& point : m_Body[m_CurrentRotate])
	{
		canvas.SetChar(point.x + m_Position.x,
			           point.y + m_Position.y, 0x25D8);
	}
}

void Figure::MoveRight()
{
	m_Position.x++;
}

void Figure::MoveLeft()
{
	m_Position.x--;
}

void Figure::Boost()
{
	++m_Position.y;
}

void Figure::Rotate()
{
	++m_CurrentRotate;
	if (m_CurrentRotate >= m_Body.size())
	{
		m_CurrentRotate = 0;
	}
}

void Figure::Backup()
{
	m_PositionBackup = m_Position;
	m_CurrentRotateBackup = m_CurrentRotate;
}

void Figure::Restore()
{
	m_Position = m_PositionBackup;
	m_CurrentRotate = m_CurrentRotateBackup;
}

const std::vector<Point>& Figure::GetBody() const
{
		return m_Body[m_CurrentRotate];
}



Point Figure::GetPosition() const
{
	return m_Position;
}

void Figure::SetPosition(Point position) {

	m_Position = position;
}