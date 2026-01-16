#include <iostream>
using namespace std;

class MyArray {
public:
    int arr[100];    // Fixed size array (max 100 elements)
    int size=0 ;      // Current number of elements
    int capacity=100;    // Maximum capacity
    

    // 1. Insert at the end
    void insertAtEnd(int value) {
        if (size < capacity) {
            arr[size] = value;
            size++;
            cout << value << " inserted at the end.\n";
        } else {
            cout << "Array is full! Cannot insert.\n";
        }
    }

    // 2. Insert at beginning
    void insertAtBeginning(int value) {
        if (size < capacity) {
            // Shift all elements to the right
            for (int i = size; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = value;
            size++;
            cout << value << " inserted at the beginning.\n";
        } else {
            cout << "Array is full!\n";
        }
    }

    // 3. Insert at specific position (index)
    void insertAtPosition(int index, int value) {
        if (index < 0 || index > size) {
            cout << "Invalid index!\n";
            return;
        }
        if (size < capacity) {
            for (int i = size; i > index; i--) {
                arr[i] = arr[i - 1];
            }
            arr[index] = value;
            size++;
            cout << value << " inserted at index " << index << "\n";
        } else {
            cout << "Array is full!\n";
        }
    }

    // 4. Delete from end
    void deleteFromEnd() {
        if (size > 0) {
            cout << arr[size - 1] << " deleted from end.\n";
            size--;
        } else {
            cout << "Array is empty!\n";
        }
    }

    // 5. Delete from beginning
    void deleteFromBeginning() {
        if (size > 0) {
            cout << arr[0] << " deleted from beginning.\n";
            for (int i = 0; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
        } else {
            cout << "Array is empty!\n";
        }
    }

    // 6. Update value at index
    void update(int index, int newValue) {
        if (index >= 0 && index < size) {
            cout << "Updated index " << index << " from " << arr[index] << " to " << newValue << "\n";
            arr[index] = newValue;
        } else {
            cout << "Invalid index!\n";
        }
    }

    // 7. Search for a value
    int search(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                cout << value << " found at index " << i << "\n";
                return i;
            }
        }
        cout << value << " not found!\n";
        return -1;
    }

    // 8. Display the array
    void display() {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "Array (" << size << " elements): ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // 9. Get current size
    int getSize() {
        return size;
    }
};

// MAIN FUNCTION - Testing the class
int main() {
    MyArray arr;  // Creating object
    // Adding initial elements
    arr.insertAtEnd(10);
    arr.insertAtEnd(20);
    arr.insertAtEnd(30);
    arr.insertAtEnd(40);
    arr.insertAtEnd(50);
    arr.display();

    // Update
    arr.update(2, 999);
    arr.display();

    // Insert at beginning
    arr.insertAtBeginning(5);
    arr.display();

    // Insert at end again
    arr.insertAtEnd(60);
    arr.display();

    // Delete from end
    arr.deleteFromEnd();
    arr.display();

    // Delete from beginning
    arr.deleteFromBeginning();
    arr.display();

    // Search
    arr.search(40);
    arr.search(999);
    arr.search(100); // not found

    // Final state
    cout << "\nFinal Array:\n";
    arr.display();
    cout << "Current size: " << arr.getSize() << endl;

    return 0;
}
