#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "function.h"
#include "owner.h"
#include "vehicle.h"
#include "test.h"

vehicle* tab[100]; /* tablica wskaznikow na pojazdy */
int ile; /* zmienna przechowujaca informacje o ilosci pojazdow wpisanych do systemu */

void LIST() /* funkcja tworzaca i wypisujaca liste pojazdow  */
{
    /* wypisanie nagowkow */
    cout<<endl<<setw(20)<<left<<"NUMER W SYSTEMIE"<<setw(20)<<left<<"REJESTRACJA"<<setw(20)<<left<<"POLISA OC"<<setw(20)<<left<<"NUMER VIN"<<setw(25)<<left<<"TYP"<<setw(20)<<left<<"MARKA"<<endl;
    /* wypisanie pojazdow */
    for(int i=0;i<ile;i++)
    {
        cout<<setw(20)<<left<<i;
        tab[i]->list();
    }
    cout<<endl;
}

owner* OWNER(int mode)
{
    owner* proprietor;

        int number;
        int pomo;


        if(mode==0)
        {
            cout<<"Wybierz 1-jesli wlascicielem jest osoba prywatna lub 2-jesli firma"<<endl;
            while(!(cin>>pomo)) /* wczytywanie zmiennej, wykrywanie bledu */
            {
                cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                cin.clear();
                cin.ignore(9999, '\n' );
                cout<<endl;
            }
            cout<<endl<<"WPROWADZ DANE WLASCICIELA:"<<endl<<endl;
        }
        else
        { pomo=1; }

        cout<<"Podaj numer wlasciciela"<<endl;

        while(!(cin>>number)) /* wczytywanie numeru, wykrywanie bledu */
        {
            cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
            cin.clear();
            cin.ignore(9999, '\n' );
            cout<<endl;
        }

        if(pomo==1) /* przypisywanie wlasciciela */
        {
            string name;
            string surname;
            int pom;
            owner* co_owner;

            cout<<"Podaj imie"<<endl;
            cin>>name;

            cout<<"Podaj nazwisko"<<endl;
            cin>>surname;

            cout<<"Czy chcesz dodac wspolwlasciciela?\n1-tak\n0-nie"<<endl;
            while(!(cin>>pom))/* wczytywanie informacji o wspolwlascicielu, wykrywanie bledu */
            {
                cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                cin.clear();
                cin.ignore(9999, '\n' );
                cout<<endl;
            }

            if(pom!=0)
            {
                cout<<"PODAJ DANE WSPOLWLASCICIELA"<<endl;
                co_owner=OWNER(1);
                proprietor=new person(number,name,surname,1,co_owner);
            }
            else
            { proprietor=new person(number,name,surname,0); }
        }
        else
        {
            string name;
            cout<<"Podaj nazwe firmy"<<endl;
            cin.clear();
            cin.ignore(9999, '\n' );
            getline(cin, name);

            proprietor=new company(number,name);
        }

    return proprietor;
}

owner* OWNER2(int co, int num, string nam, string sur)
{
    owner* proprietor;

    if(co==0)
    { proprietor=new person(num,nam,sur,0); }
    else
    { proprietor=new company(num,nam); }

    return proprietor;
}
void ADD_VEHICLE() /* funkcja odpowiedzialna za dodawanie pojazdu do systemu */
{
    int co=0; /* zmienna decyzyjna, odpowiada za stworzenie pojazdu wybranego przez uzytkownika */

    int pomo;
    string reg_number, OC_number, VIN, mark, petrol;
    owner* proprietor;
    ile++;  /* zwiekszenie ilosci pojazdow w systemie */

    /* wczytywanie wspolcych atrybutow */
    cout<<"Jaki pojazd chcesz dodac? wpisz: \n1-smochod\n2-samochod elektryczny\n3-motocykl\n4-tramwaj\n5-ciezarowke\n6-autobus\n7-motorowke\n8-skuter wodny\n9-okret\n10-kontenrowiec"<<endl;
    while(!(cin>>co))  /* podjecie decyzji, wykrywanie bledu */
    {
        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
        cin.clear();
        cin.ignore(9999, '\n' );
        cout<<endl;
    }

    cout<<endl<<"WPROWADZANIE NOWEGO POJAZDU:"<<endl<<endl;

    proprietor=OWNER(0);

    cout<<"Podaj numer rejestracyjny"<<endl;
    cin>>reg_number;

    cout<<"Podaj 12 znakowy numer polisy OC"<<endl;
    cin>>OC_number;

    cout<<"Podaj 7 znakowy numer VIN"<<endl;
    cin>>VIN;

    cout<<"Podaj marke pojazdu"<<endl;
    cin>>mark;

    cout<<"Podaj rodzaj paliwa (Pb, ON, Prad)"<<endl;
    cin>>petrol;

    switch(co)  /* tworzenie odpowiedniego pojazdu */
    {
        case 1: {
                    string colour;
                    int power;
                    int nperson;
                    double tank;
                    double speed;

                    cout<<"Podaj kolor"<<endl;
                    cin>>colour;

                    cout<<"Podaj moc w KM"<<endl;
                    while(!(cin>>power))/* wczytywanie informacji o mocy silnika, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj dopuszczalna ilosc osob"<<endl;
                    while(!(cin>>nperson))/* wczytywanie informacji o ilosci miejsc, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj pojemnosc baku w l"<<endl;
                    while(!(cin>>tank)) /* wczytywanie informacji o pojemnosci baku, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj maksymalna predkosc"<<endl;
                    while(!(cin>>speed)) /* wczytywanie informacji o maksymalnej predkosci, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    tab[ile-1]=new normal_car(reg_number,OC_number,VIN,mark,petrol,proprietor,colour,power,nperson,tank,speed);
                    tab[ile-1]->add_type(1);
                    break;
                }
        case 2: {
                    string colour;
                    int power;
                    int nperson;
                    double battery;
                    double range;

                    cout<<"Podaj kolor"<<endl;
                    cin>>colour;

                    cout<<"Podaj moc w KM"<<endl;
                    while(!(cin>>power))/* wczytywanie informacji o mocy silnika, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj dopuszczalna ilosc osob"<<endl;
                    while(!(cin>>nperson))/* wczytywanie informacji o ilosci miejsc, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj pojemnosc akumulatora w mAh"<<endl;
                    while(!(cin>>battery))/* wczytywanie informacji o pojemnosci baterii, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj maksymalny zasieg w km"<<endl;
                    while(!(cin>>range))/* wczytywanie informacji o maksymalny zasieg, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    tab[ile-1]=new electric_car(reg_number,OC_number,VIN,mark,petrol,proprietor,colour,power,nperson,battery,range);
                    tab[ile-1]->add_type(2);
                    break;
                }
        case 3: {

                    string model;
                    double speed;
                    double accelerate;

                    cout<<"Podaj model"<<endl;
                    cin>>model;

                    cout<<"Podaj maksymalna predkosc w km/h"<<endl;
                    while(!(cin>>speed)) /* wczytywanie informacji o maksymalnej predkosci, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj przyspieszenie w m/s^2"<<endl;
                    while(!(cin>>accelerate)) /* wczytywanie informacji o przyspieszeniu, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    tab[ile-1]=new motorcycle(reg_number,OC_number,VIN,mark,petrol,proprietor,model,speed,accelerate);
                    tab[ile-1]->add_type(3);
                    break;
                }
        case 4: {
                    string colour;
                    double weight;
                    string model;
                    double age;

                    cout<<"Podaj kolor"<<endl;
                    cin>>colour;

                    cout<<"Podaj mase w tonach"<<endl;
                    while(!(cin>>weight)) /* wczytywanie informacji o wadze, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj model"<<endl;
                    cin>>model;

                    cout<<"Podaj wiek"<<endl;
                    while(!(cin>>age)) /* wczytywanie informacji o wieku, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    tab[ile-1]=new tram(reg_number,OC_number,VIN,mark,petrol,proprietor,colour,weight,model,age);
                    tab[ile-1]->add_type(4);
                    break;
                }
        case 5: {
                    string colour;
                    double weight;
                    double lenght;
                    string product;
                    double load;

                    cout<<"Podaj kolor"<<endl;
                    cin>>colour;

                    cout<<"Podaj mase w tonach"<<endl;
                    while(!(cin>>weight)) /* wczytywanie informacji o wadze, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj dlugosc pojazdu w m"<<endl;
                    while(!(cin>>lenght)) /* wczytywanie informacji o dlugosci, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj rodzaj przewozonych towarow"<<endl;
                    cin>>product;

                    cout<<"Podaj ladownosc ciezarowki w tonach"<<endl;
                    while(!(cin>>load)) /* wczytywanie informacji o ladownosci, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj dlugosc pojazdu w m"<<endl;
                    while(!(cin>>lenght)) /* wczytywanie informacji o dlugosci, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj rodzaj przewozonych towarow"<<endl;
                    cin>>product;

                    cout<<"Podaj ladownosc ciezarowki w tonach"<<endl;
                    while(!(cin>>load)) /* wczytywanie informacji o ladownosci, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    tab[ile-1]=new truck(reg_number,OC_number,VIN,mark,petrol,proprietor,colour,weight,lenght,product,load);
                    tab[ile-1]->add_type(5);
                    break;
                }
        case 6: {
                    string colour;
                    double weight;
                    double lenght;
                    int passenger;

                     cout<<"Podaj kolor"<<endl;
                    cin>>colour;

                    cout<<"Podaj mase w tonach"<<endl;
                    while(!(cin>>weight)) /* wczytywanie informacji o wadze, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj dlugosc pojazdu w m"<<endl;
                    while(!(cin>>lenght)) /* wczytywanie informacji o dlugosci, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj maksymalna ilosc pasazerow"<<endl;
                    while(!(cin>>passenger)) /* wczytywanie informacji o maksymalnej liczbie pasazerow, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    tab[ile-1]=new bus(reg_number,OC_number,VIN,mark,petrol,proprietor,colour,lenght,weight,passenger);
                    tab[ile-1]->add_type(6);
                    break;
                }
        case 7: {
                    string colour;
                    double displacement;
                    int nperson;
                    double tank;
                    double speed;

                    cout<<"Podaj kolor"<<endl;
                    cin>>colour;

                    cout<<"Podaj wypornosc w tonach"<<endl;
                    while(!(cin>>displacement)) /* wczytywanie informacji o wypornosci, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj dopuszczalna ilosc osob"<<endl;
                    while(!(cin>>nperson)) /* wczytywanie informacji o maksymalnej ilosci osob na pokladzie, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj pojemnosc baku w l"<<endl;
                    while(!(cin>>tank)) /* wczytywanie informacji o pojemnosci baku, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj maksymalna predkosc"<<endl;
                    while(!(cin>>speed)) /* wczytywanie informacji o maksymalnej predkosci, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    tab[ile-1]=new motorboat(reg_number,OC_number,VIN,mark,petrol,proprietor,colour,displacement,nperson,tank,speed);
                    tab[ile-1]->add_type(7);
                    break;
                }
        case 8: {
                    string colour;
                    double displacement;
                    int nperson;
                    double tank;
                    double speed;
                    double weight;

                    cout<<"Podaj kolor"<<endl;
                    cin>>colour;

                    cout<<"Podaj wypornosc w tonach"<<endl;
                    while(!(cin>>displacement)) /* wczytywanie informacji o wypornosci, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj dopuszczalna ilosc osob"<<endl;
                    while(!(cin>>nperson)) /* wczytywanie informacji o maksymalnej ilosci osob na pokladzie, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj pojemnosc baku w l"<<endl;
                    while(!(cin>>tank)) /* wczytywanie informacji o pojemnosci baku, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj maksymalna predkosc"<<endl;
                    while(!(cin>>speed)) /* wczytywanie informacji o maksymalnej predkosci, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj wage"<<endl;
                    while(!(cin>>weight)) /* wczytywanie informacji o wadze, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    tab[ile-1]=new jet_ski(reg_number,OC_number,VIN,mark,petrol,proprietor,colour,displacement,nperson,tank,speed,weight);
                    tab[ile-1]->add_type(8);
                    break;
                }
        case 9: {
                    string colour;
                    double displacement;
                    int nperson;
                    string exploitation;

                    cout<<"Podaj kolor"<<endl;
                    cin>>colour;

                    cout<<"Podaj wypornosc w tonach"<<endl;
                    while(!(cin>>displacement)) /* wczytywanie informacji o wypornosci, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj dopuszczalna ilosc osob"<<endl;
                    while(!(cin>>nperson)) /* wczytywanie informacji o maksymalnej ilosci osob na pokladzie, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj do jakich celow wykorzystywany jest okret"<<endl;
                    cin>>exploitation;

                    tab[ile-1]=new ship(reg_number,OC_number,VIN,mark,petrol,proprietor,colour,displacement,nperson,exploitation);
                    tab[ile-1]->add_type(9);
                    break;
                }
        case 10: {  string colour;
                    double displacement;
                    int nperson;
                    double load;
                    double incineration;

                    cout<<"Podaj kolor"<<endl;
                    cin>>colour;

                    cout<<"Podaj wypornosc w tonach"<<endl;
                    while(!(cin>>displacement)) /* wczytywanie informacji o wypornosci, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj dopuszczalna ilosc osob"<<endl;
                    while(!(cin>>nperson)) /* wczytywanie informacji o maksymalnej ilosci osob na pokladzie, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj ladownosc w tonach"<<endl;
                    while(!(cin>>load)) /* wczytywanie informacji o ladownosci, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    cout<<"Podaj spalanie w l/h"<<endl;
                    while(!(cin>>incineration)) /* wczytywanie informacji o spalaniu, wykrywanie bledu */
                    {
                        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
                        cin.clear();
                        cin.ignore(9999, '\n' );
                        cout<<endl;
                    }

                    tab[ile-1]=new freegan(reg_number,OC_number,VIN,mark,petrol,proprietor,colour,displacement,nperson,load, incineration);
                    tab[ile-1]->add_type(10);
                    break;
                }
    }
    cout<<endl<<"POJAZD ZOSTAL DODANY!"<<endl<<endl;
}

void SHOW_DETAILS() /* funkcja odpowiedzialan za wyswietlenie szczegolowych informacji o pojezdzie */
{
    int x=0; /* zmienna odpowiedzialna za przechowanie informacji o numerze pojazdu ktorego informacje maja byc wyswietlone */

    cout<<"Podaj numer (w systemie) pojazdu, ktorego szczegoly maja byc wyswietlone:"<<endl;
    while(!(cin>>x)) /* wybranie pojazdu, wykrywanie bledu */
    {
        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
        cin.clear();
        cin.ignore(9999, '\n' );
        cout<<endl;
    }

    cout<<endl;
    tab[x]->show(); /* wyswietlenie informacji */
    cout<<endl;
}

void RE_REGISTER() /* funkcja odpowiedzialna za zmiane numeru rejestracyjnego pojazdu */
{
    int x=0; /* zmienna odpowiedzialna za przechowanie informacji o numerze pojazdu ktorego rejestracja ma zostac zmieniona */
    string reg_number;
    cout<<"Podaj numer (w systemie) pojazdu, ktorego numer rejestracyjny chcesz zmienic:"<<endl;
    while(!(cin>>x)) /* wybranie pojazdu, wykrywanie bledu */
    {
        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
        cin.clear();
        cin.ignore(9999, '\n' );
        cout<<endl;
    }

    cout<<"Podaj nowy numer rejestracyjny"<<endl;
    cin>>reg_number;

    tab[x]->change_reg(reg_number); /* zmiana numeru */
    cout<<endl<<"NUMER REJESTRACYJNY ZMIENIONY!"<<endl<<endl;
}

void OC_ADD() /* funkcja odpowiedzialna za dodanie OC pojazdu */
{
    int x=0; /* zmienna odpowiedzialna za przechowanie informacji o numerze pojazdu do ktorego nalezy przypisac OC */
    string OC_number;

    cout<<"Podaj numer (w systemie) pojazdu, ktorego OC chcesz dodac:"<<endl;
    while(!(cin>>x)) /* wybranie pojazdu, wykrywanie bledu */
    {
        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
        cin.clear();
        cin.ignore(9999, '\n' );
        cout<<endl;
    }

    cout<<"Podaj 12 znakowy numer polisy OC"<<endl;
    cin>>OC_number;

    tab[x]->add_OC(OC_number); /* dodanie numeru OC */
    cout<<endl<<"NUMER OC ZMIENIONY!"<<endl<<endl;
}

void CHANGE_OWNER() /* funkcja odpowiedzialna za zmiane wlasciciela */
{
    int x=0; /* zmienna odpowiedzialna za przechowanie informacji o numerze pojazdu ktorego rejestracja ma zostac zmieniona */

    cout<<"Podaj numer (w systemie) pojazdu, ktorego numer rejestracyjny chcesz zmienic:"<<endl;
    while(!(cin>>x)) /* wybranie pojazdu, wykrywanie bledu */
    {
        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
        cin.clear();
        cin.ignore(9999, '\n' );
        cout<<endl;
    }

    tab[x]->change_owner(); /* zmiana wlasciciela */
    cout<<endl<<"WLASCICIEL ZOSTAL ZMIENIONY!"<<endl<<endl;
}

void MENU() /* funkcja odpowiedzialna za tworzenie menu */
{
    int d=0;  /* zmienna odpowiadajaca z podjecie decyzji */
    cout<<"Co chcesz zrobic? Podaj numer:\n1-dodac nowy pojazd\n2-wyswietlic liste pojazdow\n3-wyswietlic szczegoly wybranego pojazdu\n4-zmienic numer rejestracyjny wybranego pojazdu\n5-dodac OC\n6-zmien wlasciciela wybranego pojazdu\n7-wykonaj testy\n8-zakoncz program"<<endl;

    while(!(cin>>d)) /*podjecie decyzji, wykrywanie bledu */
    {
        cout << "Blad! To nie jest liczba, podaj jeszcze raz: ";
        cin.clear();
        cin.ignore(9999, '\n' );
        cout<<endl;
    }

    switch(d)  /* wykonanie funkcji wybranej przez uzytkownika */
    {
        case 1: { ADD_VEHICLE();     break; }
        case 2: { LIST();            break; }
        case 3: { SHOW_DETAILS();    break; }
        case 4: { RE_REGISTER();     break; }
        case 5: { OC_ADD();          break; }
        case 6: { CHANGE_OWNER();    break; }
        case 7: { TEST();            break; }
    }

    if(d!=8)  /* po wyknaniu funkcji i sprawdzeniu czy nie zostala podjeta decyzja o zakonczeniu powrot do menu */
    { MENU(); }
}

void END() /* funkcja odpowiedzialna za usuniecie stworzonych pojazdow */
{
    for(int i=0;i<ile;i++) /* usuwanie */
    { delete tab[i]; }
}
