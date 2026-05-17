# Codeforces Problem Notes

---

## Remilia plays soku

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