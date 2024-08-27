The pattern to go through is (for example for a n = 4)
1 2 3 4
2 2 3 4
3 3 3 4
4 4 4 4

In order to achieve this pattern, your permutation will always be 1 2 3 4, you will change a row then a column, from bottom to down.
0 0 0 0
0 0 0 0
0 0 0 0
1 2 3 4

0 0 0 1
0 0 0 2
0 0 0 3
1 2 3 4

0 0 0 1
0 0 0 2
1 2 3 4
1 2 3 4

and so on...
Your given matrix will be translated to the assumed pattern.
