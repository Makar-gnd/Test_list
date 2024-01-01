#include "../list.h"

int main()
{
    List A{1,2,3};
    A.PopFront();
    std::cout<<A.ToString();
    return 0;
}
