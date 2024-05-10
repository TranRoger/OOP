#include <iostream>
#include "IFace.h"

void testFace(IFace *fc) {
    IFace *a[3] = { fc, fc->clone(), fc->clone() };
    for (int i = 0; i < 3; i++) {
        a[i]->show();
    }
    std::cout << "The same 3 lines?" << std::endl;

    delete a[1];
    delete a[2];
}

int EyedFace::objCount = 0;
int main() {

    Face fc; 
    Face fc1("Rectangle");
    testFace(&fc1);
    std::cout << "EyedFace objects: " << EyedFace::objCount << std::endl;

    return 0;
}