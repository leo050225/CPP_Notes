#include <iostream>
using namespace std;

/*
C++的引用 引用和指針的區別？
1.左值引用和右值引用
2.引用的實例

引用是一種更安全的指針
1.引用是必須初始化的，指針可以不用初始化
兩者在匯編指令上沒有區別，都是經過指針。
2.引用只有一級指針，沒有多級引用，指針可以有一級指針，也可以有多級指針。
3.定義一個引用變量，和定義一個指針變量，其匯編指令是一模一樣的。通過引用變量修改所引用內存的值，和通過指針引用修改指針指向的內存的值，其底層指令也是一模一樣的。

右值引用
1.int &&c = 20; 專門用來引用右值類型，指令上，可以自動產生臨時量，然後直接引用臨時量 c = 40;
2.右值引用變量本身是一個左值，只能用左值引用來引用它。
3.不能用一右值引用變量，來引用一個左值。

*/
#if 0
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 10;
    int b = 20;
    swap(a,b);
    cout<<"a:"<<a<<"b:"<<b<<endl;
}
#endif

#if 0
int main()
{
    int a = 10;
    int *p = &a;//指針
    // int *p = nullptr;
    int &b = a;//引用

    // int &c = 10 錯誤的

    *p = 20;
    //20 20 20
    cout << a << " " << *p << " " << b << endl;

    b = 30;
    //30 30 30
    cout << a << " " << *p << " " << b << endl;

    return 0;
}
#endif

#if 0
int main()
{
    int array[5] = {};
    int *p = array;

    //定義一個引用變量，來引用array數組
    int(&q)[5] = array;//size:20
    int(*o)[5] = &array;//size:8

    cout<<sizeof(array)<<endl;//size:20 int(4)*5
    cout<<sizeof(p)<<endl;//size:8 （64位元系統）
    cout<<sizeof(q)<<endl;

    return 0;
}
#endif

int main()
{
    int a = 10;//左值，它有內存，有名字，值可以修改的。
    int &b = a;

    int c = 20;//20是右值：沒內存，沒名字。
    //C++11提供了右值引用
    int &&c = 20;//右值引用
    c = 30;//能修改

    int &e = c;//一個右值引用變量，本身是一個左值。
    // int &&e = c;//不能使用

    /*
    int temp = 20;
    temp -> b
    */
    const int &b = 20;
    // &d = 9;不能修改




    return 0;
}
