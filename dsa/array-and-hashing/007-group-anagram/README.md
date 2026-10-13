# 007 - Group Anagrams

**Problem:** Given a list of words, group together the words that are anagrams of each other (same letters, different order).

```
input:  ["eat", "tea", "tan", "ate", "nat", "bat"]

output: [ ["eat", "tea", "ate"],
          ["tan", "nat"],
          ["bat"] ]
```

The big idea: give every word a **signature** (a key) that is the same for all its anagrams. Then put words with the same key in the same bucket, using a hash map.

```
"eat" --> key K1 --+
"tea" --> key K1 --+--> bucket K1: [eat, tea, ate]
"ate" --> key K1 --+
"tan" --> key K2 --+--> bucket K2: [tan, nat]
"nat" --> key K2 --+
"bat" --> key K3 -----> bucket K3: [bat]
```

The whole problem is: **how do I build a good key?** Below are the three ideas I went through (n = number of words, m = length of the longest word).

---

## Attempt 1: add up the ASCII values (commented out, **wrong**)

**Idea:** Anagrams have the same letters, so the sum of the letters should match.

```
"eat" = 101 + 97 + 116 = 314
"tea" = 116 + 101 + 97 = 314   same, good
```

**Why it fails:** different letters can give the same sum.

```
"ad" = 97 + 100 = 197
"bc" = 98 +  99 = 197   same sum, but NOT anagrams
```

A sum throws away too much information. I dropped this idea.

---

## Attempt 2: sort the letters (commented out)

**Idea:** If I sort the letters of a word, all anagrams become the same word.

```
"eat" -> "aet"
"tea" -> "aet"
"ate" -> "aet"     key = "aet"
"tan" -> "ant"
"nat" -> "ant"     key = "ant"
```

Sorted word = key. Put the original word in `um[key]`.

- **Time:** O(n · m log m). Each of the n words is sorted at a cost of m log m.
- **Memory:** O(n · m). The map stores all the words plus the keys.
- Simple and easy to trust. This is what I would write first in an interview.

---

## Attempt 3: count the letters (final solution)

**Idea:** Sorting is more work than I need. All I need to know is *how many of each letter* a word has, and counting does that in one pass.

```
"eat":  a=1  e=1  t=1   everything else 0

count array of 26 boxes:
 a b c d e f ... s t u ... z
 1 0 0 0 1 0     0 1 0     0
```

Turn the 26 counts into a string and use it as the key. The `#` separator is important:

```
counts 1,0,0,0,1,...  ->  "1#0#0#0#1#0#...#"
```

Without `#`, the counts `1,11` and `11,1` would both become `"111"` and clash. The separator keeps them different.

```
"eat" -> "1#0#0#0#1#...#1#..."  --+
"tea" -> "1#0#0#0#1#...#1#..."  --+--> same bucket
"ate" -> "1#0#0#0#1#...#1#..."  --+
```

Finally, loop over the map and collect the buckets. `std::move` hands each bucket over to the answer without copying all the strings.

- **Time:** O(n · m). For each word: m steps to count, plus 26 steps to build the key (a constant). No log factor.
- **Memory:** O(n · m). The map holds all words, and each key has a fixed size (about 26 numbers).

---

## Comparison

| Approach              | Key                  | Time           | Memory   | Note                               |
|-----------------------|----------------------|----------------|----------|------------------------------------|
| ASCII sum             | one number           | O(n · m)       | O(n · m) | **Wrong**, different words collide |
| Sort letters          | sorted word          | O(n · m log m) | O(n · m) | Simple, correct                    |
| **Count letters**     | 26 counts as string  | **O(n · m)**   | O(n · m) | Fastest when words are long        |

**Which one to pick?** For short words, sorting and counting are about the same speed, and sorting is simpler. Counting wins when words are long, because it avoids the `log m`.

**Watch out:**
- Only lowercase `a-z` works. An uppercase letter or digit would index outside the 26 boxes. (For other characters, use sorting, or a bigger count array.)
- The order of the groups in the output is not fixed, because `unordered_map` has no order.
- In `main`, the loops `for (auto p : g)` copy each group. `const auto &` would avoid that.

**Lesson to remember:** "Group things that are the same in some way" means *find a key that is identical for them*, then use a hash map. The only question is how to build the key, and a bad key (like the ASCII sum) breaks the solution.
