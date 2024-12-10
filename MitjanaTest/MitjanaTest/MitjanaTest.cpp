#include <iostream>
using namespace std;
double avg (double x, double y);

void main()
{
    double a = 1.2;
    double b = 2.7;
    cout << "Avg is " << avg(a, b);
    cout << endl;
    cout << endl;
    system("PAUSE");
}

double avg(double x, double y) {
    double v = (x + y) / 2;
    return v;
}


