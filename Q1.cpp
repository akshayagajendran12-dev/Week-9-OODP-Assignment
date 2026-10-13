#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Ticket {
protected:
    double convenienceFee = 20.0;

public:
    virtual double getPrice() = 0;

    double calculateAmount(int count) {
        return (getPrice() + convenienceFee) * count;
    }

    virtual ~Ticket() {}
};

class Regular : public Ticket {
public:
    double getPrice() override {
        return 150.0;
    }
};

class Premium : public Ticket {
public:
    double getPrice() override {
        return 250.0;
    }
};

class Recliner : public Ticket {
public:
    double getPrice() override {
        return 400.0;
    }
};

int main() {
    int n;
    cin >> n;

    double total = 0.0;

    for (int i = 0; i < n; i++) {
        string seat;
        int count;
        cin >> seat >> count;

        Ticket* ticket = nullptr;

        if (seat == "REGULAR")
            ticket = new Regular();
        else if (seat == "PREMIUM")
            ticket = new Premium();
        else if (seat == "RECLINER")
            ticket = new Recliner();
        else {
            cout << "Invalid seat type" << endl;
            continue;
        }

        double amount = ticket->calculateAmount(count);

        cout << fixed << setprecision(2);
        cout << seat << ": " << amount << endl;

        total += amount;
        delete ticket;
    }

    cout << fixed << setprecision(2);
    cout << "Total: " << total << endl;

    return 0;
}
```
