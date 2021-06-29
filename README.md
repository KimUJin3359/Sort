# my_stacksort

## Sort with limited storage and command

### To Run
```
git clone https://github.com/KimUJin3359/my_stacksort.git
cd my_stacksort
make
// ./push_swap 'want or order list' likes below
./push_swap 5 4 3 2 1
```

### Project
- goal
  - think about a concept of complexity
  - get a knowledge about sorting algorithms

```
Only two stacks are given.
This stacks can't get an duplicated numbers, out range of int, and no integers
Must make an ascending order numbers into stack A

COMMAND
sa : swap the first 2 elements at the top of stack a
sb : swap the first 2 elements at the top of stack b
ss : sa and sb at the same time
pa : stack a takes the top of b to first element
pb : stack b takes the top of a to first element
ra : shift up all elements in stack a by 1
rb : shift up all elements in stack b by 1
rr : ra and rb at the same time
rra : shift down all elements in stack a by 1
rrb : shift down all elements in stack b by 1
rrr : rra and rrb at the same time
```

### Using Function
- write
- read
- malloc
- free
- exit

### Using Concepts
- `Linked List`
  - Arrays are so limited to deal element
    - can't push element in the middle of array
    - can't delete element in the middle of array.. etc
- `Quick Sort`
  - best case to this algorithm is n\*logn when the best pivot is selected
  - worst case to this algorithm is n^2 when the worst pivot is selected
  - but this algorithm is good at save storage
  - when lots of data exist, it's good at using this sort  
- `Merge Sort`
  - always this algorithm behavior in n\*logn
  - but this needs a lot of additional storage
