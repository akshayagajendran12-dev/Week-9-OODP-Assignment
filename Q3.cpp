#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    double tuition;

public:
    Student(string n, double t) : name(n), tuition(t) {}

    virtual double calculateFee() = 0;

    virtual ~Student() {}
};

class DayScholar : public Student {
public:
    DayScholar(string n) : Student(n, 40000.0) {}

    double calculateFee() override {
        return tuition + 12000.0;
    }
};

class Hosteller : public Student {
public:
    Hosteller(string n) : Student(n, 40000.0) {}

    double calculateFee() override {
        return tuition + 60000.0;
    }
};

class Scholar : public Student {
public:
    Scholar(string n) : Student(n, 20000.0) {}

    double calculateFee() override {
        return tuition;
    }
};

int main() {
    int n;
    cin >> n;

    double totalCollected = 0.0;

    for (int i = 0; i < n; i++) {
        string type, name;
        cin >> type >> name;

        Student* student = nullptr;

        if (type == "DAY_SCHOLAR")
            student = new DayScholar(name);
        else if (type == "HOSTELLER")
            student = new Hosteller(name);
        else if (type == "SCHOLAR")
            student = new Scholar(name);
        else {
            cout << "Invalid student type" << endl;
            continue;
        }

        double fee = student->calculateFee();

        cout << fixed << setprecision(2);
        cout << name << ": " << fee << endl;

        totalCollected += fee;
        delete student;
    }

    cout << fixed << setprecision(2);
    cout << "Total Collected: " << totalCollected << endl;

    return 0;
}
```
