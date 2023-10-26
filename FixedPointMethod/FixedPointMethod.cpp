#include <iostream>
#include <cmath>
using namespace std;;
const double epsilon = 0.01;
double getInitialX() {
    double x;
    cout << "Enter an initial value for x0:" << endl;
    cin >> x;
    return  x;
}
double mainEquation(double x) {
    return pow(x, 2) - 3 * x + 1;
}
// the following function are the result of the process x = g(x)
double g1(double x) {
    return sqrt(3 * x - 1);
}
double g2(double x) {
    return (pow(x, 2) + 1) / 3;
}
double g3(double x) {
    return -1 / (x - 3);
}
bool checkError(double x0,double x1) {
    return abs(x0 - x1) > epsilon;
}

// pass the funciton you want to execute
void calculateG(double (*func)(double)) {
    double x0 = getInitialX();
    double x1 = func(x0);
    do
    {
        x0 = x1;
        x1 = func(x0);
        cout << x1 << endl;
    } while (checkError(x0, x1));

    x0 = x1;
    x1 = func(x0);
    cout << "x0:" << x0 << endl;
    cout << "x1:" << x1 << endl;
    cout << "the answer is:" << abs(x0 - x1) << endl;
}
int main()
{
    calculateG(g3);
    return 0;
}
