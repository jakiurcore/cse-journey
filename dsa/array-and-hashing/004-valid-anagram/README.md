# 004 - Valid Anagram

**Problem:** Are `t` and `s` made of exactly the same letters, just rearranged?

```
s = "listen"   t = "silent"   -> true
s = "rat"      t = "car"      -> false
```

---

## My approach: count the letters  (`main.cpp`)

**Idea:** Two words are anagrams if every letter appears the **same number of times** in both. So count the letters of each word and compare the counts.

Assuming only lowercase `a-z`, I use 26 boxes, one per letter. `'c' - 97` turns the letter into a box number (`a`=0, `b`=1, ...).

```
s = "rat"                  t = "tar"

box:  a b c ... r ... t ...
s:    1 0 0     1     1        <- counts for "rat"
t:    1 0 0     1     1        <- counts for "tar"

same counts everywhere -> true
```

Steps:

1. If the lengths differ, answer **false** right away. They cannot match.
2. One loop: add to `arr1` from `s` and to `arr2` from `t`.
3. Compare the 26 boxes. Any difference means **false**.

- **Time:** O(n). One pass over the words, plus 26 comparisons (a constant).
- **Memory:** O(1). Two arrays of 26 ints, no matter how long the words are.

---

## Other ways to think about it

| Approach             | Time       | Memory | Note                              |
|----------------------|------------|--------|-----------------------------------|
| Sort both, compare   | O(n log n) | O(1)   | Easy, slower                      |
| **Count array (mine)** | **O(n)** | **O(1)** | Fastest for lowercase letters  |
| Hash map of counts   | O(n)       | O(k)   | Needed for unicode or any char    |

**Small improvement:** one array is enough. Do `count[s[i]]++` and `count[t[i]]--`, then check that all boxes are 0.

**Watch out:** this only works for lowercase `a-z`. An uppercase letter or a space would index outside the array.

**Lesson to remember:** when the alphabet is small and fixed, an array is a hash map without the overhead.
