#include <iostream>
enum Error
{
    Continue = 100,
    OK = 200,
    Created = 201,
    Accepted = 202,
    Bad_Request = 400,
    Unauthorized = 401,
    Not_Found = 404,
    Method_Not_Allowed = 405,
    Internal_Server_Error = 500,
    Not_Implemented = 501,
    Bad_Gateway = 502
};
void error_handling(Error error)
{
    switch (error)
    {
    case Error::Continue:
        std::cout << "Continue" << std::endl;
        break;

    case Error::OK:
        std::cout << "OK" << std::endl;
        break;
    case Error::Created:
        std::cout << "Created" << std::endl;
        break;
    case Error::Accepted:
        std::cout << "Accepted" << std::endl;
        break;
    case Error::Bad_Request:
        std::cout << "Bad Request" << std::endl;
        break;
    case Error::Unauthorized:
        std::cout << "Unauthorized" << std::endl;
        break;
    case Error::Not_Found:
        std::cout << "Not Found" << std::endl;
        break;
    case Error::Method_Not_Allowed:
        std::cout << "Method Not Allowed" << std::endl;
        break;
    case Error::Internal_Server_Error:
        std::cout << "Internal Server Error" << std::endl;
        break;
    case Error::Not_Implemented:
        std::cout << "Not Implemented" << std::endl;
        break;
    case Error::Bad_Gateway:
        std::cout << "Bad Gateway" << std::endl;
        break;
    default:
        std::cout << std::endl;
        break;
    }
}
int main()
{
    int i = 0;
    int array[20] = {0};
    std::cin >> array[i];
    while (array[i] != 0)
    {
        i++;
        std::cin >> array[i];
    }
    for (int j = 0; j < i; j++)
    {
        error_handling(static_cast<Error>(array[j]));
    }
}