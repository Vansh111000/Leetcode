#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

int main() {
    const int N = 5000;
    ofstream out("array.txt");

    mt19937 rng(42);  // fixed seed → same input every time
    uniform_int_distribution<int> dist(1, 100000);

    for (int i = 0; i < N; i++) {
        out << dist(rng) << " ";
    }

    out.close();
    return 0;
}