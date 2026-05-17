/*
Problem Idea:
We are given a circular field with n positions.
Two players are standing at positions x1 and x2.

Since the positions form a circle:
- We can move clockwise
- Or anticlockwise

The minimum distance between x1 and x2 on a circle is:

min(
    abs(x2 - x1),          // direct distance
    n - abs(x2 - x1)       // circular distance
)

Then k is added to the final answer.

--------------------------------------------------

Explanation of Logic:

1. abs(x2 - x1)
   Finds normal/direct distance.

2. n - abs(x2 - x1)
   Finds distance if we move through the other side
   of the circle.

3. min(...)
   Chooses the shorter path.

4. + k
   Additional moves/time given in the problem.

--------------------------------------------------

Special Case:
If n <= 3:
Output is always 1 according to the condition used.

--------------------------------------------------

Time Complexity:
O(1) per test case

*/

#include<iostream>
#include<cmath>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n, x1, x2, k;

        // n  -> total positions in circle
        // x1 -> first position
        // x2 -> second position
        // k  -> extra value added to answer

        cin >> n >> x1 >> x2 >> k;

        // Special case
        if(n <= 3){

            cout << 1 << endl;

        }
        else{

            // Minimum circular distance
            int directDistance = abs(x2 - x1);

            int circularDistance = n - directDistance;

            int minimumDistance =
                min(directDistance, circularDistance);

            cout << minimumDistance + k << endl;
        }
    }
}