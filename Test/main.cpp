#include<iostream>
#include"motor.h"

using namespace std;

void main() {
	double tAtmosphere;
	cout << "Enter temperature:";
	cin >> tAtmosphere;
	motor motor1;
    double sec = motor1.work(tAtmosphere);
	printf("The time: %f seconds\n", sec);

	system("pause");
}