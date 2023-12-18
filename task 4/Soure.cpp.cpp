#include <iostream>

#define MAX_DISKS 10

int rods[4][MAX_DISKS + 1];
int top[4];

void hanoi(int n, int from_rod, int to_rod, int aux_rod) {
    if (n == 1) {
        std::cout << "1 " << from_rod << " " << to_rod << std::endl;
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    std::cout << n << " " << from_rod << " " << to_rod << std::endl;
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    std::cin >> n;

    int disks[MAX_DISKS];
    for (int i = 0; i < n; ++i) {
        std::cin >> disks[i];
        rods[disks[i]][++top[disks[i]]] = i + 1;
    }

    int from_rod = 1;
    int to_rod = 2;
    int aux_rod = 3;

    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= top[i]; ++j) {
            hanoi(i, from_rod, to_rod, aux_rod);
            from_rod = rods[i][j];
            --top[i];
        }
    }

    return 0;
}
