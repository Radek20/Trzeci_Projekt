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

void ADD_VEHICLE() /* funkcja odpowiedzialna za dodawanie pojazdu do systemu */
{
    int co=0; /* zmienna decyzyjna, odpowiada za stworzenie pojazdu wybranego przez uzytkownika */

    cout<<"Jaki pojazd chcesz dodac? wpisz: \n1-smochod\n2-samochod elektrycny\n3-motocykl\n4-tramwaj\n5-ciezarowke\n6-autobus\n7-motorowke\n8-skuter wodny\n9-okret\n10-kontenrowiec"<<endl;
    while(!(cin>>co))  /* podjecie decyzji, wykrywanie bledu */
    {
        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
        cin.clear();
        cin.ignore(9999, '\n' );
        cout<<endl;
    }

    ile++;  /* zwiekszenie ilosci pojazdow w systemie */

    switch(co)  /* tworzenie odpowiedniego pojazdu */
    {
        case 1: { tab[ile-1]=new normal_car;    tab[ile-1]->add_type(1);  break; }
        case 2: { tab[ile-1]=new electric_car;  tab[ile-1]->add_type(2);  break; }
        case 3: { tab[ile-1]=new motorcycle;    tab[ile-1]->add_type(3);  break; }
        case 4: { tab[ile-1]=new tram;          tab[ile-1]->add_type(4);  break; }
        case 5: { tab[ile-1]=new truck;         tab[ile-1]->add_type(5);  break; }
        case 6: { tab[ile-1]=new bus;           tab[ile-1]->add_type(6);  break; }
        case 7: { tab[ile-1]=new motorboat;     tab[ile-1]->add_type(7);  break; }
        case 8: { tab[ile-1]=new jet_ski;       tab[ile-1]->add_type(8);  break; }
        case 9: { tab[ile-1]=new ship;          tab[ile-1]->add_type(9);  break; }
        case 10: { tab[ile-1]=new freegan;      tab[ile-1]->add_type(10); break; }
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

    cout<<"Podaj numer (w systemie) pojazdu, ktorego numer rejestracyjny chcesz zmienic:"<<endl;
    while(!(cin>>x)) /* wybranie pojazdu, wykrywanie bledu */
    {
        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
        cin.clear();
        cin.ignore(9999, '\n' );
        cout<<endl;
    }

    tab[x]->change_reg(); /* zmiana numeru */
    cout<<endl<<"NUMER REJESTRACYJNY ZMIENIONY!"<<endl<<endl;
}

void OC_ADD() /* funkcja odpowiedzialna za dodanie OC pojazdu */
{
    int x=0; /* zmienna odpowiedzialna za przechowanie informacji o numerze pojazdu do ktorego nalezy przypisac OC */

    cout<<"Podaj numer (w systemie) pojazdu, ktorego OC chcesz dodac:"<<endl;
    while(!(cin>>x)) /* wybranie pojazdu, wykrywanie bledu */
    {
        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
        cin.clear();
        cin.ignore(9999, '\n' );
        cout<<endl;
    }

    tab[x]->add_OC(); /* dodanie numeru OC */
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
