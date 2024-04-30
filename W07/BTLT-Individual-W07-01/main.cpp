#include <iostream>
#include "Gate.h"
#include "Prince.h"
#include "SavePrincess.h"
#include "CastleInputProvider.h"
#include "PrinceInputProvider.h"
using namespace std;

int main() {
    Prince prince = PrinceInputProvider::next();
    Castle castle = CastleInputProvider::next();
    SavePrincess::savePrincess(prince, castle);

    return 0;
}