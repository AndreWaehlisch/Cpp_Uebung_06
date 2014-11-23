#include <iostream>
#include <cmath>
using namespace std;

const double G = .61803398874;

double
f (const double x)
{
	return 12 * x * x - 6 * x + 4. / 3.;
}



double
newx (double a, double b, double c)
{
	if (c - b > b - a)
		return c - G * (c - b);
	else
		return a + G * (b - a);
}

double
minimize (double a, double b, double c, double epsilon)
{


	if (abs (a - c) < epsilon)
		return c;

	double x = newx (a, b, c);

	if (b < x)
	{
		if (f (b) < f (x))
			return minimize (a, b, x, epsilon);
		else
			return minimize (b, x, c, epsilon);
	}
	else
	{
		if (f (b) < f (x))
			return minimize (x, b, c, epsilon);
		else
			return minimize (a, x, b, epsilon);
	}

}




int
main ()
{

	cout << "Minimum bei " << minimize (-2., 1., 4., 0.0000001) << endl;

	// df/dx = 24 x - 6 == 0  =>  x = 6/24 = 0.25 == der vom numerischen Algorithmus gefundenen Nullstelle

}
