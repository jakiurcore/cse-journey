# 003 - Majority Element

**Problem:** Find the number that appears **more than n/2 times**. It is guaranteed to exist.

```
[2, 2, 1, 1, 1, 2, 2]   n = 7, needs > 3 times
 2 appears 4 times  -> answer 2
```

---

## My approach: sort, then count runs  (`main.cpp`)

**Idea:** After sorting, equal numbers sit side by side. Then I just measure how long each run is and remember the longest.

```
original: [2, 2, 1, 1, 1, 2, 2]
sorted:   [1, 1, 1, 2, 2, 2, 2]
           \_____/  \________/
           run = 3   run = 4   <- longest run = the majority
```

Walking the sorted array:

```
i=1  1==1  cnt=2   best so far: (cnt 2, number 1)
i=2  1==1  cnt=3   best so far: (cnt 3, number 1)
i=3  1!=2  cnt=1
i=4  2==2  cnt=2
i=5  2==2  cnt=3
i=6  2==2  cnt=4   4 > 3 -> best = (cnt 4, number 2)
```

An array with one element is handled up front (`size < 2`).

- **Time:** O(n log n). The sort is the expensive part; the scan is O(n).
- **Memory:** O(1) extra. The sort works in place. (It changes the caller's array, though.)

---

## The comment at the top of the file

I wrote that I wanted **O(n) time and O(1) memory**. This sort version is O(1) memory but **not** O(n) time. The goal is reachable with the next trick.

### Better: Boyer-Moore voting (O(n) time, O(1) memory)

Think of a vote. Each different number cancels one vote of the candidate. The majority has more than half of the votes, so it cannot be fully cancelled.

```
[2, 2, 1, 1, 1, 2, 2]

x=2  cand=2 count=1
x=2  cand=2 count=2
x=1  count=1   (cancel)
x=1  count=0   (cancel)
x=1  count=0 -> new cand=1 count=1
x=2  count=0   (cancel)
x=2  count=0 -> new cand=2 count=1   -> answer 2
```

## Comparison

| Approach              | Time       | Memory | Note                           |
|-----------------------|------------|--------|--------------------------------|
| Hash map of counts    | O(n)       | O(n)   | Easy to reason about           |
| **Sort + count (mine)** | O(n log n) | O(1)   | Simple, modifies input         |
| Sort, take middle `nums[n/2]` | O(n log n) | O(1) | Even shorter: majority always covers the middle |
| Boyer-Moore voting    | **O(n)**   | **O(1)** | The best, the goal I wanted  |

**Lesson to remember:** "More than half" is a strong promise. It means the majority survives cancellation, and it always covers the middle of the sorted array.
