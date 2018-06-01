#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int result; /* zmienna zliczajaca wszystkie porazki */

#include "test.h"
#include "owner.h"
#include "vehicle.h"
#include "function.h"

void TEST()
{
    vehicle* test_vehicle; /* testowy pojazd */
    int de=0, pom=1; /* zmienne pomonicza */
    int fail=0; /* zmienna liczaca bledy */

    cout<<endl<<"Aby przetestowac metody dodaj testowy pojazd"<<endl;
    int co=0; /* zmienna decyzyjna, odpowiada za stworzenie pojazdu wybranego przez uzytkownika */

    cout<<"Jaki pojazd chcesz dodac? wpisz: \n1-smochod\n2-samochod elektrycny\n3-motocykl\n4-tramwaj\n5-ciezarowke\n6-autobus\n7-motorowke\n8-skuter wodny\n9-okret\n10-kontenrowiec"<<endl;
    while(!(cin>>co))  /* podjecie decyzji, wykrywanie bledu */
    {
        cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
        cin.clear();
        cin.ignore(9999, '\n' );
        cout<<endl;
    }

    switch(co)  /* tworzenie odpowiedniego pojazdu */
    {
        case 1: { test_vehicle=new normal_car;    test_vehicle->add_type(1);  break; }
        case 2: { test_vehicle=new electric_car;  test_vehicle->add_type(2);  break; }
        case 3: { test_vehicle=new motorcycle;    test_vehicle->add_type(3);  break; }
        case 4: { test_vehicle=new tram;          test_vehicle->add_type(4);  break; }
        case 5: { test_vehicle=new truck;         test_vehicle->add_type(5);  break; }
        case 6: { test_vehicle=new bus;           test_vehicle->add_type(6);  break; }
        case 7: { test_vehicle=new motorboat;     test_vehicle->add_type(7);  break; }
        case 8: { test_vehicle=new jet_ski;       test_vehicle->add_type(8);  break; }
        case 9: { test_vehicle=new ship;          test_vehicle->add_type(9);  break; }
        case 10: { test_vehicle=new freegan;      test_vehicle->add_type(10); break; }
    }

    cout<<endl<<"WCZYTANE DANE:"<<endl;
    test_vehicle->show(); /* wypisywanie szczegolow */

    cout<<endl<<"Czy dane zostaly wprowadzone poprawnie?\n1-TAK\n2-NIE"<<endl;
    cin>>de;
    if(de==2)
    { fail++; }
    de=0;

    while (pom==1)
    {
        cout<<"Ktora funkcje chcesz przetestowac?\n1-zmiana numeru rejestracyjnego\n2-dodanie OC\n3-zmiana wlasciciela"<<endl;
        cin>>de;
        switch(de)  /* wykonanie funkcji wybranej przez uzytkownika */
        {
            case 1: { test_vehicle->change_reg();     break; }
            case 2: { test_vehicle->add_OC();         break; }
            case 3: { test_vehicle->change_owner();   break; }
        }
        cout<<endl<<"DANE PO WYKONANEJ FUNKCJI:"<<endl;
        test_vehicle->show();

        cout<<endl<<"Czy metoda zadzialala poprawnie?\n1-TAK\n2-NIE"<<endl;
        cin>>de;
        if(de==2)
        { fail++; }
        de=0;

        if(fail==0)
        { cout<<endl<<"TEST ZALICZONY! :)"<<endl; }
        else
        {
            cout<<endl<<"TEST NIE ZALICZONY! :("<<endl;
            result++;
        }

        cout<<endl<<"Czy chcesz kontynuowac testowanie?\n1-TAK\n2-NIE"<<endl;
        cin>>pom;
        fail=0;
    }


    if(result==0)
    { cout<<endl<<"WSZYSTKIE TESTY ZALICZONE!"<<endl; }
    else
    {
        cout<<endl<<"COS POSZLO NIE TAK!"<<endl;
    }

    cout<<endl;

    result=0;
    delete test_vehicle; /*usuwanie testowego pojazdu */

}
