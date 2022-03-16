#include <iostream>
using namespace std;


class Actor {
public:
    Actor(string nume_actor, int varsta);
    Actor(const Actor& a);
    ~Actor();
    Actor();
    Actor& operator=(const Actor& a);
    friend istream& operator >> (istream& stream, Actor& actor);
    friend ostream& operator << (ostream& stream, Actor& actor);
    string get_nume();
    int get_varsta();
    void set_nume(string nume_actor);
    void set_varsta(int varsta);
    int operator+(Actor& actor);
    Actor operator-(int ani);
private:
    string nume_actor;
    int varsta;

};
Actor Actor::operator-(int ani) {
    Actor aux(*this);
    aux.varsta = aux.varsta - ani;
    return aux;
}
int Actor::operator+(Actor& actor) {
    float suma = 0;
    suma = this->varsta + actor.get_varsta();
    suma = suma / 2.0;
    return suma;
}

Actor::~Actor() {
}

Actor& Actor::operator=(const Actor& actor) {
    if (this != &actor)
    {
        nume_actor = actor.nume_actor;
        varsta = actor.varsta;
    }
    return *this;
}

Actor::Actor(string nume_actor, int varsta) {
    this->nume_actor = nume_actor;
    this->varsta = varsta;
}

Actor::Actor() {
}

Actor::Actor(const Actor& actor) {
    nume_actor = actor.nume_actor;
    varsta = actor.varsta;
}

string Actor::get_nume() {
    return this->nume_actor;
}

int Actor::get_varsta() {
    return this->varsta;
}

void Actor::set_nume(string nume_actor) {
    this->nume_actor = nume_actor;
}

void Actor::set_varsta(int varsta) {
    this->varsta = varsta;
}

istream& operator >> (istream& stream, Actor& actor) {
    string nume, prenume;
    cout << "Introduceti prenumele actorului: ";
    stream >> prenume;
    cout << "Introduceti numele actorului: ";
    stream >> nume;
    actor.nume_actor = prenume + " " + nume;
    cout << "Introduceti varsta actorului: ";
    stream >> actor.varsta;
    return stream;
}

ostream& operator << (ostream& stream, Actor& actor) {
    stream << "Actorul " << actor.nume_actor;
    stream << ' ' << "cu varsta de " << actor.varsta << '\n';
    return stream;
}


class Teatru {
public:
    Teatru(string denumire_piesa, int numar_actori, Actor* actori, float rating);
    Teatru(const Teatru&);
    Teatru();
    ~Teatru();
    Teatru& operator= (const Teatru& teatru);
    string get_dp();
    int get_na();
    Actor* get_a();
    float get_r();
    void set_dp(string denumire_piesa);
    void set_na(int numar_actori);
    void set_a(int numar_actori, Actor* actori);
    void set_r(float rating);
    friend istream& operator >> (istream& stream, Teatru& teatru);
    friend ostream& operator << (ostream& stream, Teatru& teatru);
    Teatru& operator +=(Teatru&);
    Teatru& operator -=(int);
    friend bool operator !=(Teatru&, Teatru&);
    friend bool operator ==(Teatru&, Teatru&);
private:
    string denumire_piesa;
    int numar_actori;
    Actor* actori;
    float rating;
};

Teatru& Teatru::operator+=(Teatru& teatru) {
    int nr_aux = this->numar_actori;
    Actor* aux = new Actor[this->numar_actori];
    for (int i = 0; i < this->numar_actori; ++i)
        aux[i] = this->actori[i];
    if (this->actori != NULL)
        delete[] this->actori;
    this->actori = new Actor[nr_aux + teatru.numar_actori];
    for (int i = 0; i < nr_aux; ++i)
        this->actori[i] = aux[i];
    for (int i = 0; i < teatru.numar_actori; ++i)
        this->actori[i + nr_aux] = teatru.actori[i];
    return *this;
}

Teatru& Teatru::operator-=(int r) {
    if (this->rating - r >= 0)
        this->rating = this->rating - r;
    else
        this->rating = 0;
    return *this;
}

Teatru::Teatru(string denumire_piesa, int numar_actori, Actor* actori, float rating) {
    this->denumire_piesa = denumire_piesa;
    this->numar_actori = numar_actori;
    this->actori = new Actor[numar_actori];
    for (int i = 0; i < numar_actori; ++i)
        this->actori[i] = actori[i];
    this->rating = rating;
}

Teatru::~Teatru() {
    if (this->actori != NULL)
        delete[] this->actori;
}

Teatru::Teatru(const Teatru& teatru) {
    denumire_piesa = teatru.denumire_piesa;
    numar_actori = teatru.numar_actori;
    actori = new Actor[teatru.numar_actori];
    for (int i = 0; i < teatru.numar_actori; ++i)
        actori[i] = teatru.actori[i];
    rating = teatru.rating;
}

Teatru& Teatru::operator=(const Teatru& teatru) {
    if (this != &teatru) {
        if (this->actori != NULL)
            delete[] this->actori;
        denumire_piesa = teatru.denumire_piesa;
        numar_actori = teatru.numar_actori;
        actori = new Actor[teatru.numar_actori];
        for (int i = 0; i < teatru.numar_actori; ++i)
            actori[i] = teatru.actori[i];
        rating = teatru.rating;
    }
    return *this;
}

Teatru::Teatru() {
    this->actori = NULL;
}

string Teatru::get_dp() {
    return this->denumire_piesa;
}

int Teatru::get_na() {
    return this->numar_actori;
}

Actor* Teatru::get_a() {
    return this->actori;
}

float Teatru::get_r() {
    return this->rating;
}

void Teatru::set_dp(string denumire_piesa) {
    this->denumire_piesa = denumire_piesa;
}

void Teatru::set_na(int numar_actori) {
    this->numar_actori = numar_actori;
}

void Teatru::set_a(int numar_actori, Actor* actori) {
    if (this->actori != NULL)
        delete[] this->actori;
    this->actori = new Actor[numar_actori];
    this->numar_actori = numar_actori;
    for (int i = 0; i < numar_actori; ++i)
        this->actori[i] = actori[i];
}

void Teatru::set_r(float rating) {
    this->rating = rating;
}

istream& operator >> (istream& stream, Teatru& teatru) {
    cout << "Introduceti denumirea piesei (un singur cuvant): ";
    stream >> teatru.denumire_piesa;
    cout << "Introduceti numarul de actori: ";
    stream >> teatru.numar_actori;
    cout << "Introduceti actorii:\n";
    if (teatru.actori != NULL)
        delete[] teatru.actori;
    teatru.actori = new Actor[teatru.numar_actori];
    for (int i = 0; i < teatru.numar_actori; ++i)
        stream >> teatru.actori[i];
    cout << "Introduceti rating-ul: ";
    stream >> teatru.rating;
    return stream;
}

ostream& operator << (ostream& stream, Teatru& teatru) {
    stream << "Piesa " << teatru.denumire_piesa << " cu rating-ul " << teatru.rating << " are " << teatru.numar_actori << " actori:\n";
    for (int i = 0; i < teatru.numar_actori; ++i)
        stream << teatru.actori[i];
    return stream;
}

bool operator != (Teatru& teatru1, Teatru& teatru2) {
    return teatru1.get_na() == teatru2.get_na();
}

bool operator == (Teatru& teatru1, Teatru& teatru2) {
    return teatru1.get_dp().compare(teatru2.get_dp());
}


int main(int argc, const char* argv[]) {
    int optiune;
    Teatru* teatre = NULL;
    int numar_teatre;
    cout << "La prima rulare a meniului se recomanda citirea datelor!\n\n";
    while (true) {
        cout << "1. Citirea pieselor\n";
        cout << "2. Afisarea pieselor\n";
        cout << "3. Compararea a doua piese\n";
        cout << "4. Modificarea datelor unui piese\n";
        cout << "5. Iesire\n";
        cout << "Optiunea aleasa este: ";
        cin >> optiune;
        if (optiune == 5)
            break;
        else if (optiune == 1) {
            cout << "Introduceti numarul de piese: ";
            cin >> numar_teatre;
            teatre = new Teatru[numar_teatre];
            for (int i = 0; i < numar_teatre; ++i) {
                cin >> teatre[i];
                cout << "\n---------------------------\n";
            }
        }
        else if (optiune == 2 && teatre != NULL) {
            for (int i = 0; i < numar_teatre; ++i) {
                cout << teatre[i];
                cout << "\n---------------------------\n";
            }
        }
        else if (optiune == 3 && teatre != NULL) {
            int i, j;
            cout << "Introduceti indicii celor doua piese pe care doriti sa le comparati: ";
            cin >> i >> j;
            i--;
            j--;
            if (teatre[i] == teatre[j])
                cout << "Cele doua piese sunt egale!";
            else
                cout << "Cele doua piese sunt diferite!";
            cout << "\n---------------------------\n";
        }
        else if (optiune == 4 && teatre != NULL) {
            int i;
            cout << "Introduceti indicele piesei pe care doriti sa o modificati :";
            cin >> i;
            i--;
            cout << "Ce doriti sa modificati?\n";
            cout << "1. Denumirea\n";
            cout << "2. Actorii\n";
            cout << "3. Ratingul\n";
            cout << "Optiunea aleasa este: ";
            int op;
            cin >> op;
            if (op == 1) {
                cout << "Introduceti noua denumire (un singur cuvant): ";
                string denumire;
                cin >> denumire;
                teatre[i].set_dp(denumire);
            }
            else if (op == 2) {
                cout << "Introduceti noul numar de actori: ";
                int nr;
                cin >> nr;
                Actor* actori_noi = new Actor[nr];
                cout << "Introduceti noii actori:\n";
                for (int i = 0; i < nr; ++i)
                    cin >> actori_noi[i];
                teatre[i].set_a(nr, actori_noi);
            }
            else if (op == 3) {
                cout << "Introduceti noul rating: ";
                float r;
                cin >> r;
                teatre[i].set_r(r);
            }
            cout << "Piesa modificata este:\n" << teatre[i];
            cout << "\n---------------------------\n";
        }
    }
    delete[] teatre;
    return 0;
}
