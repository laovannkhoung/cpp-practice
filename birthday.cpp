#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Birthday {
public:
    string name;
    int day, month, year;
};

Birthday birthdaylist[100];

void saveBirthday() {
    int count;
    cout << "please input how many birthday you want to save: ";
    cin >> count ;

    ofstream outfile("birthdays.txt");
    if (!outfile.is_open()) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    string name;
    int day, month, year;

    for (int i=0 ; i < count ; i++){
    cout << "Enter name: ";
    cin >> name;

    cout << "Enter day: ";
    cin >> day;

    cout << "Enter month: ";
    cin >> month;

    cout << "Enter year: ";
    cin >> year;

    outfile << name << " " << day << " " << month << " " << year <<  "\n";
    }
    outfile.close();
    cout << "Birthday saved successfully!" << endl;
}

void showBirthdays() {
    ifstream infile("birthdays.txt");
    if (!infile.is_open()) {
        cout << "No birthday file found!" << endl;
        return;
    }
    string name;
    int day,month,year;

    cout << "\n===== Birthday List =====" << endl;
    while (infile >> name >> day >> month >> year) {
        cout<< "Name: " << name << "\nday: " << day
             << "\nmonth: " << month << "\nyear: " << year
             << "\n------------------------\n";
    }

    infile.close();
}

void ReadDataFileToArray() {
    ifstream infile("birthdays.txt"); // Open for reading
    if (!infile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    string name;
    int day, month, year;
    int countbirthday = 0;
    while (infile >> name >> day >> month >> year ) {
        if (infile.good()) {
            birthdaylist[countbirthday].name = name;
            birthdaylist[countbirthday].day = day;
            birthdaylist[countbirthday].month = month;
            birthdaylist[countbirthday].year = year;
            countbirthday++;
        }
    }
   infile.close();

    cout << "Number of birthdays loaded: " << countbirthday << endl;
    for (int i = 0; i < countbirthday; i++) {
        cout << "Name: " << birthdaylist[i].name<< " Day: " << birthdaylist[i].day<< " Month: " << birthdaylist[i].month<< " Year: " << birthdaylist[i].year<< endl;
    }
}

int main() {
    int option;

    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Enter Birthday\n";
        cout << "2. Show All Birthdays\n";
        cout << "3. Read Data File to Array\n";
        cout << "-1. Exit\n";
        cout << "Please Select Option: ";
        cin >> option;

        if (option == -1) {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }

        switch (option) {
            case 1:
                saveBirthday();
                break;
            case 2:
                showBirthdays();
                break;
            case 3:
                ReadDataFileToArray();
                break;
            default:
                cout << "Invalid option. Please try again!" << endl;
        }
    }

    return 0;
}
