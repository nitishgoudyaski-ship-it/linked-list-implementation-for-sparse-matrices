# Sparse Matrix in C++ (Linked List Implementation)

This project demonstrates a linked list–based implementation of a Sparse Matrix.  
Each non-zero element is stored as a node with `(row, col, value)`.

## Example
Matrix (4x5) with non-zero elements:
- (0,1) = 10
- (1,3) = 20
- (2,2) = 30
- (3,0) = 40

### Triplet Form
Row Col Value  
0   1   10  
1   3   20  
2   2   30  
3   0   40  

### Full Matrix
0 10 0 0 0
0 0 0 20 0
0 0 30 0 0
40 0 0 0 0
