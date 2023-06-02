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

void pazymiu_nuskaitymas(studentas& tmp)
{
    string ivestis;
    cout << "Pasirinkite pazymiu ivedimo metoda ('R' - ranka, 'A' - automatiskai): ";
    cin >> ivestis;

    if (ivestis == "R" || ivestis == "r")
    {
        int paz;
        string nutraukimas;

        tmp.pazymiai = new int[1];
        tmp.pazymiu_kiekis = 0;
        int talpa = 1;

        do
        {
            cout << "Iveskite studento pazymi[1-10]: ";
            while (!(cin >> paz) || paz > 10 || paz < 1)
            {
                cin.clear();
                cin.ignore();
                cout << "Jusu ivestas skaicius turi buti [1-10]. Bandykite dar karta: ";
            }

            if (tmp.pazymiu_kiekis == talpa)
            {
                talpa *= 2;
                int* nauji_pazymiai = new int[talpa];
                for (int i = 0; i < tmp.pazymiu_kiekis; i++)
                    nauji_pazymiai[i] = tmp.pazymiai[i];
                delete[] tmp.pazymiai;
                tmp.pazymiai = nauji_pazymiai;
            }

            tmp.pazymiai[tmp.pazymiu_kiekis] = paz;
            tmp.pazymiu_kiekis++;

            cout << "Pazymiu vedimo nutraukimas 'N', Tesimas 'Betkoks simbolis': ";
            cin >> nutraukimas;
        } while (nutraukimas != "N" && nutraukimas != "n");
    }
    else if (ivestis == "A" || ivestis == "a")
    {
        int rand_kiekis;
        cout << "Iveskite pazymiu skaiciu, kuris bus sugeneruotas atsitiktinai: ";
        cin >> rand_kiekis;

        tmp.pazymiai = new int[rand_kiekis];
        tmp.pazymiu_kiekis = rand_kiekis;

        for (int i = 0; i < rand_kiekis; i++)
        {
            int paz = rand() % 10 + 1;
            cout << paz << " ";
            tmp.pazymiai[i] = paz;
        }
        cout << endl;
    }
}

void vidurkio_radimas(studentas& tmp)
{
    double sum = 0;

    for (int i = 0; i < tmp.pazymiu_kiekis; i++)
    {
        sum += tmp.pazymiai[i];
    }

    tmp.vidurkis = sum / tmp.pazymiu_kiekis;
}

void medianos_radimas(studentas& tmp)
{
    sort(tmp.pazymiai, tmp.pazymiai + tmp.pazymiu_kiekis);

    int vidurinis = tmp.pazymiu_kiekis / 2;
    if (tmp.pazymiu_kiekis % 2 == 0)
        tmp.mediana = (tmp.pazymiai[vidurinis - 1] + tmp.pazymiai[vidurinis]) / 2.0;
    else
        tmp.mediana = tmp.pazymiai[vidurinis];
}