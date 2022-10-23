#include <iostream>
template <typename Field, size_t N, size_t M>
class Matrix
{
public:
    Matrix()
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
    Matrix(const Matrix<Field, N, M> &rha)
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
                matrix[i][j] = rha.matrix[i][j];
            }
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < N; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void print_matrix() const
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << '\n';
        }
    }

    Matrix<Field, N, M> operator+=(const Matrix<Field, N, M> &rha)
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                matrix[i][j] += rha.matrix[i][j];
                // std::cout << matrix[i][j] << " " << rha.matrix[i][j] << '\n';
            }
        }
        return *this;
    }
    Matrix<Field, N, M> operator+(const Matrix<Field, N, M> &rha) const
    {
        Matrix<Field, N, M> result(*this);
        return result;
    }
    Matrix<Field, N, M> operator-=(const Matrix<Field, N, M> &rha)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                matrix[i][j] -= rha.matrix[i][j];
            }
        }
        return *this;
    }
    Matrix<Field, N, M> operator-(const Matrix<Field, N, M> &rha) const
    {
        Matrix<Field, N, M> result;
        result = *this;
        result -= rha;
        return result;
    }
    void operator=(const Matrix<Field, N, M> &rha)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                matrix[i][j] = rha.matrix[i][j];
            }
        }
    }

private:
    Field **matrix;
};

template <typename Field, int N, int M, int K>
Matrix<Field, N, K> operator*(const Matrix<Field, N, M> &lha, const Matrix<Field, M, K> &rha)
{
    Matrix<Field, N, K> res;

    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < K; ++j)
        {
            Field sum = 0;
            for (size_t k = 0; k < M; ++k)
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
    for (int i = 0; i < 12; ++i)
    {
        arr[i] = -i;
    }
    Matrix<int, 4, 3> matr(arr);
    Matrix<int, 4, 3> matr2 = matr;
    Matrix<int, 3, 4> matr3(arr);
    matr.print_matrix();
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

    //auto result = matr * matr;
    delete[] arr;
    return 0;
}