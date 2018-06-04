#ifndef owner_h
#define owner_h

class owner /* klasa bazowa reprezentujaca wlascicieli */
{
    protected:
    int number; /* numer wlasciciela */

    public:
    owner(int num) /* konstruktor */
    {
        number=num;
    };

    void virtual show()const /* metoda odpowiedzialna za wyswietlenie informacji o wlascicielu */
    {
        cout<<"NUMER WLASCICIELA:";
        cout<<number;

    };

    string virtual preview_name()const {}; /* podglad danych */
    string virtual preview_surname()const {}; /* podglad danych */

};

class person: public owner /* klasa reprezentujaca wlasciciela - osoba prywatna */
{
    protected:
    string name; /* imie */
    string surname; /* nazwisko */
    int pom; /* zmienna pomocnicza przechowyjaca informacje czy jest wspolwlasciciel */
    owner* co_owner; /* wskaznik na wspolwlasciciela */

    public:
    person(int num, string nam, string sur, int po, owner* co):owner(num) /* konstruktor */
    {
        name=nam;
        surname=sur;
        pom=po;
        co_owner=co;
    };

    person(int num, string nam, string sur, int po):owner(num) /* konstruktor */
    {
        name=nam;
        surname=sur;
        pom=po;
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
            cout<<endl<<endl<<"WSPOLWLASCICIEL:";
            co_owner->show();
        }

    };

    string preview_name() const /* podglad danych */
    { return name; };

    string preview_surname() const /* podglad danych */
    { return surname; };
};

class company: public owner /* klasa reprezentujaca wlasciciela - firma */
{
    protected:
    string name; /* nazwa firmy */

    public:
    company(int num, string nam):owner(num) /* konstruktor */
    {
        name=nam;
    };

    void show()const /* metoda odpowiedzialna za wyswietlenie informacji o wlascicielu */
    {
        cout<<endl<<"NAZWA FIRMY:"<<endl;
        cout<<name;
    };

    string preview_name() const /* podglad danych */
    { return name; };
};

#endif
