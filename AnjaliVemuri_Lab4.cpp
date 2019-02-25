#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Salaried {
    private:
        double salary;
        bool bonus;
        string sename;
    public:
        double getWeeklys();
        string getSEName();
        char bonusStatus();
        void addSE();
};

class Hourly {
    private:
        double wage;
        int hours;
        string hname;
    public:
        double getWage();
        int getHours();
        string getHName();
        double getWeeklyh();
        void addHEmployee();
};

class Commissioned {
    private:
        double base = 500;
        int sales;
        string cname;
    public:
        double getWeeklyc();
        string getCName();
        int getSales();
        void addCEmployee();
};


int main () {
    Salaried s1, s2;
    Hourly h1, h2;
    Commissioned c1, c2;

    s1.addSE();
    s2.addSE();
    h1.addHEmployee();
    h2.addHEmployee();
    c1.addCEmployee();
    c2.addCEmployee();

    cout << " " << endl;
    cout << "Name          Status          Hours  Sales     Wages     Pay" << endl;
    cout << s1.getSEName() << setw(20) << "Salaried" << "        -      -         -         $" << fixed << setprecision(2) << s1.getWeeklys() << s1.bonusStatus() << endl;
    cout << s2.getSEName() << setw(10) << "Salaried" << "        -      -         -         $" << fixed << setprecision(2) << s2.getWeeklys() << s2.bonusStatus() << endl;
    cout << h1.getHName() << setw(11) << "Hourly" << setw(12) << h1.getHours() << setw(9) << "     -         " <<  fixed << setprecision(2) << "$" << h1.getWage() << setw(5) << "$" << fixed << setprecision(2) << h1.getWeeklyh() << endl;
    cout << h2.getHName() << setw(11) << "Hourly" << setw(12) << h2.getHours() << setw(9) << "     -         " <<  fixed << setprecision(2) << "$" << h2.getWage() << setw(5) << "$" << fixed << setprecision(2) << h2.getWeeklyh() << endl;
    cout << c1.getCName() << setw(18) << "Commissioned" << "    -" << setw(7) << "$" << c1.getSales() << setw(6) << "    -         " << fixed << setprecision(2) << "$" << c1.getWeeklyc() << endl;
    cout << c2.getCName() << setw(18) << "Commissioned" << "    -" << setw(7) << "$" << c2.getSales() << setw(6) << "    -         " << fixed << setprecision(2) << "$" << c2.getWeeklyc() << endl;

}

double Salaried::getWeeklys() {
    if (bonus == true) {
        salary = salary * 1.1;

        return salary;
    }
    else {
        return salary;
    }
}

string Salaried::getSEName() {
    return sename;
}

char Salaried::bonusStatus() {
    char result;
    if (bonus == true) {
        result = '*';

        return result;
    }
    else {
        result = ' ';

        return result;
    }
}

void Salaried::addSE() {
    char x;

    cout << "Please enter the name of the salaried employee: " << endl;
    getline (cin, sename);
    getline (cin, sename);
    cout << "Please enter the weekly salary of this employee: ";
    cin >> salary;
    cout << "Would you like to give this employee a 10% salary bonus? (answer y or n): ";
    cin >> x;
    if (x == 'y') {
       bonus = true;
    }
    else {
        bonus = false;
    }
    cout << "The employee has been added to the payroll." << endl;

}

double Hourly::getWage() {
    return wage;
}

int Hourly::getHours() {
    return hours;
}

string Hourly::getHName() {
    return hname;
}

double Hourly::getWeeklyh() {
    if (hours > 40) {
        int overtime;
        double pay;
        overtime = hours - 40;
        pay = (40 * wage) + (2 * overtime * (hours - 40));

        return pay;
    }
    else {
        double pay;
        pay = hours * wage;

        return pay;
    }
}

void Hourly::addHEmployee() {
    cout << "Please enter the name of the hourly employee: " << endl;
    getline (cin, hname);
    getline (cin, hname);
    cout << "Please enter this employees hourly rate: ";
    cin >> wage;
    cout << "Please enter the number of hours this employee has worked this week: ";
    cin >> hours;
    cout << "The employee has been added to the payroll." << endl;
}

double Commissioned::getWeeklyc() {
    double pay;
    pay = base + (0.1 * sales);

    return pay;
}

string Commissioned::getCName() {
    return cname;
}

int Commissioned::getSales() {
    return sales;
}

void Commissioned::addCEmployee() {
    cout << "Please enter the name of the commissioned employee: " << endl;
    getline (cin, cname);
    getline (cin, cname);
    cout << "Please enter the sales this employee has made: ";
    cin >> sales;
    cout << "The employee has been added to the payroll." << endl;
}
