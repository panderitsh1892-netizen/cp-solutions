/*
question:disturbing distribution

Topic: Greedy, Array Observation

Key Idea:
The program calculates the sum of all elements
except elements equal to 1.

Then:
if the last element is 1,
add one extra to the answer.

--------------------------------------------------

Step-by-Step Explanation

--------------------------------------------------

Step 1:
Input array.

vector<ll> arr(n)

Stores all elements.

--------------------------------------------------

Step 2:
Calculate sum excluding 1s.

for(ll i=0;i<n;i++){

    if(arr[i] != 1){
        sum += arr[i];
    }
}

--------------------------------------------------

Why Ignore 1?

The logic of the problem considers:
- values other than 1 contribute directly,
- while 1s are handled differently.

So only non-1 elements are added initially.

--------------------------------------------------

Step 3:
Check last element.

if(arr[n-1] == 1)

If last element is 1:
add one extra contribution.

--------------------------------------------------

Logic

Case 1:
Last element is 1

ans = sum + 1

Case 2:
Last element is not 1

ans = sum

--------------------------------------------------

Example

--------------------------------------------------

Example 1

Array:
[1,2,3,1]

Non-1 sum:
2 + 3 = 5

Last element:
1

Final:
5 + 1 = 6

--------------------------------------------------

Example 2

Array:
[1,4,5]

Non-1 sum:
4 + 5 = 9

Last element:
5

Final:
9

--------------------------------------------------

Why This Works

The problem treats:
- normal values,
- and trailing 1 differently.

So:
1. Add all meaningful contributions.
2. Handle last 1 separately.

--------------------------------------------------

Important Implementation Details

1. long long used for large values.
2. Vector stores array dynamically.

--------------------------------------------------

Common Mistakes

1. Forgetting to check last element.
2. Accidentally adding all 1s.
3. Using int instead of long long.

--------------------------------------------------

Time Complexity

Single traversal:
O(n)

Space Complexity:
O(n)
*/

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;

#define ll long long

int main(){

    ll t;
    cin >> t;

    while(t--){

        ll n;
        cin >> n;

        vector<ll> arr(n);

        // Input array
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        int sum = 0;

        // Sum all elements except 1
        for(ll i = 0; i < n; i++){

            if(arr[i] != 1){

                sum += arr[i];
            }
        }

        ll ans;

        // Special handling for last element
        if(arr[n-1] == 1){

            ans = sum + 1;
        }
        else{

            ans = sum;
        }

        cout << ans << endl;
    }
}