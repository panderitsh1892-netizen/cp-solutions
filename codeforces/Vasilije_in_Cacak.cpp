/*
question:vasilije in cacak

Topic: Math, Greedy Observation

Key Idea:
Determine whether it is possible to obtain
a sum k using exactly x distinct numbers
from 1 to n.

Instead of checking all combinations,
we only compare:
1. Minimum possible sum
2. Maximum possible sum

If k lies between them:
Answer = YES

Otherwise:
NO

--------------------------------------------------

Important Observation

To choose exactly x distinct numbers from 1 to n:

Minimum sum:
Take the smallest x numbers.

1 + 2 + 3 + ... + x

Formula:
x(x+1)/2

--------------------------------------------------

Maximum sum:
Take the largest x numbers.

n + (n-1) + ... + (n-x+1)

Formula:
n(n+1)/2 - (n-x)(n-x+1)/2

--------------------------------------------------

Why Multiply by 2?

Instead of writing fractions:

x(x+1)/2

code multiplies everything by 2
to avoid floating point division.

So conditions become:

2*k >= x(x+1)

and

2*k <= n(n+1) - (n-x)(n-x+1)

--------------------------------------------------

Step-by-Step Logic

--------------------------------------------------

Step 1:
Compute minimum possible sum.

Minimum:
1 + 2 + ... + x

--------------------------------------------------

Step 2:
Compute maximum possible sum.

Largest x numbers:
n + (n-1) + ...

--------------------------------------------------

Step 3:
Check whether k lies in this range.

If yes:
possible.

Else:
impossible.

--------------------------------------------------

Example

n = 5
x = 2

Possible pairs:
(1,2)=3
(1,3)=4
(1,4)=5
...
(4,5)=9

Minimum = 3
Maximum = 9

Any k between 3 and 9 is possible.

--------------------------------------------------

Condition Used

if(
    2*k >= x*(x+1)
    &&
    2*k <= n*(n+1)-(n-x)*(n-x+1)
)

--------------------------------------------------

Why This Works

Any sum between:
minimum possible
and
maximum possible

can be formed using x distinct numbers.

--------------------------------------------------

Time Complexity
O(1) per test case

--------------------------------------------------

Common Mistakes

1. Forgetting arithmetic sum formula.
2. Integer overflow
→ use long long.
3. Confusing largest x numbers formula.
4. Forgetting why multiplication by 2 is used.
*/

#include <iostream>

using namespace std;

int main(){

	int t;
	cin >> t;

	while(t--){

		long long n, x, k;

		cin >> n >> x >> k;

		// Check if k lies between
		// minimum and maximum possible sums
		if(
			2*k >= x*(x+1)
			&&
			2*k <= n*(n+1) - (n-x)*(n-x+1)
		){

			cout << "YES\n";
		}
		else{

			cout << "NO\n";
		}
	}
}