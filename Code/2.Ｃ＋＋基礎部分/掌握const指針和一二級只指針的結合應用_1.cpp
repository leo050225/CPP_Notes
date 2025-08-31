#include <iostream>
using namespace std;

/*
const和一級指針的結合
const和二級（多級）指針的結合

const修飾的量 叫常量
普通變量的區別是什麼？ C++有兩點區別？ 1.編譯方式不同 2.不能作為左值

const修飾的量常出現的錯誤是：
1,常量不能再作為左值 <= 直接修改常量的值
2.不能把常量的地址洩露給普通的指針或者普通的變量 <= 可以間接修改常量的值

const和一級指針的結合
C++的語言規範：const修飾的是離他最近的類型（用＊隔開）

int：代表能不能修改值
p常量名：代表能不能修改指針指向

const int *p; 修飾int 可以任意指向不同的int類型的內存，但是不能通過指針間接修改指向內存的值

int const *p; 修飾int 跟上面一樣

int *const p; 修飾p 這個指針p是常量 不能在指向其他內存，但是可以通過指針解引用修改指向的內存的值


const int *const p; 指針和值都不能被修改

整形常量指針不能給普通指針  int * <=const int* 錯誤
普通指針能給常量指針 const int* <= int* 正確

總結：const和指針的類型轉換公式
int* <= const int*. 是錯誤的！
const int* <= int*  是可以的！

int** <= const int** 是錯誤的！
const int** <= int** 是錯誤的！

int** <= int*const* == * <= const* 是錯誤的！
int*const* <= int** 是可以的！

*/
#if 0
int main()
{
    int *q1 = nullptr;
    int * const q2 = nullptr;
    cout<<typeid(q1).name()<<endl;
    cout<<typeid(q2).name()<<endl;
    //const如果右邊沒有＊的話，const是不參與類型
    int a = 10;
    // int *p = &a;會變成間接修改常量的值
    const int *p1 = &a;//const int* <= int*（類型）
    int *const p2 = &a;//int* <= int*（類型）
    int * const p3 = &a;//int* <= int*
    int *p4 = p3;//int* <= int*

    return 0;
}
#endif
/*
const和二級指針的結合
*/
int main()
{
    int a = 10;
    int *p = &a;
    int*const*q = &p;//int*sonct* <= int** 可以的！

    // int a = 10;
    // int *p = &a;
    // const int **q = &p;
    //不能用 會把常量指針的位置給到普通指針

    // const int **q = &p;
    /*
    p = *q
    const int *     *q = &p
    *q <=> p
    const int b = 20;
    *q = &b 可以的
    */

    int b = 10;
    const int *p2 = &a;
    const int **q2 = &p2;//能用
}
