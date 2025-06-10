#include <ostream> // std::ostream
#include <iostream>
#include <vector>
#include <type_traits>
#include <stdexcept>
using namespace std;


template <typename T>
class Matrix
{
private:
    std::vector<std::vector<T>> data;
    size_t rows, cols;

public:
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), data(rows, std::vector<T>(cols)) {}
    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    T &at(size_t i, size_t j) //当对象是非 const 时调用，允许修改返回的元素值
    {
        return data[i][j];
    }

    const T &at(size_t i, size_t j) const //只读
    {
        return data[i][j];
    }

    Matrix<T> operator+(const Matrix<T> &other) const
    {
        if (this->rows != other.rows || this->cols != other.cols)
        {
            throw std::invalid_argument("Matrix dimensions mismatch");
        }

        Matrix<T> result(this->rows, this->cols);

        for (size_t i = 0; i < this->rows; i++)
        {
            for (size_t j = 0; j < this->cols; j++)
            {
                result.at(i, j) = this->at(i, j) + other.at(i, j);
            }
        }
        return result;
    }

    Matrix<T> operator*(const Matrix<T> &other) const
    {
        if (this->cols != other.rows)
        {
            throw std::invalid_argument("Matrix dimensions mismatch");
        }

        Matrix<T> result(this->rows, other.cols);

        for (size_t i = 0; i < this->rows; i++)
        {
            for (size_t j = 0; j < other.cols; j++)
            {
                result.at(i, j) = 0;
                for (size_t k = 0; k < this->cols; k++)
                {
                    result.at(i, j) += this->at(i, k) * other.at(k, j);
                }
            }
        }
        return result;
    }

    void print() const
    {
        for (size_t i = 0; i < this->rows; i++)
        {
            for (size_t j = 0; j < this->cols; j++)
            {
                cout << at(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix<int> mat1(2, 2);
    mat1.at(0, 0) = 1;
    mat1.at(0, 1) = 2;
    mat1.at(1, 0) = 3;
    mat1.at(1, 1) = 4;

    Matrix<int> mat2(2, 2);
    mat2.at(0, 0) = 5;
    mat2.at(0, 1) = 6;
    mat2.at(1, 0) = 7;
    mat2.at(1, 1) = 8;

     std::cout << "Matrix 1:\n";
    mat1.print();

    std::cout << "\nMatrix 2:\n";
    mat2.print();

    Matrix<int> matSum = mat1 + mat2;

    std::cout << "\nMatrix sum:\n";
    matSum.print();

    Matrix<int> matMul = mat1 * mat2;

    std::cout << "\nMatrix product:\n";
    matMul.print();

    return 0;
}
