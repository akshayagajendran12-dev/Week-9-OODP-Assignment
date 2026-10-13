#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Cab {
protected:
    double distance;

public:
    Cab(double d) : distance(d) {}

    virtual double calculateFare(bool night) = 0;

    virtual ~Cab() {}
};

class Mini : public Cab {
public:
    Mini(double d) : Cab(d) {}

    double calculateFare(bool night) override {
        double fare = 50.0 + distance * 12.0;

        if (night)
            fare += 30.0;

        return fare;
    }
};

class Sedan : public Cab {
public:
    Sedan(double d) : Cab(d) {}

    double calculateFare(bool night) override {
        double fare = 80.0 + distance * 18.0;

        if (night)
            fare += 50.0;

        return fare;
    }
};

class SUV : public Cab {
public:
    SUV(double d) : Cab(d) {}

    double calculateFare(bool night) override {
        double fare = 100.0 + distance * 22.0;

        if (night)
            fare += 70.0;

        return fare;
    }
};

int main() {
    int n;
    cin >> n;

    double totalFare = 0.0;

    for (int i = 0; i < n; i++) {
        string type, time;
        double distance;

        cin >> type >> distance >> time;

        bool night = (time == "NIGHT");
        Cab* cab = nullptr;

        if (type == "MINI")
            cab = new Mini(distance);
        else if (type == "SEDAN")
            cab = new Sedan(distance);
        else if (type == "SUV")
            cab = new SUV(distance);
        else {
            cout << "Invalid cab type" << endl;
            continue;
        }

        double fare = cab->calculateFare(night);

        cout << fixed << setprecision(2);
        cout << type << ": " << fare << endl;

        totalFare += fare;
        delete cab;
    }

    cout << fixed << setprecision(2);
    cout << "Total Fare: " << totalFare << endl;

    return 0;
}
