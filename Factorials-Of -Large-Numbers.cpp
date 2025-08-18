//Done By->Devansh Pandey 😎.

#include <iostream>
using namespace std;

#define MAX 5000 // 🔹 Maximum number of digits (enough for large n like 1000!)

// 🔹 Function to multiply x with the number represented by res[]
void multiply(int x, int res[], int &resSize) {
    int carry = 0;

    // 🔹 Multiply x with every digit of res[]
    for (int i = 0; i < resSize; i++) {
        int prod = res[i] * x + carry;
        res[i] = prod % 10; // store last digit
        carry = prod / 10;  // rest goes as carry
    }

    // 🔹 Store remaining carry in res[]
    while (carry) {
        res[resSize] = carry % 10;
        carry /= 10;
        resSize++;
    }
}

// 🔹 Function to compute factorial of n
void factorial(int n) {
    int res[MAX];
    res[0] = 1;       // Initialize result as 1
    int resSize = 1;  // Current size of result

    // 🔹 Multiply numbers from 2 to n
    for (int x = 2; x <= n; x++) {
        multiply(x, res, resSize);
    }

    // 🔹 Print result in reverse (MSD first)
    cout << "✨ Factorial of " << n << " is: ";
    for (int i = resSize - 1; i >= 0; i--) {
        cout << res[i];
    }
    cout << " 🎉\n";
}

// 🔹 Driver code
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    factorial(n);
    cout << "\n✅ Done by: Devansh Pandey 😎\n";
    return 0;
}

/*
📌 Time Complexity: O(n * number_of_digits_in_result) 
   (approximately O(n * n log n) for large n!)

📌 Space Complexity: O(MAX) (to store large factorial digits)
*/
