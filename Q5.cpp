#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Appliance {
protected:
    double power;
    double hours;

public:
    Appliance(double p, double h) : power(p), hours(h) {}

    virtual double calculateUnits(bool saver) = 0;
    virtual bool supportsSaverMode() = 0;
    virtual string getName() = 0;

    virtual ~Appliance() {}
};

class Fridge : public Appliance {
public:
    Fridge(double h) : Appliance(150, h) {}

    double calculateUnits(bool saver) override {
        return power * hours / 1000.0;
    }

    bool supportsSaverMode() override {
        return false;
    }

    string getName() override {
        return "FRIDGE";
    }
};

class AirConditioner : public Appliance {
public:
    AirConditioner(double h) : Appliance(1500, h) {}

    double calculateUnits(bool saver) override {
        double units = power * hours / 1000.0;
        return saver ? units * 0.75 : units;
    }

    bool supportsSaverMode() override {
        return true;
    }

    string getName() override {
        return "AC";
    }
};

class Television : public Appliance {
public:
    Television(double h) : Appliance(100, h) {}

    double calculateUnits(bool saver) override {
        return power * hours / 1000.0;
    }

    bool supportsSaverMode() override {
        return false;
    }

    string getName() override {
        return "TV";
    }
};

class Washer : public Appliance {
public:
    Washer(double h) : Appliance(500, h) {}

    double calculateUnits(bool saver) override {
        double units = power * hours / 1000.0;
        return saver ? units * 0.75 : units;
    }

    bool supportsSaverMode() override {
        return true;
    }

    string getName() override {
        return "WASHER";
    }
};

int main() {
    int n;
    cin >> n;

    double totalCost = 0.0;

    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        string type, mode;
        double hours;
        cin >> type >> hours;

        bool saver = false;

        // Read SAVER only when it is present.
        // The next appliance name must not be consumed accidentally.
        if (type == "AC" || type == "WASHER") {
            // Handled below using input parsing approach
        }

        Appliance* appliance = nullptr;

        if (type == "FRIDGE") {
            appliance = new Fridge(hours);
        } else if (type == "AC") {
            appliance = new AirConditioner(hours);
        } else if (type == "TV") {
            appliance = new Television(hours);
        } else if (type == "WASHER") {
            appliance = new Washer(hours);
        }

        if (appliance == nullptr) {
            continue;
        }

        // Saver input is optional and belongs only to AC/WASHER.
        // The input format is line-based, so use the line's remaining text.
        string line;
        getline(cin, line);

        if ((type == "AC" || type == "WASHER") &&
            line.find("SAVER") != string::npos) {
            saver = true;
        }

        if (saver && !appliance->supportsSaverMode()) {
            cout << appliance->getName()
                 << ": saver mode not supported" << endl;
        } else {
            double units = appliance->calculateUnits(saver);
            double cost = units * 8.0;

            cout << appliance->getName()
                 << ": Units=" << units
                 << " Cost=" << cost << endl;

            totalCost += cost;
        }

        delete appliance;
    }

    cout << "Total Cost: " << totalCost << endl;

    return 0;
}
```
