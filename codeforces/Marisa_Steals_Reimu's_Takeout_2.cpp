/*

question:marisa steals reimu's takeout

Topic: Greedy, Counting

Key Idea:
Count how many 0s, 1s, and 2s exist.
Then greedily form valid groups to maximize answer.

--------------------------------------------------

Logic Explanation:

We count:
c0 -> number of 0s
c1 -> number of 1s
c2 -> number of 2s

--------------------------------------------------

Step 1:
Each 0 directly contributes to answer.

So:
ans += c0

--------------------------------------------------

Step 2:
Pair 1s and 2s together.

Why?
Because one 1 and one 2 form a better/valid group.

Number of such pairs:

min(c1, c2)

Example:
c1 = 4
c2 = 2

Only 2 pairs possible.

So:
pairs = min(c1, c2)

Add pairs to answer:
ans += pairs

Remove used elements:
c1 -= pairs
c2 -= pairs

--------------------------------------------------

Step 3:
Remaining 1s can form groups of 3.

Example:
1 1 1

Number of groups:
c1 / 3

So:
ans += c1 / 3

--------------------------------------------------

Step 4:
Remaining 2s can also form groups of 3.

Example:
2 2 2

Number of groups:
c2 / 3

So:
ans += c2 / 3

--------------------------------------------------

Why Greedy Works?

1. Using 1 and 2 together first is optimal.
2. After pairing, only same numbers remain.
3. Same numbers can only contribute in groups of 3.

--------------------------------------------------

Time Complexity:
O(n) per test case

--------------------------------------------------

Common Mistakes:
1. Forgetting to reduce c1 and c2 after pairing.
2. Using max instead of min for pairs.
3. Forgetting integer division.

*/

#include<iostream>
using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;

        int c0 = 0, c1 = 0, c2 = 0;

        // Counting occurrences
        for(int i = 0; i < n; i++) {

            int x;
            cin >> x;

            if(x == 0)
                c0++;

            else if(x == 1)
                c1++;

            else
                c2++;
        }

        int ans = 0;

        // Every 0 contributes directly
        ans += c0;

        // Pair 1s and 2s
        int pairs = min(c1, c2);

        ans += pairs;

        // Remove used pairs
        c1 -= pairs;
        c2 -= pairs;

        // Remaining 1s in groups of 3
        ans += c1 / 3;

        // Remaining 2s in groups of 3
        ans += c2 / 3;

        cout << ans << endl;
    }

    return 0;
}