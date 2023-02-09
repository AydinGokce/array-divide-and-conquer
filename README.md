## Array Divide and Conquer in C

### Hi Rishi!
I made a quick demo for you. Simply execute the following commands.
```
git clone https://github.com/AydinGokce/array-divide-and-conquer.git
cd array-divide-and-conquer
make
./test_driver --demo
```

If you know how many CPU cores you have, you can achieve maximum speedup by replacing the last command with `./test_driver --demo <num_cores>`

example output:
```
generating array of length 1000000000...
TYPE    SUM     TIME (ms)
single  999966477       1726
multi   999966477       187
multithreading sped up summation by 1539ms! (9.229947x)
----------
Testing summation accuracy and edge cases
error (452027, 452027): 0
error (0, 0): 0
error (44, 44): 0
error (26, 26): 0
error (10, 10): 0
All tests passed
```

I hope you like it!