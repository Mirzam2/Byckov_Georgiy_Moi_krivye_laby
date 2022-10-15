#include <iostream>
template <typename Field, size_t M, size_t N>
class Matrix
{
public:
    Matrix()
    {
        matrix = new Field *[N];
        for (int i = 0; i < N; i++)
        {
            matrix[i] = new Field[M];
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    Matrix(Field *mas)
    {
        matrix = new Field *[N];
        for (int i = 0; i < N; ++i)
        {
            matrix[i] = new Field[M];
        }

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                matrix[i][j] = mas[M * i + j];
            }
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < N; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void print_matrix() const
    {
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << '\n';
        }
    }

    Matrix<Field, M, N> operator+=(const Matrix<Field, M, N> &rha)
    {
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                matrix[i][j] += rha.matrix[i][j];
                //std::cout << matrix[i][j] << " " << rha.matrix[i][j] << '\n';
            }
        }
        return *this;
    }
    Matrix<Field, M, N> operator+(const Matrix<Field, M, N> &rha) const
    {
        Matrix<Field, M, N> result;
        result = *this;
        std::cout << "\ntest1\t result\n";
        result.print_matrix();
        result += rha;
        std::cout << "\nrha\n";
        rha.print_matrix();
        std::cout << "\ntest2\t result\n";
        result.print_matrix();
        return result;
    }
    Matrix<Field, M, N> operator-=(const Matrix<Field, M, N> &rha)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                matrix[i][j] -= rha.matrix[i][j];
            }
        }
        return *this;
    }
    Matrix<Field, M, N> operator-(const Matrix<Field, M, N> &rha) const
    {
        Matrix<Field, M, N> result;
        result = *this;
        result -= rha;
        return result;
    }
    void operator=(const Matrix<Field, M, N> &rha)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                matrix[i][j] = rha.matrix[i][j];
            }
        }
    }

private:
    Field **matrix;
};

template <typename Field, int M, int N, int K>
Matrix<Field, M, K> operator*(const Matrix<Field, N, M> &lha, const Matrix<Field, K, N> &rha)
{
    Matrix<Field, M, K> res;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            Field sum = 0;
            for (int k = 0; k < N; k++)
            {
                sum += lha.matrix[i][k] * rha.matrix[k][j];
            }
            res.matrix[i][j] = sum;
        }
    }
    return res;
}

int main()
{
    int *arr = new int[12];
    for (int i = 0; i < 12; i++)
    {
        arr[i] = -i;
    }
    Matrix<int, 4, 3> matr(arr);
    Matrix<int, 4, 3> matr2(arr);
    Matrix<int, 3, 4> matr3(arr);
    std::cout << "matr = matr2" << '\n';
    matr2.print_matrix();
    std::cout << '\n'
              << "matr3" << '\n';
    matr3.print_matrix();
    std::cout << '\n'
              << "matr + matr2" << '\n';
    (matr + matr2).print_matrix();
    std::cout << '\n'
              << "matr - matr2" << '\n';
    (matr - matr2).print_matrix();
    std::cout << '\n'
              << "matr * matr3" << '\n';
    delete[] arr;
    return 0;
}