#include <iostream>
struct Matrix
{
    int n = 0; // количество строк
    int m = 0; // количество столбцов
    int **mat = nullptr;
    Matrix(int n_1, int m_1)
    {
        n = n_1;
        m = m_1;
        int **mat_1 = new int *[n];
        mat = mat_1;
        for (int i = 0; i < n; i++)
        {
            mat[i] = new int[m];
            for (int j = 0; j < m; j++)
                mat[i][j] = 0;
        }
    }
    void input()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                std::cin >> mat[i][j];
            }
    }
    void print()
    {
        std::cout << '\n'
                  << "Matrix:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cout << mat[i][j] << " ";
            }
            std::cout << '\n';
        }
    }
    int number_rib()
    {
        int s = 0;
        for (int i = 0; i < n; i++)
            for (int j = i; j < m; j++)
            {
                if (mat[i][j] != 0)
                    s++;
            }
        return s;
    }
};
void convert(Matrix old, Matrix extra){
    int s = 0;
    for (int i = 0; i < old.n; i++)
        for (int j = i; j < old.m; j++){
            if (old.mat[i][j] != 0){
                extra.mat[i][s] = old.mat[i][j];
                extra.mat[j][s] = old.mat[i][j];
                s++;
                extra.print();
            }
        }

}
int main()
{
    int m = 0;
    std::cin >> m;
    Matrix old(m, m);
    old.input();
    //old.print();
    int n = old.number_rib();
    Matrix extra(m, n);
    convert(old,extra);
    extra.print();
    return 0;
}