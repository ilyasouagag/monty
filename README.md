# C - Stacks, Queues - LIFO, FIFO
## Introduction
In computer science, **queues** and **stacks** are abstract data structures used to store and manage collections of items. They follow different principles of insertion and removal, making them suitable for various applications.

## Stack - LIFO
A **stack** is a Last-In-First-Out (LIFO) data structure, meaning the most recently added element is the first one to be removed.
**In the world of stacks, fear is just a lie;**

--> **Where the last in is always the first out.** 🤐

![](https://media2.giphy.com/media/6kyrz1j5uhJdK/giphy.gif?cid=ecf05e47yom7q74ipeaplcgbgkkyd1tyhqp8hgouu52fb5k1&ep=v1_gifs_search&rid=giphy.gif&ct=g)

### Queue
A **queue** is a First-In-First-Out (FIFO) data structure, where the first element added is the first one to be removed.
**In the world of *Queues* :**

--> **Every entity must patiently await its turn, defining a line that's justly right.**

![](https://media2.giphy.com/media/3o6ZsWEv7nktgfNx7y/giphy.gif?cid=ecf05e47kvqy30l7jez7wm0gudhpjv3uqx3mpyevtg2xdrit&ep=v1_gifs_related&rid=giphy.gif&ct=g)
## Basic Methods
Both stacks and queues typically support the following basic methods:
### Push
The `push` operation adds an element to the top of the stack.
### Pop
The `pop` operation removes the top element from the stack.
## Functions Explanation
Below are the functions implemented in this repository to work with stacks and queues:
### Stack Operations

- **`push(stack, line_number)`:** Adds an element to the top of the stack.
  
- **`pop(stack, line_number)`:** Removes the top element from the stack.

- **`swap(stack, line_number)`:** Swaps the top two elements of the stack.

- **`add(stack, line_number)`:** Adds the top two elements of the stack.

- **`sub(stack, line_number)`:** Subtracts the top element from the second top element of the stack.

- **`mul(stack, line_number)`:** Multiplies the top two elements of the stack.

- **`div(stack, line_number)`:** Divides the second top element by the top element of the stack.

- **`mod(stack, line_number)`:** Computes the modulus of the second top element divided by the top element of the stack.

- **`pall(stack, line_number)`:** Prints all elements in the stack.

## Usage
To use the provided functions, follow these steps:
1. Compile all the c file in this directory
```
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
2. Then make a file containing **Monty** code (Usually ends with `.mo`) , for example 'bytecodes.mo`:
```bash
push 1337
push 111
pall 
push 4
pall
```
3. Then run this command and enjoy the show ;)
```bash
./monty bytecodes.mo 
````
