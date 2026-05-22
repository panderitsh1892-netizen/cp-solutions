/*
Problem: optimal purchase

Topic: Greedy, Math

Key Idea:
We need to minimize the total cost of buying n items.

There are two pricing options:

1. Buy one item individually
   Cost = a

2. Buy a pack of 3 items
   Cost = b

The program checks all useful possibilities
and prints the minimum total cost.

--------------------------------------------------

Step-by-Step Explanation

--------------------------------------------------

Option 1:
Buy all items individually.

Cost:
n * a

Code:
cost1 = n * a

--------------------------------------------------

Option 2:
Use as many packs of 3 as possible,
then buy remaining items individually.

Example:
n = 8

8 / 3 = 2 packs
Remaining = 2 items

Cost:
2*b + 2*a

Code:
cost2 = (n/3)*b + (n%3)*a

--------------------------------------------------

Option 3:
Buy everything using only packs of 3,
even if extra items are purchased.

Why?

Sometimes buying one extra pack is cheaper
than buying remaining items individually.

--------------------------------------------------

Example

n = 5
a = 10
b = 15

Option 2:
1 pack + 2 singles
= 15 + 20
= 35

Option 3:
2 packs
= 30

Better.

--------------------------------------------------

Formula

((n+2)/3)

This computes ceiling(n/3).

Examples:

n = 5
(5+2)/3 = 2

n = 7
(7+2)/3 = 3

--------------------------------------------------

Code:
cost3 = ((n+2)/3) * b

--------------------------------------------------

Final Answer

Take minimum among:
1. All singles
2. Mixed approach
3. Only packs

Code:
min(cost1, min(cost2, cost3))

--------------------------------------------------

Why Greedy Works

Only these three meaningful possibilities exist.

Checking all of them guarantees
minimum cost.

--------------------------------------------------

Example Walkthrough

n = 7
a = 4
b = 10

--------------------------------------------------

Option 1:
7*4 = 28

--------------------------------------------------

Option 2:
2 packs + 1 single

= 20 + 4
= 24

--------------------------------------------------

Option 3:
3 packs

= 30

Minimum:
24

--------------------------------------------------

Important Concepts Learned

1. Ceiling division trick:
   (n+2)/3

2. Sometimes buying extra quantity
   can reduce overall cost.

3. Greedy comparison between
   multiple pricing strategies.

--------------------------------------------------

Common Mistakes

1. Forgetting ceiling division.
2. Not checking overbuying strategy.
3. Using int instead of long long.

--------------------------------------------------

Time Complexity

O(1) per test case
*/

#include<iostream>
#include<algorithm>

using namespace std;

int main() {

    long long t;
    cin >> t;

    while(t--) {

        long long n, a, b;

        cin >> n >> a >> b;

        // Option 1:
        // Buy all individually
        long long cost1 = n * a;

        // Option 2:
        // Use packs + remaining singles
        long long cost2 =
            (n / 3) * b + (n % 3) * a;

        // Option 3:
        // Buy only packs (possibly extra items)
        long long cost3 =
            ((n + 2) / 3) * b;

        // Minimum cost
        cout << min(cost1,
                    min(cost2, cost3))
             << endl;
    }

    return 0;
}