/*
question:zhily and array operating 

Topic: Prefix/Suffix Processing, Greedy Observation

Key Idea:
Traverse the array from right to left.
If the next element is positive,
add it to the current element.

This allows positive influence to spread
towards the left side of the array.

--------------------------------------------------

Step-by-Step Explanation

Example:
Array:
[1, -2, 3, 4]

We move from right to left.

--------------------------------------------------

Loop:

for(int i = n-2; i >= 0; i--)

Starts from second last element because
we check a[i+1].

--------------------------------------------------

Condition:

if(a[i+1] > 0)

Only positive values help increase
previous elements.

Negative values are ignored because
adding them would decrease the current value.

--------------------------------------------------

Operation:

a[i] += a[i+1]

If next value is positive,
carry its contribution backward.

--------------------------------------------------

Example Walkthrough

Initial:
[1, -2, 3, 4]

Step 1:
4 is positive

a[2] = 3 + 4 = 7

Array:
[1, -2, 7, 4]

-------------------

Step 2:
7 is positive

a[1] = -2 + 7 = 5

Array:
[1, 5, 7, 4]

-------------------

Step 3:
5 is positive

a[0] = 1 + 5 = 6

Final array:
[6, 5, 7, 4]

--------------------------------------------------

Counting Positive Elements

After propagation,
count how many elements are positive.

if(a[i] > 0)
    ans++;

--------------------------------------------------

Why This Works

Positive suffix sums can help earlier elements.

Instead of recomputing suffix sums separately,
we propagate positivity directly from right to left.

--------------------------------------------------

Time Complexity:
O(n) per test case

Space Complexity:
O(n)

--------------------------------------------------

Common Mistakes:
1. Traversing from left to right.
2. Forgetting to use long long.
3. Adding negative suffix values.
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){

    int T;
    cin >> T;

    while(T--){

        int n;
        cin >> n;

        vector<long long> a(n);

        // Input array
        for(int i = 0; i < n; i++)
            cin >> a[i];

        // Traverse from right to left
        for(int i = n - 2; i >= 0; i--){

            // Only positive values help
            if(a[i + 1] > 0)

                // Propagate positivity backward
                a[i] += a[i + 1];
        }

        int ans = 0;

        // Count positive elements
        for(int i = 0; i < n; i++){

            if(a[i] > 0)
                ans++;
        }

        cout << ans << '\n';
    }
}