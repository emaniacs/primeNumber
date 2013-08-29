prime
=====

About prime number.
Generate, check and find.

Example
-------
```
$ prime 45          # show return true or false
false
$ prime 45 -q       # quietly mode
$ echo $?           # view last return value
1
$ prime -g 5        # generate 5 prime number
2
3
5
7
11
$ prime -n 5        # show prime 5th
11
$ prime -g 5 -s '-' # generate 5 prime number with '-' as separator
2-3-5-7-11
$ 
