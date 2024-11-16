#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <matplot/matplot.h>
#include <vector>

using namespace matplot;

int main() {
	
	std::ifstream ifile("atmosphere.txt");
	std::string line;
	std::vector<double> p, h, t;
	

    if (!ifile.is_open()) 
    {
    std::cout << "Failed to open file!" << std::endl;
    return 0;
    }

     while (getline(ifile, line))
    {
        std::stringstream ss(line);
        double pressure, x_vals, temp;
		double dwpt, relh, mixr, drct, sknt, thta, thte, thtv;
        char comma;

        ss >> pressure >> x_vals >> temp >> dwpt >> relh >> mixr >> drct >> sknt >> thta >> thte >> thtv;

        p.push_back(static_cast<double>(pressure));
		h.push_back(static_cast<double>(x_vals));
		t.push_back(static_cast<double>(temp));
	}

	p.erase(p.begin(), p.begin() + 4); 
	h.erase(h.begin(), h.begin() + 4); 
	t.erase(t.begin(), t.begin() + 4); 

	plot(h, p, "bo-");
	title("Part 2");
    xlabel("Height (meters)");
    ylabel("Pressure hPa");
	//show();
	//save("task2.png");

	double t_min = *std::min_element(t.begin(), t.end());
	double t_max = *std::max_element(t.begin(), t.end());

	hold(on);
	plot(h,t, "-rx")->use_y2(true);
	y2lim({t_min, t_max});

	y2label("Temperature (C)");
	show();
	save("task2b.png");	
	
	return 0;
}
