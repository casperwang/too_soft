# Misc

## Theorems
### Description
Theorems.
### Test Status
No test.

## Weight Matroid Intersection
### Description
Almost an implementation.
### Test Status
Copied from NaCl

## Stable Marriage
### Description
Stable Marriage algo.
### Test Status
No test needed.

## Bitset LCS
### Description
$O(n^2/w)$. need hand-written bitset (needs subtraction)  
The result bitset $f$ contains the answer.
If the $i$-th position is true, the $i$-th number of the first sequence is in the answer. (Need test for this claim) 

### Test Status
Passed [LibreOJ #6564](https://loj.ac/s/1914563)

## Prefix Substring LCS
### Description
Calculate the LCS of a prefix of $S$ and a substring of $T$ in $O((|S||T| + Q)\log |T|)$
### Test Status
Passed [yosupo library checker](https://judge.yosupo.jp/submission/163705). Copied from 8BQube.

## Convex 1D/1D DP
### Description
1D/1D optimization.
### Test Status
TODO. Rarely used.

## ConvexHull Optimization
### Description
Maintain upper envelope of lines.
### Test Status
Passed yosupo library checker.

## De-Bruijn
### Description
De-Bruijn sequence construction
### Test Status
Passed CSES, [regional prob](https://codeforces.com/gym/102001/problem/C) and local test.

## Josephus Problem
### Description
Josephus problem $O(N)$ and faster algo ($O(M\log N)$).
### Test Status
Not even used or tested

## N Queens Problem
### Description
N Queens Problem construction
### Test Status
Not even used or tested.

## Manhattan MST
### Description
Minimum Spanning Tree of manhattan distance.
### Test Status
Passed [yosupo library checker](https://judge.yosupo.jp/submission/69901).

## Tree Knapsack
### Description
TODO
don't know its usage
### Test Status
Not even used or tested.

## Binary Search On Fraction
### Description
Binary search on stern-borcot tree, binary search
over $p/q$ such that $0 <= p, q <= N$.
### Test Status
TODO. Copied from NaCl.

## Barret Reduction
### Description
Fast modulo operation of non-constexpr constant.
### Test Status
Copied from kactl. Guess it's ok to have no test.
