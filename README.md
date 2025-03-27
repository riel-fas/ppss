<p align="center"> 
<img src="https://img.shields.io/badge/42-Network-black?style=for-the-badge&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABAAAAAQCAYAAAAf8/9hAAAACXBIWXMAAAsTAAALEwEAmpwYAAABiElEQVQ4y2NgGFQggv//CSgoKCgqKioqKSkpKSkpffz48f///f8P0tjR0VHe3t5e29zcXNLc3FzS2NhY0tDQUNLQ0FDS1NRc0traurS1tXVpW1vb0tbW1qVtbW1L29vbl7a3ty9tb29f2tHRsbSjo2Npe3v70s7OzqWdnZ1LBwYGlw4ODi4dGhpaOjQ0tHRkZGTp6Ojo0rGxsaVjY2NLx8fHl46Pjy8dHx9fOjExsXRycnLpzMzM0llg8D8K//37R/Dv3z+Cv3//Evz//5/g+/cfBP/+/Sf4/v0nwe/fvwm+ff9F8OfPX4Kf\n P34T/Pz5i+Dnz98Ev3//Ifj9+y/Bn/2/gAr+ATX+hCr+AVWAqQAW+APU8Aeo4R9Qw19QDf+BGv4BNfwDavgH1PAPqOEfUMM/oIZ/QA3/gBr+ATX8A2r4B9TwD6jhH1DDH6CGf0AN/4Aa/gE1/ANq+AfU8A+o4R9Qwz+ghn9ADf+AGv4BNfwDavgH1PAPqOEfUMM/oIZ/QA3/gBoYAABhKkjR0SIEzwAAAABJRU5ErkJggg==" alt="42 Network"> 
<img src="https://img.shields.io/badge/1337-Coding-green?style=for-the-badge&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABAAAAAQCAYAAAAf8/9hAAAACXBIWXMAAAsTAAALEwEAmpwYAAABiElEQVQ4y2NgGFQggv//CSgoKCgqKioqKSkpKSkpffz48f///f8P0tjR0VHe3t5e29zcXNLc3FzS2NhY0tDQUNLQ0FDS1NRc0traurS1tXVpW1vb0tbW1qVtbW1L29vbl7a3ty9tb29f2tHRsbSjo2Npe3v70s7OzqWdnZ1LBwYGlw4ODi4dGhpaOjQ0tHRkZGTp6Ojo0rGxsaVjY2NLx8fHl46Pjy8dHx9fOjExsXRycnLpzMzM0llg8D8K//37R/Dv3z+Cv3//Evz//5/g+/cfBP/+/Sf4/v0nwe/fvwm+ff9F8OfPX4Kf\n P34T/Pz5i+Dnz98Ev3//Ifj9+y/Bn/2/gAr+ATX+hCr+AVWAqQAW+APU8Aeo4R9Qw19QDf+BGv4BNfwDavgH1PAPqOEfUMM/oIZ/QA3/gBr+ATX8A2r4B9TwD6jhH1DDH6CGf0AN/4Aa/gE1/ANq+AfU8A+o4R9Qwz+ghn9ADf+AGv4BNfwDavgH1PAPqOEfUMM/oIZ/QA3/gBoYAABhKkjR0SIEzwAAAABJRU5ErkJggg==" alt="1337 Coding"> 
</p> 
<h1 align="center">🚀 Push_Swap 🚀</h1> 


## Overview
Push Swap is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations with the goal of minimizing the number of moves.

## Project Structure
The project implements a sorting algorithm for two stacks (A and B) with the following key operations:
- `sa`, `sb`, `ss`: Swap the first two elements of a stack
- `pa`, `pb`: Push an element from one stack to another
- `ra`, `rb`, `rr`: Rotate a stack (move the top element to the bottom)
- `rra`, `rrb`, `rrr`: Reverse rotate a stack (move the bottom element to the top)

## Sorting Algorithm Details

### Core Algorithm Strategy
The implemented sorting algorithm uses a sophisticated cost-based approach that optimizes sorting through several key steps:

#### 1. Indexing and Median Calculation
The `current_index()` function assigns an index to each element and determines whether it's above or below the median. This is crucial for calculating push costs and optimizing moves.

```c
void current_index(t_stack *stack)
{
    int i = 0;
    int median = stack_length(stack) / 2;
    while (stack)
    {
        stack->index = i;
        stack->above_median = (i <= median);
        stack = stack->next;
        ++i;
    }
}
```

#### 2. Target Node Selection
Two key functions handle target node selection:
- `set_target_a()`: For stack A, finds the best matching node in stack B
- `set_target_b()`: For stack B, finds the best matching node in stack A

Example from `set_target_a()`:
```c
void set_target_a(t_stack *a, t_stack *b)
{
    while (a)
    {
        best_match_index = LONG_MIN;
        current_b = b;
        while (current_b)
        {
            // Find the largest B node smaller than the current A node
            if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
            {
                best_match_index = current_b->nbr;
                target_node = current_b;
            }
            current_b = current_b->next;
        }
        // If no smaller node found, target the max node in B
        a->target_node = (best_match_index == LONG_MIN) 
            ? find_max_nb(b) 
            : target_node;
        a = a->next;
    }
}
```

#### 3. Cost Calculation
The `cost_calc_a()` function calculates the "push cost" for moving elements, considering:
- The node's current index
- Whether the node is above or below the median
- The target node's position

```c
void cost_calc_a(t_stack *a, t_stack *b)
{
    int len_a = stack_length(a);
    int len_b = stack_length(b);
    while (a)
    {
        // Calculate push cost based on current stack configuration
        a->push_cost = a->index;
        if (!(a->above_median))
            a->push_cost = len_a - (a->index);
        
        // Add cost of moving target node
        if (a->target_node->above_median)
            a->push_cost += a->target_node->index;
        else
            a->push_cost += len_b - (a->target_node->index);
        
        a = a->next;
    }
}
```

#### 4. Cheapest Node Selection
The `set_cheapest()` function identifies the node with the lowest push cost:

```c
void set_cheapest(t_stack *stack)
{
    long cheapest_value = LONG_MAX;
    t_stack *cheapest_node;
    
    while (stack)
    {
        if (stack->push_cost < cheapest_value)
        {
            cheapest_value = stack->push_cost;
            cheapest_node = stack;
        }
        stack = stack->next;
    }
    cheapest_node->cheap = true;
}
```

### Sorting Process
The main sorting algorithm `sort_a_b()` follows these steps:
1. Move elements from stack A to stack B, keeping only 3 elements in A
2. Sort the remaining 3 elements in stack A
3. Move elements back from B to A, positioning them optimally
4. Rotate to ensure the smallest element is at the top

## Error Handling
The project includes robust error handling:
- Syntax checking for input numbers
- Duplicate number detection
- Overflow protection
- Comprehensive error messaging

## Complexity
- Time Complexity: O(n log n)
- Space Complexity: O(n)

## How to Use
```bash
# Compile the project
make

# Run with a list of integers
./push_swap 4 2 7 1 5
```

## Key Challenges Overcome
- Implementing an efficient sorting algorithm with limited operations
- Minimizing the total number of moves
- Handling various input scenarios
- Optimizing stack manipulations

## Lessons Learned
- Advanced data structure manipulation
- Algorithm optimization techniques
- Importance of modular code design
- Complex problem-solving strategies

## Author
- 42 School Student: riel-fas
