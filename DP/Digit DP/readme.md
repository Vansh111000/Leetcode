# Digit DP — Complete Revision Guide

> A comprehensive guide to Digit Dynamic Programming (Digit DP) for Competitive Programming and Interviews.

---

# Table of Contents

1. What is Digit DP?
2. When to Use Digit DP
3. Core Idea
4. Generic Problem Pattern
5. State Design
6. Tight Flag Explained
7. Leading Zero Handling
8. Generic Transition
9. Generic Template
10. Time Complexity
11. Common State Parameters
12. Building Intuition
13. Example Problems
14. Advanced Variations
15. Common Mistakes
16. Debugging Checklist
17. Mental Model for Interviews
18. Master Template Structure
19. Practice Roadmap
20. Quick Revision Sheet

---

# What is Digit DP?

Digit DP is a Dynamic Programming technique used when:

* Numbers can be extremely large.
* Brute force iteration over every number is impossible.
* The property depends on the digits of the number.

Instead of checking every number individually, we count valid numbers digit-by-digit.

---

## Typical Questions

Count numbers in range `[L, R]` such that:

* Sum of digits = K
* Sum of digits divisible by M
* Contains digit 7
* Does not contain digit 4
* Number of odd digits = X
* Adjacent digits differ by at most K
* Digit product satisfies condition
* No repeated digits

---

# When to Use Digit DP

Look for phrases like:

* Count numbers from 1 to N
* Count numbers in range [L, R]
* Digits satisfy condition
* Number length up to 10^18
* Large range queries

If brute force is impossible and constraints involve digits, Digit DP is likely required.

---

# Core Idea

Instead of generating numbers:

```text
0
1
2
3
...
999999999999999999
```

We build the number digit-by-digit.

Example:

```text
N = 583
```

Build:

```text
_
5_
58_
583
```

At every position we decide which digit to place.

DP remembers important information.

---

# Generic Range Formula

Digit DP usually computes:

```text
F(N) = count of valid numbers from 0 to N
```

Then:

```text
Answer = F(R) - F(L-1)
```

This is the most important formula in Digit DP.

---

# State Design

A DP state generally looks like:

```text
dp(pos, tight, state)
```

where:

```text
pos    -> current digit position
tight  -> are we still restricted?
state  -> problem-specific information
```

---

## Example

Suppose:

Count numbers whose digit sum equals K.

State:

```text
dp(pos, tight, sum)
```

Meaning:

```text
Current position
Current restriction
Current digit sum so far
```

---

# Tight Flag Explained

This is the most important concept.

Suppose:

```text
N = 583
```

At first digit:

Possible digits:

```text
0..5
```

because first digit cannot exceed 5.

---

## Case 1

Choose:

```text
digit = 5
```

Still equal to prefix of N.

```text
tight = 1
```

---

## Case 2

Choose:

```text
digit = 3
```

Now number is already smaller.

Remaining digits can be anything.

```text
tight = 0
```

---

# Transition Rule

```text
limit =
tight ? digit_of_N[pos] : 9
```

Loop:

```text
for d in [0..limit]
```

New tight:

```text
newTight =
tight && (d == limitDigit)
```

---

# Leading Zero Handling

Extremely important.

Example:

```text
00045
```

Actually:

```text
45
```

Leading zeros often should not affect:

* Digit sum
* Digit count
* Distinct digit set

---

## Add Started Flag

State:

```text
dp(pos, tight, started)
```

Meaning:

```text
Have we placed first non-zero digit?
```

---

### Example

```text
00045
```

Before 4:

```text
started = false
```

After 4:

```text
started = true
```

---

# Generic State Structure

Most problems use:

```text
dp(
    pos,
    tight,
    started,
    extra_state
)
```

---

# Generic Transition

```text
limit = tight ? digit[pos] : 9

for d in [0..limit]:

    newTight =
        tight && (d == limit)

    newStarted =
        started || (d != 0)

    update extra state

    answer += recurse(...)
```

---

# Base Case

When all digits processed:

```text
pos == length
```

Return:

```text
1 if state valid
0 otherwise
```

Example:

```text
sum == K
```

return:

```text
(sum == K)
```

---

# Generic Template

```cpp
long long solve(
    int pos,
    int tight,
    int started,
    State state
)
{
    if(pos == n)
        return valid(state);

    if(dp exists)
        return dp;

    int limit =
        tight ? digits[pos] : 9;

    long long ans = 0;

    for(int d=0; d<=limit; d++)
    {
        int newTight =
            tight && (d == limit);

        int newStarted =
            started || (d != 0);

        ans += solve(...);
    }

    return dp = ans;
}
```

---

# Complexity

General complexity:

```text
O(
    positions
    × tight
    × states
)
```

For 18-digit numbers:

```text
18 × stateCount
```

which is usually very manageable.

---

# Common State Parameters

## Digit Sum

```text
sum
```

State:

```text
dp(pos,tight,sum)
```

---

## Digit Modulo

Track:

```text
number % M
```

State:

```text
dp(pos,tight,mod)
```

Transition:

```text
newMod =
(mod*10 + digit)%M
```

---

## Count Digit Occurrences

Track:

```text
count7
```

State:

```text
dp(pos,tight,count7)
```

---

## Distinct Digits

Use bitmask.

State:

```text
dp(pos,tight,mask)
```

Mask stores used digits.

---

## No Repeated Digits

State:

```text
dp(pos,tight,mask)
```

Skip digit if already used.

---

## Adjacent Digit Constraints

Remember previous digit.

State:

```text
dp(pos,tight,prevDigit)
```

---

## Previous Digit + Mask

Common hard version:

```text
dp(
 pos,
 tight,
 prev,
 mask
)
```

---

# Building Intuition

Think of a decision tree.

Example:

```text
N = 235
```

Digit choices:

```text
Position 0:
0..2

Position 1:
depends on tight

Position 2:
depends on previous choices
```

DP compresses repeated subproblems.

---

# Example Problem 1

Count numbers ≤ N with digit sum = K.

State:

```text
dp(pos,tight,sum)
```

Base:

```text
sum == K
```

---

# Example Problem 2

Count numbers ≤ N divisible by M.

State:

```text
dp(pos,tight,mod)
```

Transition:

```text
newMod =
(mod*10+d)%M
```

Base:

```text
mod == 0
```

---

# Example Problem 3

Count numbers without digit 4.

State:

```text
dp(pos,tight)
```

Transition:

Skip:

```text
d == 4
```

---

# Example Problem 4

Count numbers with exactly K occurrences of digit 7.

State:

```text
dp(pos,tight,count7)
```

Transition:

```text
if(d==7)
count7++
```

Base:

```text
count7 == K
```

---

# Advanced Variations

## Digit Sum + Modulo

State:

```text
dp(
 pos,
 tight,
 sum,
 mod
)
```

---

## Distinct Digits

State:

```text
dp(
 pos,
 tight,
 mask
)
```

Mask size:

```text
2^10 = 1024
```

---

## Palindrome Constraints

Track:

```text
left half decisions
```

More specialized.

---

## Binary Digit DP

Apply same idea on binary representation.

Useful for:

```text
XOR
Bit constraints
Set bits
```

---

# Common Mistakes

## Mistake 1

Wrong range formula.

Wrong:

```text
F(R)-F(L)
```

Correct:

```text
F(R)-F(L-1)
```

---

## Mistake 2

Forgetting leading zeros.

This causes:

```text
0007
007
07
7
```

to be counted differently.

---

## Mistake 3

Memoizing when tight = 1.

Usually cache only:

```text
tight = 0
```

states.

---

## Mistake 4

Incorrect modulo transition.

Correct:

```text
newMod =
(mod*10+d)%M
```

---

## Mistake 5

Wrong base condition.

Verify:

```text
What exactly defines validity?
```

---

# Debugging Checklist

If answer is wrong:

### Check 1

Range formula:

```text
F(R)-F(L-1)
```

---

### Check 2

Leading zeros.

---

### Check 3

Base case.

---

### Check 4

Tight transition.

---

### Check 5

Memoization dimensions.

---

### Check 6

Digit extraction order.

---

# Interview Mental Model

Interviewer asks:

```text
Count numbers <= N satisfying property P.
```

Immediately think:

```text
1. Can brute force work?
2. Property depends on digits?
3. Large N?
```

If yes:

```text
Digit DP
```

Then define:

```text
Position
Tight
Started
Problem State
```

---

# Master Template Structure

```text
convert N into digits

solve(
    pos,
    tight,
    started,
    state
)

base case

loop digit

update state

recurse

memoize

return
```

---

# Practice Roadmap

### Beginner

* Sum of digits
* Count digit occurrences
* No digit 4

---

### Intermediate

* Divisible by M
* Exact K occurrences
* Adjacent digit constraints

---

### Advanced

* Distinct digits
* Bitmask Digit DP
* Multiple state dimensions

---

### Expert

* Digit DP + Bitmask
* Digit DP + Graph State
* Automaton + Digit DP
* KMP + Digit DP
* Aho-Corasick + Digit DP

---

# Quick Revision Sheet

## Formula

```text
Answer =
F(R)-F(L-1)
```

---

## Core State

```text
(pos,tight,state)
```

or

```text
(pos,tight,started,state)
```

---

## Limit

```text
limit =
tight ? digit[pos] : 9
```

---

## New Tight

```text
tight && (d == limitDigit)
```

---

## Base

```text
pos == n
```

---

## Complexity

```text
O(
positions × states
)
```

---

## Most Common States

```text
sum
mod
count
mask
prevDigit
```

---

## Golden Rule

Digit DP is simply:

"Build numbers digit-by-digit while remembering enough information to determine whether the final number is valid."
