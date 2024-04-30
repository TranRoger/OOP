#pragma once

#include <iostream>
#include <vector>
#include "IntegerInputProvider.h"
#include "Castle.h"
using namespace std;

class CastleInputProvider {
public:
    static Castle next() {
        system("clear");
        cout << "Enter castle gates information" << endl << endl;
        cout << "Number of gates: ";
        int numberOfGates = IntegerInputProvider::next();
        vector<Gate*> gates;

        for (int i = 0; i < numberOfGates; i++) {
            system("clear");
            cout << "Gate " << i + 1 << endl;
            Gate* gate = GateInputProvider::next();
            gates.push_back(gate);
        }

        Castle result(gates, numberOfGates);
        return result;
    }

    class GateInputProvider { // inner class
    public:
        static Gate* next() {
            cout << "Which kind is this gate? (1. Business gate, 2. Academic gate, 3. Power gate) Pick 1 out of 3 gate: ";
            int opt = IntegerInputProvider::next();
            if (1 == opt) {
                cout << "Quantity: ";
                int qty = IntegerInputProvider::next();
                cout << "Price per unit: ";
                int price = IntegerInputProvider::next();
                BusinessGate *result = new BusinessGate(qty, price);
                return result;
            }
            else if (2 == opt) {
                cout << "IQ requirement: ";
                int iq = IntegerInputProvider::next();
                AcademicGate *result = new AcademicGate(iq);
                return result;
            }
            else {
                cout << "Power requirement: ";
                int power = IntegerInputProvider::next();
                PowerGate *result = new PowerGate(power);
                return result;
            }
        }
    };
};