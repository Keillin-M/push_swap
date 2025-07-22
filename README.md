# ♻️ push_swap

A sorting algorithm visualizer (without the visuals) — built in pure C, with strict constraints and zero standard sorting functions.

Welcome to **push_swap** — a project where you write two programs: one that **generates** the steps to sort a stack of integers using a limited set of operations, and another that **executes** those instructions. It’s all about efficiency, brainpower, and… well, a bit of suffering.

---

## 🚀 Project Overview

**push_swap** is part of the 42 school curriculum. The challenge: sort a stack of integers using only a limited set of operations — as few moves as possible.
You’ll implement your own sorting algorithm tailored to these constraints and handle edge cases like duplicates, already sorted input, and more.

🌀 Stack A → Stack B → Sorted
💡 Optimize move count
🛑 Only use allowed operations

---

## 🔧 Allowed Stack Operations

| Operation | Description                      |
| --------: | -------------------------------- |
|      `sa` | Swap top 2 elements of Stack A   |
|      `sb` | Swap top 2 elements of Stack B   |
|      `ss` | `sa` and `sb` at the same time   |
|      `pa` | Push top of Stack B to Stack A   |
|      `pb` | Push top of Stack A to Stack B   |
|      `ra` | Rotate Stack A upwards           |
|      `rb` | Rotate Stack B upwards           |
|      `rr` | `ra` and `rb` at the same time   |
|     `rra` | Reverse rotate Stack A           |
|     `rrb` | Reverse rotate Stack B           |
|     `rrr` | `rra` and `rrb` at the same time |

---

## 🧠 Key Concepts Covered

* Implementing custom sorting algorithms
* Data structures: linked lists and stacks
* Optimizing algorithm performance (big O)
* Handling input parsing and edge cases
* Writing clean, modular C code under constraints
* Developing a checker program to validate results

---

## 🛠️ Technologies

* **Language:** C (ISO C90 standard)
* **OS:** Linux
* **No external libraries** — all written from scratch
* **Bonus:** Visualizer (if implemented)

---

## 📦 How to Use

Clone the repo:

```bash
git clone https://github.com/your-username/push_swap.git
cd push_swap
```

Compile:

```bash
make
```

Run `push_swap` with input:

```bash
./push_swap 2 1 3 6 5 8
```

This will output a list of operations to sort the stack.

To verify with your checker:

```bash
ARG="2 1 3 6 5 8"
./push_swap $ARG | ./checker $ARG
```

---

## 🧪 Bonus Features

* 🧠 Optimized chunk sort for large datasets
* 🧮 Cost-based operation selection
* 📊 Move counter
* 🧵 Pivot sorting strategy

---

## 💡 Lessons Learned

* Sorting without `qsort` or `sort()` makes you think deeply about algorithm logic.
* Linked lists can be annoying... and powerful.
* You can optimize move count more than you think.
* Error handling and memory management is a full-time job.
* Everything breaks if you forget to free just one node.

---

## 🧪 Example

```bash
Input: 3 2 1

Output:
pb
pb
sa
pa
pa
```

---

## 📝 What I applied

In this project I decided to implement a few different algorithms that I learned.
- To index my linked list, I used an array and applied **Quick Sort**, very nice algorithm, a little more complicated to write than Selection Sort (or Bubble Sort) and uses recursive.
- I hard coded a sorting function for small number of elements (< 6 elements).
- I implemented **Radix**, using binary - very short and good sorting algorithm for 100 elements (if my next sorting algorithm didn't work, I would go with this).
- Finally, I tried to implement **Chunk Sort**, a very interesting way of sorting and a little more efficient for large set of elements and it also fit well with the operation restrictions of this project. Didn't have time to work too much in the greedy optimization, but it got really close to the max 5500 operations for 500 numbers.
