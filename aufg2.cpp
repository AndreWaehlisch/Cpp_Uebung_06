#include <iostream>
#include <cmath>
#include "helfer.h"
#include "minimization.h"


using namespace std;

class F
{
		double p, q, v, w;
	public:

		F (const double pi, const double qi, const double vi, const double wi)
		{
			p = pi;
			q = qi;
			v = vi;
			w = wi;
		}

		double operator  () (const double x)
		{
			return exp (-(x - p) * (x - p) / v) + exp (-(x + q) * (x + q) / w);
		}

		double df (const double x)
		{
			return -2 * (x - p) / v * exp (-(x - p) * (x - p) / v) - 2 * (x + q) / w * exp (-(x + q) * (x + q) / w);
		}

};



int
main ()
{
	int steps;

	double a = -.25, b = .25, c;
	double x, y;
	Bracketmethod br;
	Golden golden;
	Brent brent;
	DBrent dbrent;




	F f (1, 2, 100, 1);


	br.bracket (a, b, c, f);

	cout << "Bracketing: a = " << a << "  b = " << b << "  c = " << c << endl;

	golden.set (a, b, c);
	brent.set (a, b, c);
	dbrent.set (a, b, c);

	steps = golden.minimize (x, y, f);

	cout << "\nMethod\tSteps\tx_min\t\tf(x_min)" << endl;
	cout << "Golden\t" << steps << "\t" << x << "\t" << y << "\t" << endl;

	steps = brent.minimize (x, y, f);

	cout << "Brent\t" << steps << "\t" << x << "\t" << y << "\t" << endl;

	steps = dbrent.minimize (x, y, f);

	cout << "DBrent\t" << steps << "\t" << x << "\t" << y << "\t" << endl;

}
