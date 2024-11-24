#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char* fullName;  

public:
    Person() : fullName(nullptr) {}

    Person(const char* name) {
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
    }

    Person(const Person& other) {
        fullName = new char[strlen(other.fullName) + 1];
        strcpy(fullName, other.fullName);
    }

    ~Person() {
        delete[] fullName;
    }

    void display() const {
        cout << "ПІБ: " << fullName << endl;
    }
};

class Apartment {
private:
    Person* people;  
    int capacity;    

public:
    Apartment() : people(nullptr), capacity(0) {}

    Apartment(int numPeople) : capacity(numPeople) {
        people = new Person[capacity];
    }

    Apartment(const Apartment& other) : capacity(other.capacity) {
        people = new Person[capacity];
        for (int i = 0; i < capacity; ++i) {
            people[i] = other.people[i];
        }
    }

    ~Apartment() {
        delete[] people;
    }

    void addPerson(int index, const char* name) {
        if (index >= 0 && index < capacity) {
            people[index] = Person(name);
        }
    }

    void display() const {
        cout << "Квартира з " << capacity << " мешканцями:" << endl;
        for (int i = 0; i < capacity; ++i) {
            people[i].display();
        }
    }
};

class Building {
private:
    Apartment* apartments;  
    int numApartments;      

public:
    Building() : apartments(nullptr), numApartments(0) {}

    Building(int numApts) : numApartments(numApts) {
        apartments = new Apartment[numApartments];
    }

    Building(const Building& other) : numApartments(other.numApartments) {
        apartments = new Apartment[numApartments];
        for (int i = 0; i < numApartments; ++i) {
            apartments[i] = other.apartments[i];
        }
    }

    ~Building() {
        delete[] apartments;
    }

    void addApartment(int index, int numPeople) {
        if (index >= 0 && index < numApartments) {
            apartments[index] = Apartment(numPeople);
        }
    }

    void addPersonToApartment(int aptIndex, int personIndex, const char* name) {
        if (aptIndex >= 0 && aptIndex < numApartments) {
            apartments[aptIndex].addPerson(personIndex, name);
        }
    }

    void display() const {
        cout << "Будинок з " << numApartments << " квартирами:" << endl;
        for (int i = 0; i < numApartments; ++i) {
            cout << "Квартира " << i + 1 << ":" << endl;
            apartments[i].display();
        }
    }
};

int main() {
    Building building(2); 

    building.addApartment(0, 2);
    building.addPersonToApartment(0, 0, "Іван Іванов");
    building.addPersonToApartment(0, 1, "Максімка Максімкович");

    building.addApartment(1, 1);
    building.addPersonToApartment(1, 0, "Новік Мар'ян");

    building.display();

    return 0;
}
