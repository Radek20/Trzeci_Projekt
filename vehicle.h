#ifndef vehicle_h
#define vehicle_h

class vehicle /* klasa bazowa reprezentujaca pojazdy */
{
    protected:
    string reg_number; /* numer rejestracyjny */
    string OC_number; /* numer OC */
    string VIN; /* numer VIN */
    string type; /* typ pojazdu */
    string mark; /* marka */
    string petrol; /* rodzaj paliwa */
    int pomo; /* zmienna pomocnicza przechowujaca informacje czy wlascicielem jest osoba prywatna czy firma */
    person* proprietor1; /* wskaznik na wlasciciela - osoba prywatna */
    company* proprietor2; /* wskaznik na wlasciciela - firma */

    public:
    vehicle() /* konstruktor */
    {
        cout<<endl<<"WPROWADZANIE NOWEGO POJAZDU:"<<endl<<endl;

        cout<<"Wybierz 1-jesli wlascicielem jest osoba prywatna lub 2-jesli firma"<<endl;
        while(!(cin>>pomo)) /* wczytywanie zmiennej, wykrywanie bledu */
        {
            cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
            cin.clear();
            cin.ignore(9999, '\n' );
            cout<<endl;
        }

        if(pomo==1) /* przypisywanie wlasciciela */
        { proprietor1=new person; }
        else
        { proprietor2=new company; }

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

    };

    ~vehicle() /* destruktor */
    {
        if(pomo==1)
        { delete proprietor1; }
        else
        { delete proprietor2; }
    };

    void change_reg() /* metoda odpowiadajaca za zmiane numeru rejestracyjnego */
    {
        cout<<"Podaj nowy numer rejestracyjny"<<endl;
        cin>>reg_number;
    };

    void add_OC() /* metoda odpowiadajaca za dodanie OC */
    {
        cout<<"Podaj 12 znakowy numer polisy OC"<<endl;
        cin>>OC_number;
    };

    void change_owner() /* metoda odpowiadajaca za zmiane wlasciciela */
    {
        if(pomo==1) /* usuwanie poprzedniego wlasciciela */
        { delete proprietor1; }
        else
        { delete proprietor2; }

        pomo=0; /* zerowanie zmiennej */

        cout<<"WPROWADZANIE DANYCH NOWEGO WLASCICIELA:"<<endl<<endl;

        cout<<"Wybierz 1-jesli wlascicielem jest osoba prywatna lub 2-jesli firma"<<endl;
        while(!(cin>>pomo)) /* wczytywanie zmiennej, wykrywanie bledu */
        {
            cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
            cin.clear();
            cin.ignore(9999, '\n' );
            cout<<endl;
        }

        if(pomo==1) /* przypisywanie wlasciciela */
        { proprietor1=new person; }
        else
        { proprietor2=new company; }
    };

    void add_type(int t) /* metoda odpowiadajaca za przypisanie typu pojazdu */
    {
        switch(t)
        {
            case 1: { type="samochod";              break; }
            case 2: { type="samochod elektryczny";  break; }
            case 3: { type="motocykl";              break; }
            case 4: { type="tramwaj";               break; }
            case 5: { type="ciezarowka";            break; }
            case 6: { type="autobus";               break; }
            case 7: { type="motorowka";             break; }
            case 8: { type="skuter wodny";          break; }
            case 9: { type="okret";                 break; }
            case 10: { type="kontenerowiec";        break; }
        }
    };

    void virtual show()const /* metoda odpowiadajaca za wyswietlenie informacji o pojezdzie */
    {
        cout<<"WLASCICIEL:"<<endl;
        if(pomo==1)
        { proprietor1->show(); }
        else
        { proprietor2->show(); }

        cout<<endl<<endl<<"NUMER REJESTRACYJNY:"<<endl;
        cout<<reg_number;

        cout<<endl<<"NUMER POLISY OC:"<<endl;
        cout<<OC_number;

        cout<<endl<<"NUMER VIN:"<<endl;
        cout<<VIN;

        cout<<endl<<"TYP:"<<endl;
        cout<<type;

        cout<<endl<<"MARKA:"<<endl;
        cout<<mark;

        cout<<endl<<"PALIWO:"<<endl;
        cout<<petrol;

    };

    void list()const /* metoda odpowiadajaca za wypisnie pojazdu w formacie listy */
    {
        cout<<setw(20)<<left<<reg_number<<setw(20)<<left<<OC_number<<setw(20)<<left<<VIN<<setw(25)<<left<<type<<setw(20)<<left<<mark<<endl;
    };

};

class car: public vehicle /* klasa reprezentujaca samochody */
{
    protected:
    string colour; /* kolor */
    int power; /* moc silnika */
    int nperson; /* ilosc miejsc */

    public:

    car():vehicle() /* konstruktor */
    {
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
    };



    void show()const /* metoda odpowiadajaca za wyswietlenie informacji o pojezdzie */
    {
        vehicle::show();

        cout<<endl<<"KOLOR:"<<endl;
        cout<<colour;

        cout<<endl<<"MOC:"<<endl;
        cout<<power<<" KM";

        cout<<endl<<"ILOSC OSOB:"<<endl;
        cout<<nperson;

    };

};

class electric_car: public car /* klasa reprezentujaca samochody elektryczne */
{
    protected:
    double battery; /* pojemnosc baterii */
    double range; /* zasieg (maksymalna ilosc kilometrow przejechana na jednym ladowaniu) */

    public:
    electric_car():car()  /* konstruktor */
    {
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

    };

    void show()const /* metoda odpowiadajaca za wyswietlenie informacji o pojezdzie */
    {
        car::show();

        cout<<endl<<"POJEMNOSC AKUMULATORA:"<<endl;
        cout<<battery<<" mAh";

        cout<<endl<<"ZASIEG:"<<endl;
        cout<<range<<" km";

        cout<<endl;
    };
};

class normal_car: public car /* klasa reprezentujaca samochody bedaca uzupelnieniem klasy car */
{
    protected:
    double tank;  /* pojemnosc baku */
    double speed;  /* maksymalna predkosc */

    public:
    normal_car():car() /* konstruktor */
    {
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

    };

    void show()const /* metoda odpowiadajaca za wyswietlenie informacji o pojezdzie */
    {
        car::show();

        cout<<endl<<"POJEMNOSC BAKU:"<<endl;
        cout<<tank<<" l";

        cout<<endl<<"MAKSYMALNA PREDKOSC:"<<endl;
        cout<<speed<<" km/h";

        cout<<endl;
    };
};

class motorcycle: public vehicle /* klasa reprezentujaca motocykle */
{
    protected:
    string model;  /* model */
    double speed;  /* maksymalna predkosc */
    double accelerate;  /* przyspieszenie */


    public:

    motorcycle():vehicle()  /* konstruktor */
    {
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

    };



    void show()const /* metoda odpowiadajaca za wyswietlenie informacji o pojezdzie */
    {
        vehicle::show();

        cout<<endl<<"MODEL:"<<endl;
        cout<<model;

        cout<<endl<<"MAKSYMALNA PREDKOSC:"<<endl;
        cout<<speed<<" km";

        cout<<endl<<"PRZYSPIESZENIE:"<<endl;
        cout<<accelerate<<" m/s^2";
    };
};

class big_vehicle: public vehicle /* klasa reprezentujaca duze pojazdy */
{
    protected:
    string colour; /* kolor */
    double weight; /* waga */

    public:

    big_vehicle():vehicle()  /* konstruktor */
    {
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

    };



    void show()const /* metoda odpowiadajaca za wyswietlenie informacji o pojezdzie */
    {
        vehicle::show();

        cout<<endl<<"KOLOR:"<<endl;
        cout<<colour;

        cout<<endl<<"MASA:"<<endl;
        cout<<weight<<" t";

    };

};

class tram: public big_vehicle /* klasa reprezentujaca tramwaje */
{
    protected:
    string model; /* model */
    double age;  /* wiek */


    public:

    tram():big_vehicle()  /* konstruktor */
    {
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

    };



    void show()const /* metoda odpowiadajaca za wyswietlenie informacji o pojezdzie */
    {
        big_vehicle::show();

        cout<<endl<<"MODEL:"<<endl;
        cout<<model;

        cout<<endl<<"WIEK:"<<endl;
        cout<<age<<" lat";
    };
};

class truck: public big_vehicle /* klasa reprezentujaca ciezarowki */
{
    protected:
    double lenght; /* dlugosc */
    string product; /* rodzaj produktow */
    double load; /* ladownosc */

    public:

    truck():big_vehicle() /* konstruktor */
    {
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
    };



    void show()const /* metoda odpowiadajaca za wyswietlenie informacji o pojezdzie */
    {
        big_vehicle::show();

        cout<<endl<<"DLUGOSC:"<<endl;
        cout<<lenght<<" m";

        cout<<endl<<"RODZAJ PRZEWOZONYCH TOWAROW:"<<endl;
        cout<<product;

        cout<<endl<<"LADOWNOSC:"<<endl;
        cout<<load<<" t";
    };
};

class bus: public big_vehicle /* klasa reprezentujaca autobusy */
{
    protected:
    double lenght; /* dlugosc */
    int passenger; /* maksymalna ilosc pasazerow */

    public:

    bus():big_vehicle() /* konstruktor */
    {
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
    };



    void show()const /* metoda odpowiadajaca za wyswietlenie informacji o pojezdzie */
    {
        big_vehicle::show();

        cout<<endl<<"DLUGOSC:"<<endl;
        cout<<lenght<<" m";

        cout<<endl<<"ILOSC PASAZEROW:"<<endl;
        cout<<passenger;

    };
};

class boat: public vehicle /* klasa reprezentujaca lodzie */
{
    protected:
    string colour; /* kolor */
    double displacement; /* wyporosc */
    int nperson; /* maksymalna ilosc osob na pokladzie */

    public:

    boat():vehicle() /* konstruktor */
    {
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
    };



    void show()const /* metoda odpowiadajaca za wyswietlenie informacji o pojezdzie */
    {
        vehicle::show();

        cout<<endl<<"KOLOR:"<<endl;
        cout<<colour;

        cout<<endl<<"WYPORNOSC:"<<endl;
        cout<<displacement<<" t";

        cout<<endl<<"ILOSC OSOB:"<<endl;
        cout<<nperson;

    };

};

class motorboat: public boat /* klasa reprezentujaca motorowki */
{
    protected:
    double tank; /* pojemnosc baku */
    double speed; /* maksymalna predkosc */

    public:
    motorboat():boat() /* konstruktor */
    {
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

    };

    void show()const /* metoda odpowiadajaca za wyswietlenie informacji o pojezdzie */
    {
        boat::show();

        cout<<endl<<"POJEMNOSC BAKU:"<<endl;
        cout<<tank<<" l";

        cout<<endl<<"MAKSYMALNA PREDKOSC:"<<endl;
        cout<<speed<<" km/h";

        cout<<endl;
    };
};

class jet_ski: public boat /* klasa reprezentujaca skutery wodne */
{
    protected:
    double tank; /* pojemnosc baku */
    double speed; /* maksymalna predkosc */
    double weight; /* waga */

    public:
    jet_ski():boat() /* konstruktor */
    {
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

    };

    void show()const /* metoda odpowiadajaca za wyswietlenie informacji o pojezdzie */
    {
        boat::show();

        cout<<endl<<"POJEMNOSC BAKU:"<<endl;
        cout<<tank<<" l";

        cout<<endl<<"MAKSYMALNA PREDKOSC:"<<endl;
        cout<<speed<<" km/h";

        cout<<endl<<"WAGA:"<<endl;
        cout<<weight<<" kg";

        cout<<endl;
    };
};

class ship: public boat /* klasa reprezentujaca okrety */
{
    protected:
    string exploitation; /* przeznaczenie (do jakich celow wykozystywany jest okret) */

    public:
    ship():boat() /* konstruktor */
    {
        cout<<"Podaj do jakich celow wykorzystywany jest okret"<<endl;
        cin>>exploitation;

    };

    void show()const /* metoda odpowiadajaca za wyswietlenie informacji o pojezdzie */
    {
        boat::show();

        cout<<endl<<"WYKORZYSTANIE:"<<endl;
        cout<<exploitation;

        cout<<endl;
    };
};

class freegan: public boat /* klasa reprezentujaca kontenerowce */
{
    protected:
    double load; /* ladownosc */
    double incineration; /* spalanie */

    public:
    freegan():boat() /* konstruktor */
    {
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
    };

    void show()const /* metoda odpowiadajaca za wyswietlenie informacji o pojezdzie */
    {
        boat::show();

        cout<<endl<<"LADOWNOSC:"<<endl;
        cout<<load<<" t";

        cout<<endl<<"SPALANIE:"<<endl;
        cout<<incineration<<" l/h";

        cout<<endl;
    };
};

#endif
