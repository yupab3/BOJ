#include <iostream>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int userY, userM, userD, stdY, stdM, stdD, Mage, Sage, Uage;
    cin >> userY >> userM >> userD >> stdY >> stdM >> stdD;
    Mage = stdY - userY - 1 * (userY < stdY) + ((userY < stdY) && ((userM < stdM) || ((userM == stdM) && (userD <= stdD))));
    Sage = stdY - userY + 1;
    Uage = Sage - 1;
    cout << Mage << '\n' << Sage << '\n' << Uage << '\n';
    return 0;
}