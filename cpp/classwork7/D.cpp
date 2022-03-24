#include <iostream>
#include <cmath>
struct Street
{
    float x1 = 0, y1 = 0, x2 = 0, y2 = 0, k = 0;
    Street()
    {
        x1 = 0;
        x2 = 0;
        y1 = 0;
        y2 = 0;
        k = 0;
    }
    Street(float x_1, float y_1, float x_2, float y_2)
    {
        x1 = x_1;
        y1 = y_1;
        x2 = x_2;
        y2 = y_2;
        // std::cout << " x2 = " << x2 << " x_2 = " << x_2;
        if (y1 == y2)
        {
            k = (x2 - x1) / 0.001;
        }
        else
        {
            // std::cout << " x2 = " << x2 << " x1 = " << x1;
            k = (x2 - x1) / (y2 - y1);
        }
        // std::cout << " k = " << k << '\n';
    }
    friend std::istream &operator>>(std::istream &in, Street &s)
    {
        in >> s.x1 >> s.y1 >> s.x2 >> s.y2;
        return in;
    }
    bool operator==(const Street other)
    {
        bool flag = false;
        float x0 = 0, y0 = 0; //точка условного пересечения
        if ((x1 == other.x1) && (y1 == other.y1) || (x1 == other.x2) && (y1 == other.y2))
        {
            x0 = x1;
            y0 = y1;
            return true;
        }
        if ((x2 == other.x1) && (y2 == other.y1) || (x2 == other.x2) && (y2 == other.y2))
        {
            x0 = x2;
            y0 = y2;
            return true;
        }
        if (fabs(k) != fabs(other.k))
        {
            y0 = (other.x1 - x1 + y1 * k - other.y1 * other.k) / (k - other.k);
            x0 = x1 + (y0 - other.y1) * k;
            flag = true;
        }
        // std::cout << x0 << " " << y0 << '\n';
        if (flag == false)
            return false;
        else
        {
            bool a1 = ((x1 <= x0) && (x0 <= x2) || ((x2 <= x0) && (x0 <= x1)));
            bool a2 = ((other.x1 <= x0) && (x0 <= other.x2) || ((other.x2 <= x0) && (x0 <= other.x1)));
            return (a1 && a2);
        }
    }
};
bool chec(Street &st, float &x, float &y)
{
    if ((st.x1 <= x) && (x <= st.x2) || ((st.x2 <= x) && (x <= st.x1)))
    {
        return true;
    }
    else
        return false;
}
int main()
{
    float x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    std::cin >> x1 >> x2 >> y1 >> y2;
    Street s1(x1, x2, y1, y2);
    std::cin >> x1 >> x2 >> y1 >> y2;
    Street s2(x1, x2, y1, y2);
    bool b = (s1 == s2);
    if (b)
    {
        std::cout << "NO";
    }
    else
    {
        std::cout << "YES";
    }
    return 0;
}