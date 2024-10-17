#include <iostream>
#include <string>
using namespace std;

int minimumSwaps(string s) {
    int swaps=0; //stores minimum number of swaps
    int white_balls=0; //stores number of ones
    int n=s.length();
    for (int i=0;i<n;i++){
        if (s[i]=='0'){
            swaps+=white_balls;
        }
        else if (s[i]=='1'){
            white_balls++;
        }
        
    }
    return swaps;

}

int main() {
    string s;
    cout << "Enter the binary string: ";
    cin >> s;
    
    int result = minimumSwaps(s);
    cout << "Minimum number of swaps: " << result << endl;
    
    return 0;
}
