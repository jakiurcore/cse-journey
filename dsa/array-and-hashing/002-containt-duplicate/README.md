# 002 - Contains Duplicate

**Problem:** Does any value appear **at least twice** in the array? Return true or false.

```
[1, 2, 3, 1]  -> true   (1 appears twice)
[1, 2, 3, 4]  -> false
```

---

## My approach: hash map  (`main.cpp`)

**Idea:** Walk through the array and keep a "seen" box. For each number, check the box first.

```
nums = [1, 2, 3, 1]

x=1  box={}          not there -> put it in   box={1}
x=2  box={1}         not there -> put it in   box={1,2}
x=3  box={1,2}       not there -> put it in   box={1,2,3}
x=1  box={1,2,3}     ALREADY THERE -> duplicate! return true
```

If I reach the end without a hit, every number was new, so return false.

Early exit helps: I stop the moment I see the first repeat.

- **Time:** O(n). One pass, and each lookup is O(1) on average.
- **Memory:** O(n). The box can grow to hold all numbers.

---

## Other ways to think about it

| Approach              | Time       | Memory | Why                                    |
|-----------------------|------------|--------|----------------------------------------|
| Brute force (compare all pairs) | O(n²) | O(1)   | Simple but slow                  |
| Sort, then compare neighbours   | O(n log n) | O(1)* | Duplicates end up side by side    |
| **Hash map / set** (this one)   | **O(n)**   | O(n)  | Fastest, costs memory             |

\* if sorting in place.

**Small improvement:** a map stores a useless value (`1`) next to each key. Since I only care whether a number *exists*, `unordered_set<int>` says the same thing more clearly.

**Lesson to remember:** "Have I seen this before?" is the signature of a hash set.
