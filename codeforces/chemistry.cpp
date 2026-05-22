/*

question:chemistry

Topic: Strings, Frequency Counting, Palindrome Logic

Key Idea:
A string can be rearranged into a palindrome if:
- at most one character has odd frequency.

Here, we are allowed to perform k operations
that can help reduce the number of odd frequencies.

--------------------------------------------------

Important Palindrome Property

For a palindrome:

1. Even length:
   Every character frequency must be even.

2. Odd length:
   Only one character may have odd frequency.

So:
Number of odd frequency characters
must be <= 1.

--------------------------------------------------

Step 1: Count Frequency

map<char,int> freq;

Stores frequency of every character.

Example:
"aabbc"

a -> 2
b -> 2
c -> 1

--------------------------------------------------

Step 2: Count Odd Frequencies

if(p.second % 2 != 0)

Count characters having odd occurrences.

Example:
a -> 2
b -> 3
c -> 1

Odd frequencies:
b, c

odd = 2

--------------------------------------------------

Step 3: Use k Operations

Each operation can help reduce one odd count.

Remaining odd frequencies:

odd1 = odd - k

--------------------------------------------------

Step 4: Final Check

If remaining odd frequencies <= 1:
Palindrome formation is possible.

if(odd1 <= 1)
    YES
else
    NO

--------------------------------------------------

Example

Input:
aabbccd

Frequencies:
a=2
b=2
c=2
d=1

odd = 1

Already palindrome possible.

--------------------------------------------------

Another Example

abcde

All frequencies odd.

odd = 5

If k = 4:
odd1 = 1

Possible.

--------------------------------------------------

Why This Works

Each operation can effectively fix
one odd frequency character.

Goal:
Reduce odd frequencies to at most 1.

--------------------------------------------------

Time Complexity

Frequency counting:
O(n)

Map traversal:
O(number of distinct characters)

Overall:
O(n)

--------------------------------------------------

Common Mistakes

1. Forgetting palindrome frequency condition.
2. Confusing odd character count with string length.
3. Not understanding why only one odd frequency is allowed.
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        // Frequency map
        map<char,int> freq;

        // Count character frequencies
        for(char ch : s){
            freq[ch]++;
        }

        int odd = 0;

        // Count odd frequency characters
        for(auto p : freq){

            if(p.second % 2 != 0){
                odd++;
            }
        }

        // Remaining odd frequencies
        int odd1 = odd - k;

        // Palindrome possible if <= 1 odd remains
        if(odd1 <= 1){

            cout << "YES" << endl;
        }
        else{

            cout << "NO" << endl;
        }
    }
}