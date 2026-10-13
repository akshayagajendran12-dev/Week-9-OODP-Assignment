#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Parcel {
protected:
    double weight;
    double declaredValue;

public:
    Parcel(double w, double v) : weight(w), declaredValue(v) {}

    virtual double calculateCharge() = 0;

    virtual double calculateInsurance() {
        return 0.0;
    }

    double getTotal() {
        return calculateCharge() + calculateInsurance();
    }

    virtual ~Parcel() {}
};

class Standard : public Parcel {
public:
    Standard(double w, double v) : Parcel(w, v) {}

    double calculateCharge() override {
        return 40.0 + 10.0 * weight;
    }
};

class Express : public Parcel {
public:
    Express(double w, double v) : Parcel(w, v) {}

    double calculateCharge() override {
        return 80.0 + 15.0 * weight;
    }

    double calculateInsurance() override {
        return declaredValue * 0.02;
    }
};

class Fragile : public Parcel {
public:
    Fragile(double w, double v) : Parcel(w, v) {}

    double calculateCharge() override {
        return 40.0 + 10.0 * weight + 50.0;
    }

    double calculateInsurance() override {
        return declaredValue * 0.03;
    }
};

int main() {
    int n;
    cin >> n;

    double grandTotal = 0.0;

    for (int i = 0; i < n; i++) {
        string type;
        double weight, declaredValue;

        cin >> type >> weight >> declaredValue;

        Parcel* parcel = nullptr;

        if (type == "STANDARD")
            parcel = new Standard(weight, declaredValue);
        else if (type == "EXPRESS")
            parcel = new Express(weight, declaredValue);
        else if (type == "FRAGILE")
            parcel = new Fragile(weight, declaredValue);
        else {
            cout << "Invalid parcel type" << endl;
            continue;
        }

        double charge = parcel->calculateCharge();
        double insurance = parcel->calculateInsurance();
        double total = charge + insurance;

        cout << fixed << setprecision(2);
        cout << type << ": Charge=" << charge
             << " Insurance=" << insurance
             << " Total=" << total << endl;

        grandTotal += total;
        delete parcel;
    }

    cout << fixed << setprecision(2);
    cout << "Grand Total: " << grandTotal << endl;

    return 0;
}
```
