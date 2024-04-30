#pragma once

#include <iostream>
#include "Prince.h"
#include "Castle.h"

class SavePrincess {
public:
    static bool savePrincess(Prince prince, Castle castle) {
        for (auto g : castle.gates()) {
            if (false == g->passTheGate(prince)) {
                cout << "Incapable to save the princess." << endl;
                return false;
            }
        }
        cout << "You saved the princess! Remaining stats: " << endl;
        prince.stats();
        return true;
    }
};