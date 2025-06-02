#include "Array.h"

int main() {
    Array<int> A(2, 3, 5);
    Array<int> B = { {1, 2, 3}, {4, 5, 6} };
    Array<int> C = A + B;
    Array<int> D = C * 2;
    Array<int> E = 10 + D;

    std::cout << "Array E:\n" << E;
}