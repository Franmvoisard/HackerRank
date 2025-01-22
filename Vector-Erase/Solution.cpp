#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

void read_input();
void execute_remove_queries();
void print_output();

vector<int> intVector;
int n;

int main() {
    read_input();
    execute_remove_queries();
    print_output();
    return 0;
}

void read_input() {
    cin >> n;
    intVector.reserve(n);
    
    for(int i = 0; i < n; i++){
        int value;
        cin >> value;
        intVector.emplace_back(value);
    }
}

void execute_remove_queries() {    
    int indexToRemove;
    int rangeToRemoveStartIndex;
    int rangeToRemoveEndIndex;
    
    cin >> indexToRemove;
    cin >> rangeToRemoveStartIndex;
    cin >> rangeToRemoveEndIndex;
    
    intVector.erase(intVector.begin() + indexToRemove - 1);
    intVector.erase(intVector.begin() + rangeToRemoveStartIndex - 1, intVector.begin() + rangeToRemoveEndIndex - 1);
}

void print_output() {
    cout << intVector.size() << endl;
    
    for (auto number : intVector) {
        cout << number << " ";
    }
}
