#include <iostream>

struct Matrix;

void clean(Matrix &graph);

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
    void delete_matrix()
    {
        for (int i = 0; i < n; i++)
        {
            delete[] mat[i];
        }
        delete[] mat;
    }
};
void clean(Matrix &graph)
{
    for (int j = 0; j < graph.m; j++)
    {
        int i1 = -1;
        for (int i = 0; i < graph.n; i++)
        {
            if (graph.mat[i][j] != 0 && i1 == -1)
            {
                i1 = i;
            }
            else if (graph.mat[i][j] != 0 && i1 != -1)
            {
                i1 = -1;
                break;
            }
        }
        if (i1 != -1)
            graph.mat[i1][j] = 0;
    }
}
int internet(Matrix graph)
{
    clean(graph); // очистка от самосапряжений

    int l = 0; //длина
    while (true)
    {
        int min = INT16_MAX;
        int j1 = 0;
        int i1 = 0;
        bool flag = true;
        for (int j = 0; j < graph.m; j++)
        {
            // std::cout << j << " " << graph.mat[0][j] << '\n';
            if (graph.mat[0][j] != 0 && graph.mat[0][j] < min)
            {
                j1 = j;
                min = graph.mat[0][j];
                flag = false;
            }
        }
        if (flag)
            break; // это значит что все готовы
        l += min;
        for (int i = 1; i < graph.n; i++)
        {
            if (graph.mat[i][j1] != 0)
            {
                for (int j = 0; j < graph.m; j++)
                {
                    if (graph.mat[i][j] == graph.mat[0][j])
                    {
                        graph.mat[0][j] = 0;
                    }
                    else
                    {
                        if (graph.mat[i][j] != 0)
                            graph.mat[0][j] = graph.mat[i][j];
                    }
                    graph.mat[i][j] = 0;
                }
                break;
            }
        }
    }
    return l * 98;
}
int main()
{
    int m = 0, n = 0;
    std::cin >> n >> m;
    Matrix graph(m, n);
    graph.input();
    //graph.print();
    std::cout << internet(graph);
    graph.delete_matrix();
    return 0;
}