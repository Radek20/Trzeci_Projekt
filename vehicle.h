#ifndef vehicle_h
#define vehicle_h


owner* OWNER(int);
owner* OWNER2(int,int,string,string);

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
    owner* proprietor; /* wskaznik na wlasciciela */

    public:
    vehicle(string nreg, string noc, string vin, string mar, string pet, owner* own) /* konstruktor */
    {
        reg_number=nreg;
        OC_number=noc;
        VIN=vin;
        mark=mar;
        petrol=pet;
        proprietor=own;

    };

    vehicle(){};

    ~vehicle() /* destruktor */
    {
        delete proprietor;
    };

    void change_reg(string nreg) /* metoda odpowiadajaca za zmiane numeru rejestracyjnego */
    { reg_number=nreg; };

    void add_OC(string noc) /* metoda odpowiadajaca za dodanie OC */
    { OC_number=noc; };

    void change_owner(int test_mode=0, int co=0, int num=0, string nam="", string sur="") /* metoda odpowiadajaca za zmiane wlasciciela */
    {
        delete proprietor;

        pomo=0; /* zerowanie zmiennej */
        if(test_mode==0)
        {
            cout<<"WPROWADZANIE DANYCH NOWEGO WLASCICIELA:"<<endl<<endl;
            proprietor=OWNER(0);
        }
        else
        { proprietor=OWNER2(co,num,nam,sur); }
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
        proprietor->show();

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

    string preview_reg() const /* metoda zwracajaca aktualny numer rejestracyjny */
    { return reg_number; };

    string preview_oc() const /* metoda zwracajaca aktualny numer polisy OC */
    { return OC_number; };

    owner* preview_owner() const /* metoda zwracajaca wskaznik na wlasciciela */
    { return proprietor; };
};

class car: public vehicle /* klasa reprezentujaca samochody */
{
    protected:
    string colour; /* kolor */
    int power; /* moc silnika */
    int nperson; /* ilosc miejsc */

    public:

    car(string nreg, string noc, string vin, string mar, string pet, owner* own, string col, int pow, int npe):vehicle(nreg, noc, vin, mar, pet, own) /* konstruktor */
    {
        colour=col;
        power=pow;
        nperson=npe;
    };

    car(){};

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
    electric_car(string nreg, string noc, string vin, string mar, string pet, owner* own, string col, int pow, int npe, double bat, double ran):car(nreg, noc, vin, mar, pet, own, col, pow, npe)
    {
        battery=bat;
        range=ran;
    };

    electric_car(){};

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
    normal_car(string nreg, string noc, string vin, string mar, string pet, owner* own, string col, int pow, int npe, double tan, double spe):car(nreg, noc, vin, mar, pet, own, col, pow, npe) /* konstruktor */
    {
        tank=tan;
        speed=spe;
    };

    normal_car(){};

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

    motorcycle(string nreg, string noc, string vin, string mar, string pet, owner* own, string mod, int spe, int acc):vehicle(nreg, noc, vin, mar, pet, own)  /* konstruktor */
    {
        model=mod;
        speed=spe;
        accelerate=acc;
    };

    motorcycle(){};

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

    big_vehicle(string nreg, string noc, string vin, string mar, string pet, owner* own, string col, double wei):vehicle(nreg, noc, vin, mar, pet, own)  /* konstruktor */
    {
        colour=col;
        weight=wei;
    };

    big_vehicle(){};

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

    tram(string nreg, string noc, string vin, string mar, string pet, owner* own, string col, double wei, string mod, double ag):big_vehicle(nreg, noc, vin, mar, pet, own, col, wei)  /* konstruktor */
    {
        model=mod;
        age=ag;
    };

    tram(){};

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

    truck(string nreg, string noc, string vin, string mar, string pet, owner* own, string col, double wei, double len, string pro, double loa):big_vehicle(nreg, noc, vin, mar, pet, own, col, wei) /* konstruktor */
    {
        lenght=len;
        product=pro;
        load=loa;
    };

    truck(){};

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

    bus(string nreg, string noc, string vin, string mar, string pet, owner* own, string col, double wei, double len, int pas):big_vehicle(nreg, noc, vin, mar, pet, own, col, wei) /* konstruktor */
    {
        lenght=len;
        passenger=pas;
    };

    bus(){};

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

    boat(string nreg, string noc, string vin, string mar, string pet, owner* own, string col, double dis, int npe):vehicle(nreg, noc, vin, mar, pet, own) /* konstruktor */
    {
        colour=col;
        displacement=dis;
        nperson=npe;
    };

    boat(){};

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
    motorboat(string nreg, string noc, string vin, string mar, string pet, owner* own, string col, double dis, int npe, double tan, double spe):boat(nreg, noc, vin, mar, pet, own, col, dis, npe) /* konstruktor */
    {
        tank=tan;
        speed=spe;
    };

    motorboat(){};

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
    jet_ski(string nreg, string noc, string vin, string mar, string pet, owner* own, string col, double dis, int npe, double tan, double spe, double wei):boat(nreg, noc, vin, mar, pet, own, col, dis, npe) /* konstruktor */
    {
        tank=tan;
        speed=spe;
        weight=wei;
    };

    jet_ski(){};

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
    ship(string nreg, string noc, string vin, string mar, string pet, owner* own, string col, double dis, int npe, string exp):boat(nreg, noc, vin, mar, pet, own, col, dis, npe) /* konstruktor */
    {
        exploitation=exp;
    };

    ship(){};

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
    freegan(string nreg, string noc, string vin, string mar, string pet, owner* own, string col, double dis, int npe,double loa, double inc):boat(nreg, noc, vin, mar, pet, own, col, dis, npe) /* konstruktor */
    {
        load=loa;
        incineration=inc;
    };

    freegan(){};

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
