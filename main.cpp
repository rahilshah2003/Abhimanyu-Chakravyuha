#include <iostream>
#include <vector>
using namespace std;
bool Chakravyuha(vector<int>& k, int p, int a, int b) {
    int n = k.size();
    int skips = a;
    int recharges = b;
    int start_power = p;
    
    for (int i = 0; i < n; ++i) {
        // Check if Abhimanyu needs to recharge
        if (p < k[i] && recharges > 0) {
            p = start_power;
            recharges--;
        }
        
        // Check if Abhimanyu needs to skip this enemy
        if (p < k[i] && skips > 0) {
            skips--;
            continue;
        }
        
        // Battle with the enemy
        if (p >= k[i]) {
            p -= k[i];
        } else {
            return false;  // Abhimanyu loses
        }
        
        // Handle special enemies (k3 and k7)
        if (i == 2 || i == 6) {
            int regenerated_Power = k[i] / 2;
            if (i < n - 1) {
                if (p >= regenerated_Power) {
                    p -= regenerated_Power;
                } else if (skips > 0) {
                    skips--;
                } else {
                    return false;
                }
            }
        }
    }
    
    return true;  // Abhimanyu successfully crosses the Chakravyuha
}

int main() {
    int n = 11; // Number of circles in Chakravyuha
    vector<int> k(n);
    int p, a, b;

   
    cout << "Enter initial power: ";
    cin >> p;
    cout << "Enter number of skips available: ";
    cin >> a;
    cout << "Enter number of recharges available: ";
    cin >> b;
    
    cout << "Enter the power of enemies in each circle (11 values):\n";
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
    }

    bool result = Chakravyuha(k, p, a, b);
    
    cout << "Result: " << (result ? "Success" : "Failure") << endl;

    if (result) {
        cout << "Abhimanyu successfully crossed the Chakravyuha" << endl;
    } else {
        cout << "Abhimanyu failed to cross the Chakravyuha." << endl;
    }

    return 0;
}


//TEST CASES 1
//Enter initial power: 100
//Enter number of skips available: 2
//Enter number of recharges available: 1
//Enter the power of enemies in each circle (11 values):
//10 20 30 40 50 60 70 80 90 100 110
//Result: Success
//Abhimanyu successfully crossed the Chakravyuha


//TEST CASES 2
//Enter initial power: 50
//Enter number of skips available: 1
//Enter number of recharges available: 1
//Enter the power of enemies in each circle (11 values):
//20 30 40 50 60 70 80 90 100 110 120
//Result: Failure
//Abhimanyu failed to cross the Chakravyuha.


