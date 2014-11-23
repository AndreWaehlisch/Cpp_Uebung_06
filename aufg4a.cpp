#include <iostream>
#include <cmath>
#include <fstream>
#include "anneal.h"
using namespace std;

int main ()
{
	// (Später optimierte) Reihenfolge der Städte
	VecInt r (8);

	for (int i = 0; i < 8; i++)
	{
		r[i] = i;
	}

	// x-Koordinate der einzelnen Städte
	const double x_coords[8] = { 2, 4, 1, 5, 2, 5, 4, 1 };
	VecDoub x (8, x_coords);

	// y-Koordinate der einzelnen Städte
	const double y_coords[8] = { 2, 2, 2, 2, 3, 0, 3, 0 };
	VecDoub y (8, y_coords);

	// Metrpolois-Algorithmus auf vorgegebene Städte anwenden (aus anneal.h)
	Anneal myAnneal;

	const double length = myAnneal.order (x, y, r);

	// Datei öffnen (und überschreiben)
	ofstream file ("handlungsreisender.txt", ios::trunc);

	// Einzelne Schritte der Reise
	for (int i = 0; i < 8; i++)
	{
		const int k = r[i];
		file << x[k] << '\t' << y[k] << endl;
	}

	// zurück zum Ausgangsort
	file << x[r[0]] << '\t' << y[r[0]] << endl;

	// Datei schließen
	file.close ();

	cout << "Ergebnis in handlungsreisender.txt geschrieben. Länge der Reise: " << length << endl;

	// Der Algorithmus berechnet die richtige Länge von 14 (Längeneinheiten), dies ist inklusive des Rückweges zum Ausgangsort.
}
