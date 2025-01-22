#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> numbers;
    int n; 
    cin >> n;
    numbers.reserve(n);
    
    for(int i = 0; i < n; i++) {
        int value;
        cin >> value;
        numbers.emplace_back(value);
    }
    sort(numbers.begin(), numbers.end());

    for (auto number: numbers) {
        cout << number;
        cout << " ";
    }
    
    return 0;
}
