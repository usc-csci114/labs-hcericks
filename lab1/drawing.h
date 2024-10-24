#ifndef DRAWING_H
#define DRAWING_H

#include <string>
#include <vector>
#include "bmplib.h"

using namespace std;

//Define your structs/classes in this file

struct ColorPixel {
	uint8_t red, green, blue;
};

class ColorImage {
	public:
		ColorImage(uint32_t xdim, uint32_t ydim);
		void setPixel(ColorPixel p, uint32_t x, uint32_t y);
		ColorPixel getPixel(uint32_t x, uint32_t y);
		void render(string filename);
			
	private:
		vector< vector<ColorPixel> > data;
}; 

struct Point {
	double x, y;
};

struct Line {
	Point start, end;
	ColorPixel c;
};

class Drawing {
	public:
		Drawing();
		void parse(string filename);
		void draw();
		void write(string filename);
	private:
		ColorImage image;
		vector<Line> lines;
};



#endif


//wright calls render
//draw will go through vector of lines --> give to line drawing algorithim
// vector will give you back points --> set pixel to get the color
// render you call within write function

// dont use constructor initialization list, inside constructor create ColorImage image = ColorImage(with dimensions from above)