#include <iostream>
#include <string>
#include <array>
#include <fstream>
#include <iomanip>

using namespace std;

int n = 0;

struct frequency {
    string name;
    int count;

    frequency(string n, int c) {
        name = n;
        count = c;
    }
    frequency() {}
};

bool isPunctuation(char c) {
    string punctuations = "!,.;:";
    for(int i = 0; i < punctuations.length(); i++) {
        if(c == punctuations[i]) return true;
    }
    return false;
}

string removeTrailing(string s) {
    while(isPunctuation(s.back())) {
        s.pop_back();
    }
    return s;
}
int search(frequency* dict, string s) {
    int location = -1;
    for(int i = 0; i < n; i++) {
        if(dict[i].name == s) location = i;
    }
    return location;
}
void report(frequency* dict) {
    cout << "Word:               " << "Frequency: " << endl;
    for(int i = 0; i < n; i++) {
        cout << setw(10) << dict[i].name << "              " << dict[i].count << endl;
    }
    cout << "..." << endl;
}
frequency* read(string filename) {
    ifstream is (filename);
    string temp;

    frequency* dict = new frequency[5];
    int max = 5;

    while(is >> temp) {
        temp = removeTrailing(temp);
        int loc = search(dict, temp);
        if(loc > -1) {
            dict[loc].count = dict[loc].count + 1;
        }
        else {
            if(n == max) {
                frequency* temp =  new frequency[2*max];
                for(int i = 0; i < n; i++) {
                    temp[i] = dict[i];
                }
                max = 2*max;
                dict = temp;
            }
            dict[n] = frequency(temp, 1);
            n++;
        }
    }
    return dict;
}

int main () {
    frequency* dict = read("sample.txt");
    report(dict);
}

