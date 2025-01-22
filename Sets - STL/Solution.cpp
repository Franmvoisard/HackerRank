#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

int q;
set<int> intSet;

int main() {
    
    cin >> q;
    for(int i = 0; i < q; i++) {
        int operationType;
        int number;
        
        cin >> operationType;
        cin >> number;
        
        switch (operationType) {
            case 1:
                intSet.insert(number);
            break;
            case 2:
                if(intSet.find(number) != intSet.end()){
                    intSet.erase(number);
                }
            break;
            case 3:
                 if(intSet.find(number) != intSet.end()){
                    cout << "Yes" << endl;
                 }
                 else {
                    cout << "No" << endl;
                 }
            break;
        }
    }
    return 0;
}


