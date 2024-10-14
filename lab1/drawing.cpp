#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>
#include <fstream>


#include "bmplib.h"
#include "drawing.h"




//implement your classes in this file

//adapted from https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
std::vector<Point> plotLine(Point start, Point end)
{
	int x0 = start.x;
	int y0 = start.y;
	int x1 = end.x;
	int y1 = end.y;
	
	int dx = abs(x1 - x0);
	int sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0);
	int sy = y0 < y1 ? 1 : -1;
	int error = dx + dy;
	
	std::vector<Point> line;
	
	while(true)
	{
		Point p = {x0, y0};
		line.push_back(p);
		if (x0 == x1 && y0 == y1) break;
		int e2 = 2 * error;
		if(e2 >= dy) {
			error = error + dy;
			x0 = x0 + sx;
		}
		if(e2 <= dx) {
			error = error + dx;
			y0 = y0 + sy;
		}
	}
	return line;
}

ColorImage::ColorImage (uint32_t xdim, uint32_t ydim) 
{
    data.resize(ydim);
    for (size_t i = 0; i < data.size(); ++i)
    {
        data[i].resize(xdim);
    }

	//ColorImage test (xdim, ydim);
	ColorPixel white = {255, 255, 255};
	for (int i = 0; i < ydim; i++)
	{
		for (int j = 0; j < xdim; j++)
		{
			setPixel(white, j, i);
		}
	}



}


void ColorImage::setPixel (ColorPixel p, uint32_t x, uint32_t y)
{
	uint32_t ysize = data.size();
	uint32_t xsize = data[0].size();

	ColorPixel white = {255, 255, 255};
	data[y][x] = white;

	if (x < xsize && y < ysize)
	{
		data[y][x] = p;
	}
	
}


ColorPixel ColorImage::getPixel (uint32_t x, uint32_t y) 
{
	uint32_t ysize = data.size();
	uint32_t xsize = data[0].size();

	if (x < xsize && y < ysize)
	{
		return data[y][x];
	}

	throw std::range_error ("bad size on getPixel()");
	
}

void ColorImage::render(string filename)
{
	size_t ydim = data.size();
	size_t xdim = data[0].size();

	uint8_t*** image = new uint8_t**[ydim];
	for (int i = 0; i < ydim; i++)
	{
		image[i] = new uint8_t*[xdim];

		for (int j = 0; j < xdim; j++)
		{
			image[i][j] = new uint8_t[3];
			image[i][j][R] = data[i][j].red;
			image[i][j][G] = data[i][j].green;
			image[i][j][B] = data[i][j].blue;
		}
		

	}
	writeRGBBMP(filename.c_str(), image, ydim, xdim);
}


Drawing::Drawing () : image(0,0) {}


void Drawing::parse(string filename)
{
	uint32_t xdim; 
	uint32_t ydim;
	string line;


	std::ifstream file(filename);


	getline(file, line);
	stringstream ss(line);
	ss >> xdim >> ydim;

	image = ColorImage(xdim,ydim);

	while (getline(file, line)) 
	{
		stringstream ss(line);
		Point start, end;
		ColorPixel c_point;
		
		uint32_t r,g,b;
		ss >> start.x >> start.y >> end.x >> end.y >> r >> g >> b;

		c_point.red = r; c_point.green = g; c_point.blue = b;
		Line line_object;
		line_object.start = start;
		line_object.end = end;
		line_object.c = c_point;

		lines.push_back(line_object);
	}
}



void Drawing::draw()
{
	for (int i = 0; i < lines.size() ; i++) 
	{	
		vector<Point> plot_lines = plotLine(lines[i].start, lines[i].end); 
		for (int p = 0; p < plot_lines.size(); p++)
		{
			//image = ColorImage(xdim,ydim);
			//ColorImage(uint32_t xdim, uint32_t ydim);

			uint32_t x = static_cast<uint32_t>(plot_lines[p].x); 
            uint32_t y = static_cast<uint32_t>(plot_lines[p].y);
			ColorPixel color = lines[i].c;

			image.setPixel(color, x, y);
		}
	}
}

void Drawing::write(string filename)
{
	image.render("output.bmp");
}











//finish color image  1. set pixal is straight forward (pixel and location) 2. render is a little more complicated -- go back to 103
