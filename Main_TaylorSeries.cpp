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
#include <cmath>

using namespace std;

#define M_PI 3.14159265358979323846   // pi

unsigned t_sin_0, t_sin_1;  // Sin clock 
unsigned t_cos_0, t_cos_1;  // Cos clock

int factorial(int n){
    if (n == 1)
        return 1;
    return n*factorial(n-1);
}

void TaylorSin( int n_i, double angle){
    double sin = angle;
    double num = 0, den = 0;
    double error;

    for (int n = 0; n < n_i ;  n++){
        num = (pow(-1, n) * pow(angle, (2*n)+1));
        den = factorial( (2*n)+1 );
        sin += num/den;

        //cout << "num: " << num << endl;
        //cout << "den: " << den << endl;
        //cout << "sin: " << sin << endl;

    }
    cout << "Total Sin: "<< sin << endl;
    error= fabs(sin- std::sin(angle)); 
    cout << "Error: "<< error << endl;
    //for (int n = 0; n < n_i; n++)   // calculating sin 
    //    sin += (pow(-1, n) ) * ( (pow(angle, (2*n)+1 ) ) / ( factorial( (2*n)+1 )));
}

void TaylorCos(int n_i, double angle){
    double cos = 1;
    double num = 0, den = 0;
    double error;
    
    for (int n = 0; n < n_i ;  n++){

        num = (pow(-1, n) * pow(angle, (2*n)));
        den = factorial( (2*n));
        cos += num/den;

        cout << "num: " << num << endl;
        cout << "den: " << den << endl;
        cout << "sin: " << cos << endl;
    }
    cout << "Total Cos: "<< cos << endl;
    error= fabs(cos -std::cos(angle)); 
    cout << "Error: "<< error << endl;
    //for (int n = 0; n < n_i; n++)   //Calculatin cos
    //    cos += (pow(-1, n) * pow(angle, 2*n)) / (factorial(2*n));
}


int main(int argc, char const *argv[])
{
    

    long long n_i = 3;  //number of iterations
    double angle = 30;
    

    // Convert angle to rad
    angle = (angle * M_PI )/180;
    cout << angle << endl;
    
    t_sin_0 = clock();    // start sin clock
    cout << "--SIN--" << endl;
    TaylorSin(n_i, angle);
    t_sin_1 = clock();      // end sin clock
    double time_sin = (double(t_sin_1-t_sin_0)/CLOCKS_PER_SEC);
    cout << "Execution time: " << time_sin << endl;
    

    //t_cos_0 = clock();    // start cos clock
    cout << "--COS--" << endl;
    TaylorCos(n_i, angle);
    //SerieTaylorCoseno(n_i, 30);
    //t_cos_1 = clock();    // end sin clock
    //double time_cos = (double(t_cos_1-t_cos_0)/CLOCKS_PER_SEC);
    //cout << "Execution time: " << time_cos << endl;
        
        
    
    
    //cout << "Sin: " << sin << endl;
    //cout << "Cos: " << cos << endl;

    //t1 = clock();   // end clock
    //double time = (double(t1-t0)/CLOCKS_PER_SEC);
    //cout << "Execution time: " << time << endl;
    return 0;
}
