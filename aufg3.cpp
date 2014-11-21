#include <iostream>
#include <cmath>
#include "amoeba.h"
using namespace std;

// Funktion deren Minimum bestmimt werden soll
double testFunktion(const VecDoub v)
{
	return (-exp( -(v[0] * v[0] + v[1] * v[1]) ) * exp( 4 * v[0] + 6 * v[1] - 13 ));
}

int main()
{
	// Startwerte
	const double startwerte[2] = { 40, -2 };
	VecDoub start(2, startwerte);

	// initial step size
	const double del = 10000;

	// function value at minimum
	double fmin;

	// Amoeben-Testsystem (dieses Objekt enthält die Minimalisierungs-Funktion)
	Amoeba testSystem;

	// startwert, step size, f(min), func: coords of minimum
	VecDoub ergebnis;

	//remove me

	try
	{
		ergebnis = testSystem.minimize( start, del, fmin, testFunktion );
	}
	catch ( const char * e )
	{
		cout << "ERROR: '" << e << "'" << endl;
		exit(1);
	}

	cout << "Minimum gefunden bei folgenden Koordinaten:" << endl;
	cout << "x1=" << ergebnis[0] << " x2=" << ergebnis[1] << endl;
	cout << "Die Test-Funktion hat an dieser Stelle folgenden Funktionswert:" << endl;
	cout << "f(x1, x2)=" << fmin << endl;

	// Das gesuchte Minimum bei (2,3) wird nicht mehr gefunden, sobald die Startwerte zu weit vom Minimum entfernt sind und die Schrittweite (del) zu klein gewählt ist. Beispielsweise findet der Algorithmus für die Startwerte (8,-2) und einer Schrittweite 0.1 nicht das Minimum (da der Gradient an dieser Stelle quasi Null ist). Für die selben Startwerte mit Schrittweite 1.0 wird die Lösung wieder erreicht.
}
