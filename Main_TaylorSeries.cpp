/*
Created on Thuesday Mar 01 2022
@author: 
    Leonardo Juárez Morales
@Description: 
    -Calculate sine and cosine function using Taylor Series
    -Calculate execution time
    -Calculate N iterations for the angles 30,45,60,75,90
*/

#include <iostream>
#include <ctime>

using namespace std;

#define M_PI 3.14159265358979323846   // pi

unsigned t0, t1;

int main(int argc, char const *argv[])
{
    t0 = clock();    
    //CODE
    int n = 5;  //number of iterations
    double angle = 30;
    double sin = 0;
    double cos = 1;

    // Convert angle to rad
    angle = (angle * M_PI )/180;
    cout << angle << endl;

    



    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution time: " << time << endl;
    return 0;
}
