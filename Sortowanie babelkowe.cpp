#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;
const int ile_elem = 100;

void Losowanie(float tab[], int ile)
{   // Losowanie zadaniej ilości liczb rzeczywistych z zakresu od 1 do 100
    for (int i = 0; i < ile; i++)
        tab[i] = 99.0 * rand() / RAND_MAX + 1;
}

void Wypisz(float tab[], int ile)
{   // Wypisanie aktualnej zawartości podanej tablicy (z precyzją do 3 cyfr łacznie przed i po przecinku)
    for (int i = 0; i < ile; i++)
        cout << setprecision(3) << tab[i] << "\t";

    cout << endl << endl;
}

void zamiana(float& a, float& b) // Praca na przekazanych zmiennych a nie liczbach
{
    float pomoc = a;
    a = b;
    b = pomoc;
}

void Sortowanie(float tab[], int ile)
{
    //Sortowanie bąbelkowe ze strażnikiem

    bool straznik;
    do
    {
        straznik = 0;
        for (int j = 0; j < (ile - 1); j++)
            if (tab[j] > tab[j + 1])
            {
                zamiana(tab[j], tab[j + 1]);
                straznik = 1;
            }
    } while (straznik); //ponowne przeglądanie tablicy o ile ostatnio były jakieś zamiany
}

int main(int argc, char* argv[])
{
    srand(time(NULL));              // Start generatora liczb pseudolosowych
    float Tablica[ile_elem];        // Stworzenie tablicy o zadanej ilości elementów

    Losowanie(Tablica, ile_elem);   // Zapełnienie tablicy losowymi liczbami
    Wypisz(Tablica, ile_elem);      // Wypisanie zawartości tablicy przed sortowaniem

    Sortowanie(Tablica, ile_elem);  // Sortowanie
    Wypisz(Tablica, ile_elem);      // Wypisanie zawartości tablicy po dokonanym sortowaniu


    system("PAUSE");
    return EXIT_SUCCESS;
}
