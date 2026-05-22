/*
Problem: construct an array 

Topic: Implementation, Constructive Algorithm

Key Idea:
For every test case:
- print n numbers
- starting from 2*n
- decreasing by 1 each time.

--------------------------------------------------

Step-by-Step Explanation

--------------------------------------------------

Step 1:
Read number of test cases.

int t;
cin >> t;

--------------------------------------------------

Step 2:
For every test case:
read n.

--------------------------------------------------

Step 3:
Compute:

z = 2*n

This becomes the starting number.

--------------------------------------------------

Step 4:
Run loop from i = 0 to n-1.

for(int i = 0; i < n; i++)

--------------------------------------------------

Step 5:
Print:

z - i

Meaning:
start from z
and decrease by 1 every iteration.

--------------------------------------------------

Example

n = 5

z = 10

Printed values:

10 9 8 7 6

--------------------------------------------------

Another Example

n = 3

z = 6

Printed values:

6 5 4

--------------------------------------------------

Why This Works

The pattern simply generates:
n consecutive decreasing numbers
starting from 2*n.

--------------------------------------------------

Important Observation

Largest printed value:
2*n

Smallest printed value:
2*n - (n-1)
= n+1

So output always contains numbers:

[n+1 ... 2*n]

--------------------------------------------------

Constructive Idea

Instead of calculating complex arrangements,
the solution directly constructs
a valid sequence using a simple pattern.

--------------------------------------------------

Common Mistakes

1. Wrong loop bounds.
2. Using i <= n instead of i < n.
3. Forgetting spaces/newline formatting.

--------------------------------------------------

Time Complexity

Loop runs n times.

Overall:
O(n) per test case

--------------------------------------------------

Space Complexity

O(1)
*/

#include <iostream>

using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        // Starting value
        int z = 2 * n;

        // Print decreasing sequence
        for (int i = 0; i < n; i++) {

            cout << z - i << " ";
        }

        cout << endl;
    }

    return 0;
}