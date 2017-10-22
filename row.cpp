// vim: ts=2 sw=2 encoding=utf8
/*  PROGRAM: Rownania rozniczkowe
 *  WERSJA: 0.1
 *  Autor: Artur GRACKI mailto: arteq(at)arteq(dot)org
 *  OSTATNIA MODYFIKACJA: 2007/07/11 (śro) 01:03:51
 *  KEYWORDS: dynamika chaotyczna, uklad Rosslera, rownania rozniczkowe, generyczny, dynamika nieliniowa, calkowanie
 */

#include	<iostream>

using namespace std;

/* ====================================================================== */

double dx(double x, double y, double z)
{
	return -y - z;
}

/* ====================================================================== */

double dy(double x, double y, double z)
{
	return x + 0.3 * y;
}

/* ====================================================================== */

double dz(double x, double y, double z)
{
	return 0.5 + x * z - 5.3 * z;
}

/* ====================================================================== */

int main()
{
	// Warunki poczatkowe dla t = 10
	double x1, x0 = 0.2;
	double y1, y0 = 0.3;
	double z1, z0 = 0.4;
	
	// Krok
	double dT = 0.1;

	// Czas poczatkowy i koncowy
	double tS = 10, tK = 400;

	// Krok calkowania
	double h = 0.01;
	double k1, k2, k3, k4;


	int ile_pkt = (int)((tK - tS) / dT);

	for (int i = 0; i < ile_pkt; i++)
	{
		k1 = dx(x0, y0, z0);
		k2 = dx(x0 + h/2.0 * k1, y0, z0);
		k3 = dx(x0 + h/2.0 * k2, y0, z0);
		k4 = dx(x0 + h * k3, y0, z0);
		x1 = x0 + h * (k1 + 2*k2 + 2*k3 + k4)/6.0;

		k1 = dy(x0, y0, z0);
		k2 = dy(x0, y0 + h/2.0 * k1, z0);
		k3 = dy(x0, y0 + h/2.0 * k2, z0);
		k4 = dy(x0, y0 + h * k3, z0);
		y1 = y0 + h * (k1 + 2*k2 + 2*k3 + k4)/6.0;

		k1 = dz(x0, y0, z0);
		k2 = dz(x0, y0, z0 + h/2.0 * k1);
		k3 = dz(x0, y0, z0 + h/2.0 * k2);
		k4 = dz(x0, y0, z0 + h * k3);
		z1 = z0 + h * (k1 + 2*k2 + 2*k3 + k4)/6.0;

		x0 = x1;
		y0 = y1;
		z0 = z1;

		cout << x1 << "\t" << y1 << "\t" << z1 << "\n";
	}

	return 0;
}
