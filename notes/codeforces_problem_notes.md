# Codeforces Problem Notes

---

## 1.Remilia plays soku

### Topic
Math,Games, Implementation

### Key Observation
In circular movement:
min(abs(a-b), n-abs(a-b))

### Mistake
Forgot wrap-around path.
For n<=3 the answer is only one .

### Learning
Always check circular traversal.

---

## 2.Marisa steals Reimu's takeout

## Topic
Greedy, Counting

### Key Observation
Best strategy is:
1. Use all 0s directly.
2. Pair 1s and 2s first.
3. Remaining equal numbers can form groups of 3.

### Greedy Idea
Using one 1 and one 2 together is optimal,
so always form those pairs first.

Formula:
pairs = min(c1, c2)

After pairing:
- remaining 1s contribute as c1/3
- remaining 2s contribute as c2/3

### Mistake to Avoid
1. Forgetting to decrease c1 and c2 after pairing.
2. Using max instead of min.
3. Forgetting integer division.

### Learning
When frequencies are involved:
- think about counting,
- pairing,
- and greedy grouping.

### Time Complexity
O(n)