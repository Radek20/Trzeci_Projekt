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
    cout<<endl;

    if(test_1())
       { cout<<"test_1: PASS"<<endl; }
    else
       { cout<<"test_1: FAIL"<<endl; }

    if(test_2())
       { cout<<"test_2: PASS"<<endl; }
    else
       { cout<<"test_2: FAIL"<<endl; }

    if(test_3())
       { cout<<"test_3: PASS"<<endl; }
    else
       { cout<<"test_3: FAIL"<<endl; }

    cout<<endl;
}

bool test_1() /* test sprawdzajacy poprawnosc metody zmieniajacej numer rejestrcyjny */
{
    /* tworzenie pojazdu */
    string nreg="WW12446";
    string noc="123412340989";
    string vin="4857693";
    string mar="Renault";
    string pet="Prad";
    owner* own=new person(1,"Jan","Kowalski",0);
    string col="niebieski";
    int pow=140;
    int npe=4;
    double bat=2300;
    double ran=350;
    vehicle* test_vehicle;

    test_vehicle=new electric_car(nreg,noc,vin,mar,pet,own,col,pow,npe,bat,ran);
    test_vehicle->add_type(2);

    /* testowanie */
    string reg1="WR0559T";
    string reg2="OX00256";

    test_vehicle->change_reg(reg1);

    if(test_vehicle->preview_reg()!=reg1)
    { return false; }

    test_vehicle->change_reg(reg2);

    if(test_vehicle->preview_reg()==reg2)
    { return true; }
    else
    { return false; }
}

bool test_2() /* test sprawdzajacy poprawnosc metody zmieniajacej numer polisy OC */
{
    /* tworzenie pojazdu */
    string nreg="TX1244Z";
    string noc="345234657456";
    string vin="9475629";
    string mar="BMW";
    string pet="Pb";
    owner* own=new company(4,"FAJNA FIRMA");
    string col="czarny";
    double wei=5.5;
    double len=8;
    string pro="zywnosc";
    double loa=3;
    vehicle* test_vehicle;

    test_vehicle=new truck(nreg,noc,vin,mar,pet,own,col,wei,len,pro,loa);
    test_vehicle->add_type(5);

    /* testowanie */
    string oc1="234234234234";
    string oc2="555666444777";

    test_vehicle->add_OC(oc1);

    if(test_vehicle->preview_oc()!=oc1)
    { return false; }

    test_vehicle->add_OC(oc2);

    if(test_vehicle->preview_oc()==oc2)
    { return true; }
    else
    { return false; }
}

bool test_3() /* test sprawdzajacy poprawnosc metody zmieniajacej numer polisy OC */
{
    /* tworzenie pojazdu */
    string nreg="QW4444T";
    string noc="565645345657";
    string vin="4453478";
    string mar="Mazda";
    string pet="ON";
    owner* own=new company(4,"FAJNA FIRMA");
    string col="czerwony";
    double dis=2;
    int npe=2;
    double tan=16;
    double spe=250;
    double wei=1;
    vehicle* test_vehicle;

    test_vehicle=new jet_ski(nreg,noc,vin,mar,pet,own,col,dis,npe,tan,spe,wei);
    test_vehicle->add_type(8);

    /* testowanie */
    int num1=5;
    int num2=7;
    int co1=1;
    int co2=0;
    string company_name="LENIWIEC.SA";
    string person_name="Stanislaw";
    string person_surname="Beznazwiska";

    test_vehicle->change_owner(1,co1,num1,company_name);

    owner* test_owner1;
    test_owner1=test_vehicle->preview_owner();

    if(test_owner1->preview_name()!=company_name)
    { return false; }

    test_vehicle->change_owner(1,co2,num2,person_name,person_surname);

    owner* test_owner2;
    test_owner2=test_vehicle->preview_owner();

    if(test_owner2->preview_name()!=person_name)
    { return false; }

    if(test_owner2->preview_surname()==person_surname)
    { return true; }
    else
    { return false; }
}
