#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

std::map<string,int> studentMarks;

void execute_query(const int& type, const string& name, const int& mark = -1);
void read_and_execute_queries();

int main() {
    read_and_execute_queries();
    return 0;
}

void read_and_execute_queries() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int type;
        int argsNumber;
        string name;
        int mark;
        
        cin >> type;
        
        argsNumber = type == 1 ? 2 : 1;
        
        
        for(int q = 0; q < argsNumber; q++) {
            if(q == 0){
                cin >> name;
            }
            else {
                cin >> mark;
            }
        }
        
        execute_query(type, name, mark);
    }
}

void execute_query(const int& type, const string& name, const int& mark) {
    switch (type) {
        case 1:
            if(studentMarks.find(name) == studentMarks.end()){
                studentMarks.insert(make_pair(name, mark));
            }
            else {
                studentMarks[name] += mark;
            }
        break;
        case 2:
            if(studentMarks.find(name) != studentMarks.end()){
                studentMarks.erase(name);
            }
        break;
        case 3:
            if(studentMarks.find(name) == studentMarks.end()){
                cout << "0" << endl;
            }
            else {
                cout << studentMarks[name] << endl;
            }
        break;
    }
}
