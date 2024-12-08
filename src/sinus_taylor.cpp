#include <iostream>
#include <cmath>
namespace sinus_taylor {
    float sin(float x) {
        float result = x;
        float currentAn = x; 
        float e = 1e-6;
        int n = 1;

        while (true) {
            float q = (-1.0 * (x * x)) / ((2 * n) * (2 * n + 1));
            currentAn *= q;

            if (fabs(currentAn) < e) {
                break;
            }

            result += currentAn;
            n++;
        }

        return result;
    }

    double sin(double x) {
        double result = x;
        double currentAn = x; 
        double e = 1e-6;
        int n = 1;

        while (true) {

            double q = (-1.0 * (x * x)) / ((2 * n) * (2 * n + 1));
            currentAn *= q;

            if (fabs(currentAn) < e) {
                break;
            }

            result += currentAn;
            n++;
        }

        return result;
    }

    long double sin(long double x) {
        long double result = x;
        long double currentAn = x; 
        long double e = 1e-6;
        int n = 1;

        while (true) {

            long double q = (-1.0 * (x * x)) / ((2 * n) * (2 * n + 1));
            currentAn *= q;

            if (fabs(currentAn) < e) {
                break;
            }

            result += currentAn;
            n++;
        }

        return result;
    }

    void print_sin(const float& x){
        std::cout << x << " with type float" << std::endl;
    }

    void print_sin(const double& x){
        std::cout << x << " with type double" << std::endl;
    }

    void print_sin(const long double& x){
        std::cout << x << " with type long double" << std::endl;
    }
}