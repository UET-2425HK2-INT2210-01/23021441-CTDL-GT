#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int pairCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (A[i] == A[j]) {
                pairCount++;
            }
        }
    }

    cout << pairCount << endl;
    return 0;
}
