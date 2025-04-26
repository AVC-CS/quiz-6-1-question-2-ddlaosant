#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to write employee records to file
int writeFile(const string& filename) {
    int numEmployees;
    ofstream outFile(filename);

    cout << "Enter the number of employees: ";
    cin >> numEmployees;
    outFile << numEmployees << endl;

    for (int i = 0; i < numEmployees; ++i) {
        int id;
        string name, dept;
        double salary;

        cout << "Enter Employee " << i + 1 << " ID: ";
        cin >> id;
        cout << "Enter Employee " << i + 1 << " Name: ";
        cin >> name;
        cout << "Enter Employee " << i + 1 << " Department: ";
        cin >> dept;
        cout << "Enter Employee " << i + 1 << " Salary: ";
        cin >> salary;

        outFile << id << " " << name << " " << dept << " " << salary << endl;
    }

    outFile.close();
    return numEmployees;
}

// Function to read employee records from file
int readFile(const string& filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "Error opening file: " << filename << endl;
        return 0;
    }

    int numEmployees;
    inFile >> numEmployees;

    int id;
    string name, dept;
    double salary;
    double totalSalary = 0;

    cout << "\nID\tName\tDepartment\tSalary\n";

    for (int i = 0; i < numEmployees; ++i) {
        inFile >> id >> name >> dept >> salary;
        cout << id << "\t" << name << "\t" << dept << "\t\t" << salary << endl;
        totalSalary += salary;
    }

    double average = (numEmployees > 0) ? totalSalary / numEmployees : 0;
    cout << "\nTotal Salary: " << totalSalary << "\tAverage Salary: " << average << endl;

    inFile.close();
    return numEmployees;
}

#endif
