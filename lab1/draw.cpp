#include <iostream>
#include "bmplib.h"
#include "drawing.h"
#include <fstream>



using namespace std;


int main(int argc, char* argv[])
{
	
	//use the structs/classes you defined in drawing.h to implement the program in this file


	string filename;

	cout << "Please enter file name " << endl;
	cin >> filename;

	//std::string filename = argv[1];
	std::ifstream file(filename);
	
	if (!file.is_open()) 
	{
        cout << "Could not open file " << endl;
        return 1;
	}


	Drawing draw_image;

	draw_image.parse(filename);
	draw_image.draw();
	draw_image.write("output.bmp");

	
	return 0;


	
}

//main() needs to read the input file given as argv[1] and draw the lines specified in the file. 
/*

	ColorImage test (100,100);
	ColorPixel white = {255, 255, 255};
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			test.setPixel(white, j, i);
		}
		test.render("file");
	}



*/
	