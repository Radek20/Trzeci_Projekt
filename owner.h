#ifndef owner_h
#define owner_h

class owner /* klasa bazowa reprezentujaca wlascicieli */
{
    protected:
    int number; /* numer wlasciciela */

    public:
    owner() /* konstruktor */
    {
        cout<<endl<<"WPROWADZ DANE WLASCICIELA:"<<endl<<endl;

        cout<<"Podaj numer wlasciciela"<<endl;

        while(!(cin>>number)) /* wczytywanie numeru, wykrywanie bledu */
        {
            cout<<"Blad! To nie jest liczba, podaj jeszcze raz: ";
            cin.clear();
            cin.ignore(9999, '\n' );
            cout<<endl;
        }

    };

    void virtual show()const /* metoda odpowiedzialna za wyswietlenie informacji o wlascicielu */
    {
        cout<<"NUMER WLASCICIELA:"<<endl;
        cout<<number;

    };
};

class person: public owner /* klasa reprezentujaca wlasciciela - osoba prywatna */
{
    protected:
    string name; /* imie */
    string surname; /* nazwisko */
    int pom; /* zmienna pomocnicza przechowyjaca informacje czy jest wspolwlasciciel */
    owner* co_owner; /* wskaznik na wspolwlasciciela */

    public:
    person():owner() /* konstruktor */
    {
        cout<<"Podaj imie"<<endl;
        cin>>name;

        cout<<"Podaj nazwisko"<<endl;
        cin>>surname;

        cout<<"Czy chcesz dodac wspolwlasciciela? Wprowadz 1 jesli tak lub 0 jesli nie"<<endl;
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
            co_owner=new person;
        }

    };

    ~person() /* destruktor */
    {
        if(pom!=0)
        { delete co_owner; }
    }

    void show()const /* metoda odpowiedzialna za wyswietlenie informacji o wlascicielu */
    {
        cout<<endl<<"IMIE:"<<endl;
        cout<<name;

        cout<<endl<<"NAZWISKO:"<<endl;
        cout<<surname;

        if(pom!=0)
        {
            cout<<endl<<"WSPOLWLASCICIEL:";
            co_owner->show();
        }

    };

};

class company: public owner /* klasa reprezentujaca wlasciciela - firma */
{
    protected:
    string name; /* nazwa firmy */

    public:
    company():owner() /* konstruktor */
    {
        cout<<"Podaj nazwe firmy"<<endl;
        cin.clear();
        cin.ignore(9999, '\n' );
        getline(cin, name);

    };

    void show()const /* metoda odpowiedzialna za wyswietlenie informacji o wlascicielu */
    {
        cout<<endl<<"NAZWA FIRMY:"<<endl;
        cout<<name;
    };
};

#endif
