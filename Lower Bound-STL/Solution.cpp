#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void read_input();
void execute_queries();

int n; //Amount of Numbers
int q; //Amount of queries
vector<int> intVector;
vector<int> queries;

int main() {
    read_input();
    execute_queries();
    return 0;
}

void read_input() {
    cin >> n;
    intVector.reserve(n);
    int value;

    for(int i = 0; i < n; i++) {
        cin >> value;
        intVector.emplace_back(value);
    }
    
    cin >> q;
    queries.reserve(q);
    
    for(int i = 0; i < q; i++){
        int value;
        cin >> value;
        queries.emplace_back(value); 
    }
}

void execute_queries() {
    for (auto it : queries) {
        auto lowIndex = lower_bound(intVector.begin(), intVector.end(), it);
        if(intVector[lowIndex - intVector.begin()] == it){
            cout << "Yes " << (lowIndex - intVector.begin() + 1) << endl;
        }
        else {
            cout << "No " << (lowIndex - intVector.begin() + 1) << endl;
        }
    }
}
