#include "../list.h"

int main()
{
    List A{1,2,3};
    A.PopFront();
    int x =5;
    A.PushBack(x);
    A.PopBack();
    std::cout<<A.ToString();
    return 0;
}
