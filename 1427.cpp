<<<<<<< HEAD
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    string str;
    cin>>str;
    sort(str.begin(), str.end(), greater<char>());
    cout<<str;
=======
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    string str;
    cin>>str;
    sort(str.begin(), str.end(), greater<char>());
    cout<<str;
>>>>>>> 0c93815fc02a24b74059a0f147792a3d9d2d9a11
}