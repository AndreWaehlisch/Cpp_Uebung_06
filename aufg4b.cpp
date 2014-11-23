#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include "anneal.h"
using namespace std;

int main ()
{
	// Laufzeit des Kompletten Programms messen
	clock_t c1 = clock();

	Ran myRand;

	for (int stadt = 0; stadt < 3; stadt++)
	{
		int size;

		switch (stadt)
		{
			case 0:
				size = 4;
				break;

			case 1:
				size = 10;
				break;

			case 2:
				size = 1000;
				break;
		}

		// (Später optimierte) Reihenfolge der Städte
		VecInt r (size);

		for (int i = 0; i < size; i++)
		{
			r[i] = i;
		}

		// x-Koordinate der einzelnen Städte
		VecDoub x (size);

		for (int i = 0; i < size; i++)
		{
			x[i] = myRand.doub (0, 10);
		}

		// y-Koordinate der einzelnen Städte
		VecDoub y (size);

		for (int i = 0; i < size; i++)
		{
			y[i] = myRand.doub (0, 5);
		}

		// Metrpolois-Algorithmus auf vorgegebene Städte anwenden (aus anneal.h)
		Anneal myAnneal;

		const double length = myAnneal.order (x, y, r);

		if (stadt == 2)
		{
			// Datei öffnen (und überschreiben)
			ofstream file ("test.txt", ios::trunc);

			// Einzelne Schritte der Reise
			for (int i = 0; i < size; i++)
			{
				const int k = r[i];
				file << x[k] << '\t' << y[k] << endl;
			}

			// zurück zum Ausgangsort
			file << x[r[0]] << '\t' << y[r[0]] << endl;

			// Datei schließen
			file.close ();

			cout << "[Ergebnis für N=1000 in die Datei 'test.txt' geschrieben.]" << endl;
		}

		cout << "Anzahl der Städte: " << size << " Länge der Reise: " << length << endl;
	}

	clock_t c2 = clock();

	cout << "Laufzeit des Programms: " << (c2 - c1) / double(CLOCKS_PER_SEC) << " secs" << endl;
	// Laufzeit mit -O3 flag: ca. 11s
	// Laufzeit mit -O2 flag: ca. 12s
	// Laufzeit mit -O1 flag: ca. 12s
	// Laufzeit ohne -O flag: ca. 23s
	// Ergebnis: Die Optimierung des Compilers kann in diesem Fall die Laufzeit um bis zu ca. 50% reduzieren!
}
