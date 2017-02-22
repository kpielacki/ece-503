#include <iostream>
#include <vector>
using namespace std;


vector < int > get_counting_nums(int n) {
    vector < int > counting;
    for (int i = 0; i < n; i++) {
        counting.push_back(i);
    }
    return counting;
}


int main() {
    int n = -1;

    
    while (n < 0) {
        cout << "Enter a positive integer: ";
        cin >> n;


        if (n < 0) {
            cout << "Integer must be positive." << endl;
        }
    }

    get_counting_nums(n);

    return 0;
}
