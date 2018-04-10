#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i=0;i<(int)(n);i++)

int main() {
    string a, b;
    cin >> a >> b;
    reverse(b.begin(), b.end());
    cout << (a==b?"YES":"NO") << endl;
}