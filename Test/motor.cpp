#include "motor.h"
#include<cmath>

	double tOverheat = 110;
	double I = 0.1;
	double HM = 0.01;
	double HV = 0.0001;
	double C = 0.1;
	int M[6] = { 20, 75, 100, 105, 75, 0 };
	int V[6] = { 0, 75, 150, 200, 250, 300 };
	double VH, VC;

	double motor:: work(double tAtmosphere) {
		double tMotor = tAtmosphere;
		double timeOverheat = 0, a = 0;
		int index = 0;
		while (tMotor < tOverheat) {
			a = M[index] * I;
			if (V[index] + a >= V[index + 1] && index <= 5) {
				index++;
			}
			VH = M[index] * HM + pow(V[index], 2) * HV;
			VC = C * (tAtmosphere - tMotor);
			tMotor = tMotor + VH - VC;
			timeOverheat++;
		}
		return timeOverheat;
	}
