#include <algorithm>
#include <cmath>
#include "shapes.h"

//Implement your shapes here


bool PointInTriangle(Point p, Point tri[3])
{
	int s = (tri[0].x - tri[2].x) * (p.y - tri[2].y) - (tri[0].y - tri[2].y) * (p.x - tri[2].x);
	int t = (tri[1].x - tri[0].x) * (p.y - tri[0].y) - (tri[1].y - tri[0].y) * (p.x - tri[0].x);

	if ((s < 0) != (t < 0) && s != 0 && t != 0)
		return false;

	int d = (tri[2].x - tri[1].x) * (p.y - tri[1].y) - (tri[2].y - tri[1].y) * (p.x - tri[1].x);
	return d == 0 || (d < 0) == (s + t <= 0);
}

Shape::Shape (Color c)
{
    m_color = c;
}


void Shape::draw(uint8_t*** image, uint32_t h, uint32_t w)
{
    BoundingBox bb = getBoundingBox(); 
    for (int r = bb.ul.y; r < bb.br.y; r++) 
    {
        for (int c = bb.ul.x; c < bb.br.x; c++)
        {
            if(inside(c,r))
            {
                image[r][c][0] = m_color.r;
                image[r][c][1] = m_color.g;
                image[r][c][2] = m_color.b;
                //copy color to image 
            }
        }
    }
}

Shape::~Shape() {}

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

    b.ul.x = min(min(m_tri[0].x, m_tri[1].x) , m_tri[2].x);
    b.ul.y = min(min(m_tri[0].y, m_tri[1].y), m_tri[2].y);

    b.br.x = max(max(m_tri[0].x, m_tri[1].x), m_tri[2].x);
    b.br.x = max(max(m_tri[0].y, m_tri[1].y), m_tri[2].y);

    //upper left wants min x and min y 
    // bottom right wants max x and max y

    return b;
}

bool Triangle::inside(uint32_t x, uint32_t y) 
{
    Point p = {x,y};
    return PointInTriangle(p, m_tri);
}

Circle::Circle(Point center, uint32_t r, Color c) : Shape(c)
{
    m_center = center;
    m_radius = r;
}

Circle::~Circle() {}

BoundingBox Circle::getBoundingBox()
{
    BoundingBox b;

    b.ul.x = m_center.x - m_radius;
    b.ul.y = m_center.y - m_radius;

    b.br.x = m_center.x + m_radius;
    b.br.y = m_center.x + m_radius;

    return b;
}

bool Circle::inside (uint32_t x, uint32_t y) 
{
    double dx = x;
    double dy = y;

    double distance = sqrt((m_center.x - dx) * (m_center.x - dx) + (m_center.y - dy) * (m_center.y - dy));
    return distance < m_radius;
}



Rectangle::Rectangle (Point t[4], Color c): Shape(c)
{
    m_rect[0] = t[0];
    m_rect[1] = t[1];
    m_rect[2] = t[2];
    m_rect[3] = t[3];
    
}

Rectangle::~Rectangle () {}

BoundingBox Rectangle::getBoundingBox()
{
    BoundingBox b;

    b.ul.x = min(min(min(m_rect[0].x, m_rect[1].x ), m_rect[2].x ), m_rect[3].x);
    b.ul.y = min(min(min(m_rect[0].y, m_rect[1].y ), m_rect[2].y ), m_rect[3].y);

    b.br.x = max(max(max(m_rect[0].x, m_rect[1].x ), m_rect[2].x ), m_rect[3].x);
    b.br.y = max(max(max(m_rect[0].y, m_rect[1].y ), m_rect[2].y ), m_rect[3].y);

    return b;
}


bool Rectangle::inside(uint32_t x, uint32_t y) 
{
    BoundingBox inside = Rectangle::getBoundingBox();
 
    if ( (x > inside.ul.x) && (x < inside.br.x)) 
    {
        if( (y > inside.ul.y) && (y < inside.br.y)) 
        {
            return true;
        }
    }
    return false;
}
    
