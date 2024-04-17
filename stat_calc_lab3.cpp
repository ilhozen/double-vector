#include "Double_Vector.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

void addData(Double_vector& dataVector){
    cout << "Enter numeric data(separate values by spaces) : ";
    string data;
    getline(cin, data);

    stringstream dataStream(data);
    double val;

    while (dataStream >> val) {
        dataVector.push_back(val);
    }
    cout << "Data added successfully.\n" << endl;
}

void calculateMean(const Double_vector& dataVector){
    double mean = 0.0;
    for (int i = 0; i < dataVector.size(); i++) {
        mean += dataVector[i];
    }
    mean = mean / dataVector.size();

    cout << "Mean: " << mean << endl << endl;
}

void calculateMedian(const Double_vector& dataVector){
    double median = 0.0;
    double temp;
    Double_vector tempVector = dataVector;
    for (int i = 0; i < tempVector.size() - 1; i++) {

        for (int j = 0; j < tempVector.size() - i - 1; j++) {

            if (tempVector[j] > tempVector[j + 1]) {

                temp = tempVector[j];
                tempVector[j] = tempVector[j + 1];
                tempVector[j + 1] = temp;

            }
        }
    }
    if (tempVector.size() % 2) {
        median = tempVector[tempVector.size() / 2];
    }
    else {
        median = tempVector[tempVector.size() / 2] + tempVector[(tempVector.size() / 2) - 1];
        median = median / 2;
    }
    cout << "Median: " << median << endl << endl;
}

void calculateStandardDeviation(const Double_vector& dataVector){
    double mean = 0.0;
    double standard_dev = 0.0;
    for (int i = 0; i < dataVector.size(); i++) {
        mean += dataVector[i];
    }
    mean = mean / dataVector.size();
    for (int i = 0; i < dataVector.size(); i++) {
        standard_dev += pow(dataVector[i] - mean, 2);
    }
    standard_dev = standard_dev / dataVector.size();
    standard_dev = sqrt(standard_dev);

    cout << "Standard Deviation: " << standard_dev << endl << endl;
}

void displayData(const Double_vector& dataVector){
    cout << "Current Data: ";
    for (int i = 0; i < dataVector.size(); i++) {
        cout << dataVector[i] << " ";
    }
    cout << endl << endl;
}

void showMenu() {
    cout << "=== Statistics Calculator ===\n"
         << "1. Add Data\n"
         << "2. Calculate Mean\n"
         << "3. Calculate Median\n"
         << "4. Calculate Standard Deviation\n"
         << "5. Display Data\n"
         << "6. Exit\n"
         << "Enter your choice: ";
}

void runStatisticsCalculator() {
    Double_vector dataVector;
    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                addData(dataVector);
                break;
            case 2:
                calculateMean(dataVector);
                break;
            case 3:
                calculateMedian(dataVector);
                break;
            case 4:
                calculateStandardDeviation(dataVector);
                break;
            case 5:
                displayData(dataVector);
                break;
            case 6:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);
}

int main() {
    runStatisticsCalculator();
    return 0;
}
