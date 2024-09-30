#include <algorithm>
#include "shapes.h"

//Implement your shapes here

Triangle::Triangle(Point t[3], Color c) : Shape(c)
{
    m_tri[0] = t[0];
    m_tri[1] = t[1];
    m_tri[2] = t[2];
}

Triangle::~Triangle() {}

BoundingBox Triangle::getBoundingBox()
{
    BoundingBox b;

    b.ul.x = min(m_tri[0].x, m_tri[1].x, m_tri[2].x);
    b.ul.y = min(m_tri[0].y, m_tri[1].y, m_tri[2].y);

    b.br.x = max(m_tri[0].x, m_tri[1].x, m_tri[2].x);
    b.br.x = max(m_tri[0].y, m_tri[1].y, m_tri[2].y);

    //upper left wants min x and min y 
    // bottom right wants max x and max y

    return b;
}

bool Triangle::inside(uint32_t x, uint32_t y) 
{
    Point p = {x,y};
    return PointInTriangle(p, m_tri);
}