# Circular Queue Implementation in C

A simple and efficient implementation of a circular queue data structure using a static array in C.

## Overview

This project implements a circular queue (ring buffer) using a fixed-size array in C. 
The circular queue is a linear data structure that follows the First-In-First-Out (FIFO) principle 
and uses memory efficiently by reusing the empty spaces when elements are dequeued.

## Features

- Fixed capacity circular queue implementation (size of 5 elements)
- Basic operations:
  - Enqueue: Add an element to the queue
  - Dequeue: Remove an element from the queue
  - Check if queue is empty
  - Check if queue is full
  - Display queue elements and status
- Interactive command-line menu interface
- Overflow and underflow detection
- Status updates during operations

## Technical Implementation

The implementation includes:
- A queue structure with head and tail pointers
- Circular indexing to wrap around the array
- Proper empty and full state handling
- Detailed status reporting

## Usage

1. Compile the program:
   ```
   gcc circular_queue.c -o circular_queue
   ```

2. Run the executable:
   ```
   ./circular_queue
   ```

3. Use the interactive menu to perform operations:
   - Option 1: Enqueue (add) an element
   - Option 2: Dequeue (remove) an element
   - Option 3: Display the queue contents
   - Option 4: Exit the program

## Example Output

```
Queue Implementation Using array
____________________________________________

------------------------
|   Queue Operation    |
|----------------------|
| 1 | EnQueue          |
| 2 | DeQueue          |
| 3 | ShowQueue        |
| 4 | Quit program     |
------------------------

Enter option << 1

 Enter Number : 42
-----------enQueue():: element-> 42 added H:0  T:0-----------

------------------------
|   Queue Operation    |
|----------------------|
| 1 | EnQueue          |
| 2 | DeQueue          |
| 3 | ShowQueue        |
| 4 | Quit program     |
------------------------

Enter option << 3

.------------------------------------------
| Elements of Queue: 42 
|
| Head: 0    Tail: 0
|
| Elements : 1/5
'------------------------------------------
```

## Limitations

- Fixed size queue (5 elements)
- Only supports integer data type
- Command-line interface only

## Future Improvements

- Make queue size configurable
- Implement a generic version using void pointers
- Add additional queue operations (peek, clear, etc.)
- Improve error handling

## License

[MIT License](LICENSE)

## Contribution

Contributions, bug reports, and feature requests are welcome!
