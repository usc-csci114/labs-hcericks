#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath> 
#include <iomanip>



double calc_mean (std::vector<double>& input_values) 
{
    double sum = 0;

    for (int i = 1; i < input_values.size(); i++) 
    {
        sum += input_values[i];
    }

    double mean = sum / input_values.size();
    return mean;
}

double calc_B (std::vector<double>& x_vals, std::vector<double>& y_vals, double x_mean, double y_mean)
{
    double num_sum = 0;
    double denom_sum = 0;
    for (int i = 1; i < x_vals.size(); i++)
    {
        num_sum += ((x_vals[i] - x_mean) * (y_vals[i] - y_mean));
        denom_sum += (std::pow((x_vals[i] - x_mean),2));
    }
    double beta = (num_sum / denom_sum);
    return beta;
}

double calc_A (double x_mean, double y_mean, double beta)
{
    double alpha = y_mean - (beta * x_mean);
   return alpha;
}

double calc_SS_res (std::vector<double> fi_datapoints, std::vector<double> y_vals)
{
    double calc = 0;
    double SS_res = 0;
    for (int i = 1; i < fi_datapoints.size(); i++)
    {
        calc = y_vals[i] - fi_datapoints[i];
        SS_res += (std::pow(calc, 2));
    }

    return SS_res;
}

double calc_SS_tot(std::vector<double> y_vals, double y_mean)
{
    double calc = 0;
    double SS_tot = 0;
    for (int i = 1; i < y_vals.size(); i++)
    {
        calc = y_vals[i] - y_mean;
        SS_tot += (std::pow(calc, 2));
    }
    return SS_tot;
}


int main (int argc, char **argv) 
{
    std::vector<double> sat;
    std::vector<double> gpa;

    std::ifstream file("gpa_sat.csv");
    std::string line;

    if (!file.is_open()) 
    {
    std::cout << "Failed to open file!" << std::endl;
    return 0;
    }


     while (getline(file, line))
    {
        std::stringstream ss(line);
        double sat_value, gpa_value;
        char comma;

        ss >> sat_value >> comma >> gpa_value;

        sat.push_back(static_cast<double>(sat_value));
        gpa.push_back(static_cast<double>(gpa_value));
    }

    double x_mean = calc_mean(sat);
    double y_mean = calc_mean(gpa);

    double beta =  calc_B(sat, gpa, x_mean, y_mean);
    double alpha = calc_A(x_mean, y_mean, beta);

    std::vector<double> fi_datapoints(101);


    for (int i = 0; i < sat.size(); i++)
    {
        fi_datapoints[i] = (alpha + (beta * sat[i]));
    }

    double SS_res =  calc_SS_res(fi_datapoints, gpa);
    double SS_tot =  calc_SS_tot(gpa, y_mean);

    double R_sqaured = 1 - (SS_res/SS_tot);

    double val = (alpha  +  beta)  * gpa[2];

    std::cout << "Hello " << gpa[2] <<  "   " << val  <<  "   " << sat[2] << std::endl;


    std::cout << "SAT score = "<< alpha << " + " << beta << " * GPA" << std::endl;
    std::cout << "R sqaured value is " << R_sqaured << std::endl;



}