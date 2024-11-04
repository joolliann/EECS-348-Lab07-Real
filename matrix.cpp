#include <iostream> 
#include <fstream>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
  Matrix(){
    for (int i = 0; i < SIZE; ++i){
      for (int j = 0; j < SIZE; ++j){
        data[i][j] = 0;
      }
    }
  }
  
  // Read values from a file into a matrix
  void readFromStdin(const string fileName){
    ifstream file(fileName);
    if (file.is_open()) { // Check if the file opened successfully
      for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
          file >> data[i][j];
        }
      }
      file.close();
    } else {
      cout << "Error: Unable to open file " << fileName << endl; // Error message if file fails to open
    }
  }

  // Display a matrix
  void display() const {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << data[i][j] << " ";
        }
        cout << endl; 
    }
  }

  // Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) const {
    Matrix new_matrix;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            new_matrix.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return new_matrix;
  }

  // Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) const {
    Matrix new_matrix;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
              new_matrix.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return new_matrix;
  }

  // Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const {
    int to_add = 0;
    for (int i = 0; i < SIZE; ++i) {
      to_add += data[i][i];
      if (i != SIZE - i - 1) {
        to_add += data[i][SIZE - i - 1];
      }
    }
    return to_add;
  }

  // Swap matrix rows
  void swapRows(int row1, int row2) {
    for (int col = 0; col < SIZE; ++col) {
        std::swap(data[row1][col], data[row2][col]);
    }
  }
};

int main() {
  // Example usage:
  Matrix mat1;
  cout << "Enter values for Matrix 1 from matrix1.txt:" << endl;
  mat1.readFromStdin("matrix1.txt"); // Use filename directly
  cout << "Matrix 1:" << endl;
  mat1.display();

  Matrix mat2;
  cout << "Enter values for Matrix 2 from matrix2.txt:" << endl;
  mat2.readFromStdin("matrix2.txt"); // Use filename directly
  cout << "Matrix 2:" << endl;
  mat2.display();

  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();

  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();

  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows:" << endl;
  mat1.display();

  return 0;
}
