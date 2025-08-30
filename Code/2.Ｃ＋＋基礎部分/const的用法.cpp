#include <iostream>
using namespace std;

/*
const 指針 引用 在函數中的引用
const怎麼理解？
const修飾的變量不能夠在作為左值！！！初始化完成後，值不能被修改！！！

C和C++中const有什麼區別？

C的const
const就是當作一個變量來生成編譯指令

C++的const
必須初始化，叫常量。
所有出現const常量名字的地方，都被常量的初始化替換了！！！
用變量去初始化常量，就變成常變量。會根據初始化的變量去改變。
*/

int main()
{
    const int a = 20;
    // int array[a] == int array[20]
    int *p = (int*)&a;
    *p = 30;

    printf("%d %d %d \n",a,*p,*(&a));
    // printf("%d %d %d \n",20,*p,20);

    return 0;
}
