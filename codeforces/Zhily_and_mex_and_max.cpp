/*
question:zhily and mex and max

Topic: Greedy, Sorting, MEX, Prefix Processing

Key Idea:
Rearrange the array in a smart order so that
the sum of:

(maximum element + mex)

over all prefixes becomes as large as possible.

--------------------------------------------------

Important Concepts

1. MX (Maximum)
Largest value seen so far in prefix.

2. MEX
Smallest non-negative integer not present
in the prefix.

Example:
[0,1,2,4]

mex = 3

--------------------------------------------------

Step 1: Sort Array

sort(a+1, a+n+1)

This helps organize duplicates together.

--------------------------------------------------

Step 2: Put Maximum Element First

swap(a[1], a[n])

Why?

If maximum element appears early,
then every prefix gets a larger "mx" value.

This maximizes contribution to answer.

--------------------------------------------------

Step 3: Sort Remaining Elements

sort(a+2, a+n+1)

Now remaining elements are sorted.

--------------------------------------------------

Step 4: Separate Distinct and Duplicate Values

We create:

v1 -> distinct values
v2 -> duplicates

Logic:

if current value already appeared before:
    put into duplicates

Else:
    put into distinct list

--------------------------------------------------

Why Separate Duplicates?

Distinct small values help increase mex quickly.

Duplicates do not improve mex immediately.

So:
- place unique values earlier
- place duplicates later

This greedily maximizes mex contribution.

--------------------------------------------------

Step 5: Rebuild Array

Final order:

[max_element][distinct values][duplicates]

This arrangement helps:
1. mx become large early
2. mex increase quickly

--------------------------------------------------

Step 6: Calculate Answer

For every prefix:

mx = maximum element so far
mex = smallest missing number

Add:
mx + mex

to answer.

--------------------------------------------------

How MEX is Calculated

mp[x] stores frequency.

while(mp[mex])
    mex++;

Keep increasing mex until a missing value appears.

--------------------------------------------------

Example

Suppose:

[0,1,1,2]

Rearranged:
[2,0,1,1]

Prefixes:

[2]
mx=2 mex=0

[2,0]
mx=2 mex=1

[2,0,1]
mx=2 mex=3

etc.

--------------------------------------------------

Why Greedy Works

1. Large maximum early improves all prefixes.
2. Unique values early increase mex rapidly.
3. Duplicates are less useful initially.

--------------------------------------------------

Time Complexity

Sorting:
O(n log n)

MEX processing:
O(n)

Overall:
O(n log n)

--------------------------------------------------

Common Mistakes

1. Forgetting to clear map for each testcase.
2. Wrong mex update logic.
3. Not separating duplicates properly.
4. Confusing mex with minimum value.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

#define ll long long

int a[200005];
map<int,int> mp;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {

        int n;
        cin >> n;

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        // Step 1: Sort array
        sort(a + 1, a + n + 1);

        // Step 2: Put maximum element first
        swap(a[1], a[n]);

        // Step 3: Sort remaining elements
        sort(a + 2, a + n + 1);

        vector<int> v1, v2;

        // Step 4: Separate unique and duplicate values
        for(int i = 2; i <= n; i++) {

            if(!v1.empty() && v1.back() == a[i]) {

                // Duplicate value
                v2.push_back(a[i]);
            }
            else {

                // Distinct value
                v1.push_back(a[i]);
            }
        }

        // Step 5: Rebuild array
        int t = 1;

        for(int i = 0; i < v1.size(); i++) {
            a[++t] = v1[i];
        }

        for(int i = 0; i < v2.size(); i++) {
            a[++t] = v2[i];
        }

        ll ans = 0;

        mp.clear();

        int mex = 0;
        int mx = 0;

        // Step 6: Calculate answer for all prefixes
        for(int i = 1; i <= n; i++) {

            // Add current value
            mp[a[i]]++;

            // Update maximum
            mx = max(mx, a[i]);

            // Update mex
            while(mp[mex]) {
                mex++;
            }

            // Add contribution
            ans += mx + mex;
        }

        cout << ans << '\n';
    }

    return 0;
}