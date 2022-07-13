#include "town.h"

void Menu(){
    Town town;
    cout << "Enter number family (n): ";
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cout << "Enter info family " << i << endl;
        town.addFamily();
    }
        town.showTownInfo();
}

int main()
{
    Menu();
    return 0;
}
