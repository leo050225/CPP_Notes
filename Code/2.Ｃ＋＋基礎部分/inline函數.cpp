#include <iostream>
using namespace std;

/*
===> inline內聯函數 和 普通函數的區別？？？
inline內聯函數：在編譯過程中，就沒有函數的調用開銷了，在函數的調用點
把函數的代碼進行展開處理 ret = sum(a,b) => ret = a+b

inline函數不再生成相應的函數符號

inline只是建議編譯器把這個函數處理成內聯函數
但是不是所有的inline都會被編譯器處理成內聯函數 例如：遞歸

debug版本上，inline是不起作用的。 inline只能在release版本下才能出現
g++ -c main.cpp -o2. objdump -t main.o
*/

inline int sum(int x, int y)// *.o sum_int_int .text 不會生成
{
    return x + y;
}

int main()
{
    int a = 10;
    int b = 20;

    int ret = sum(a,b);// => int ret = a+b;
    //此處函數調用過程 參數壓棧，函數棧幀的開闢和回退過程
    //有函數調用的開銷
    //x+y mov add mov

    return 0;
}
