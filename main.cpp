#include <iostream>
using namespace std;

// Node structure for sparse matrix
struct Node {
    int row, col, value;
    Node* next;
    Node(int r, int c, int v) : row(r), col(c), value(v), next(nullptr) {}
};

class SparseMatrix {
private:
    int rows, cols;
    Node* head;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c), head(nullptr) {}

    // Add a new non-zero element
    void addElement(int r, int c, int v) {
        if (v == 0) return; // ignore zero values
        Node* newNode = new Node(r, c, v);

        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    // Display in triplet form
    void displayTriplet() {
        cout << "Row Col Value" << endl;
        Node* temp = head;
        while (temp) {
            cout << temp->row << "   " << temp->col << "   " << temp->value << endl;
            temp = temp->next;
        }
    }

    // Display full matrix
    void displayMatrix() {
        Node* temp = head;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (temp && temp->row == i && temp->col == j) {
                    cout << temp->value << " ";
                    temp = temp->next;
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    SparseMatrix sm(5, 4);  // Changed to 5 rows and 4 columns

    // New non-zero elements at different positions with new values
    sm.addElement(0, 0, 7);
    sm.addElement(1, 2, -5);
    sm.addElement(2, 3, 12);
    sm.addElement(4, 1, 9);

    cout << "Sparse Matrix in Triplet Form:" << endl;
    sm.displayTriplet();

    cout << "\nFull Matrix Representation:" << endl;
    sm.displayMatrix();

    return 0;
}
