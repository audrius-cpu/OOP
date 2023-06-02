#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

struct studentas
{
    string vardas, pavarde;
    int* pazymiai;
    int pazymiu_kiekis;
    int egzaminas;
    double vidurkis, mediana;
};