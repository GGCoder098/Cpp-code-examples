#include <iostream>
#include <random>
using namespace std;

class Matrix {
public:
    Matrix(const int r, const int c) {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(0, 100);
        this->rows = r;
        this->cols = c;
        mtrx = new int *[r];
        for (int i = 0; i < r; i++) {
            mtrx[i] = new int[c];
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                mtrx[i][j] = static_cast<int>(dis(gen));
            }
        }
    }

    Matrix(int **a, const int r, const int c) {
        this->rows = r;
        this->cols = c;
        mtrx = new int *[r];
        for (int i = 0; i < r; i++) {
            mtrx[i] = new int[c];
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                mtrx[i][j] = a[i][j];
            }
        }
    }

    Matrix(const int num, const int r, const int c) {
        this->rows = r;
        this->cols = c;
        mtrx = new int *[r];
        for (int i = 0; i < r; i++) {
            mtrx[i] = new int[c];
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                mtrx[i][j] = num;
            }
        }
    }

    ~Matrix() {
        if (mtrx) {
            for (int i = 0; i < rows; i++) {
                delete[] mtrx[i];
            }
            delete[] mtrx;
        }
    }

    int rows;
    int cols;
    int **mtrx;

    void print() const {
        cout << "Matrix: " << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mtrx[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix transpose() const {
        Matrix result(cols, rows);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mtrx[j][i] = mtrx[i][j];
            }
        }
        // result.print();
        return result;
    }

    Matrix sum(const Matrix &a, const Matrix &b) const {
        if (a.rows != b.rows || a.cols != b.cols) {
            throw invalid_argument("Matrix dimensions do not match");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mtrx[i][j] = a.mtrx[i][j] + b.mtrx[i][j];
            }
        }
        return result;
    }

    Matrix difference(const Matrix &a, const Matrix &b) const {
        if (a.rows != b.rows || a.cols != b.cols) {
            throw invalid_argument("Matrix dimensions do not match");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mtrx[i][j] = a.mtrx[i][j] - b.mtrx[i][j];
            }
        }
        return result;
    }

    Matrix tovector() const {
        Matrix v(0, 1, this->rows * this->cols);
        int counter = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                v.mtrx[0][counter] = this->mtrx[i][j];
                counter++;
            }
        }
        return v;
    }

    int sumofall() {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                sum += this->mtrx[i][j];
            }
        }
        return sum;
    }

    Matrix findcommon(Matrix &a, Matrix &b) {
        if (a.rows != b.rows || a.cols != b.cols) {
            throw invalid_argument("Matrix dimensions do not match");
        }
        Matrix c(0, this->rows, this->cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (a.mtrx[i][j] == b.mtrx[i][j]) {
                    c.mtrx[i][j] = 1;
                } else {
                    c.mtrx[i][j] = 0;
                }
            }
        }
        return c;
    }

    Matrix multiply(const Matrix &b) {
        if (this->cols != b.rows) {
            throw invalid_argument("Matrix dimensions do not match");
        }
        Matrix result(0, this->rows, b.cols);
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < b.cols; j++) {
                for (int k = 0; k < this->cols; k++) {
                    result.mtrx[i][j] += this->mtrx[i][k] * b.mtrx[k][j];
                }
            }
        }
        return result;
    }
};


int main() {
    // int x = 5;
    // int c = 5;
    Matrix test1(2, 3);
    Matrix test2(3, 2);
    test1.mtrx[0][0] = 3;
    test1.mtrx[0][1] = 1;
    test1.mtrx[0][2] = 5;

    test1.mtrx[1][0] = 6;
    test1.mtrx[1][1] = 9;
    test1.mtrx[1][2] = 7;


    test2.mtrx[0][0] = 3;
    test2.mtrx[0][1] = 4;

    test2.mtrx[1][0] = 7;
    test2.mtrx[1][1] = 2;

    test2.mtrx[2][0] = 5;
    test2.mtrx[2][1] = 9;
    test1.print();
    test2.print();

    try {
        // Matrix result( x, c);
        // result.print();
        // Matrix new_m = result.transpose();
        // new_m.print();
        // Matrix sum_m = new_m.sum(result, new_m);
        // sum_m.print();
        // Matrix diff_m = new_m.difference(result, new_m);
        // diff_m.print();
        // Matrix vector = result.tovector();
        // vector.print();
        // cout << vector.sumofall() << endl;
        // Matrix common = result.findcommon(result, new_m);
        // common.print();
        Matrix final = test2.multiply(test1);
        final.print();
    } catch (exception &e) {
        cout << "Exception thrown: " << e.what() << endl;
    }
}
