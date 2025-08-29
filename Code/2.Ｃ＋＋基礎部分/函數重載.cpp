#include <iostream>
using namespace std;

/*
函數重載
1.C++為什麼支持函數重載，C語言不支持函數重載
C++代碼產生函數符號時後，函數名＋參數列表類型組成的！
C代碼產生函數符號的時候，函數名來決定！
2.函數重載需要注意些什麼
3.C++和C語言代碼之間如何互相調用

什麼是函數重載？
1.一組函數，其中函數名相同，參數列表的個數或者類型不同，
那麼這一組函數就稱作-函數重載。
2.一組函數要稱得上重載，一定先是處在同一個作用域當中。
3.const或者volatile的時候，是怎麼影響形參類型。
4.一組函數，函數名相同，參數列表相同，僅僅返回值不同？不叫重載

請你解釋一下，什麼是多態？
靜態（編譯時期）的多態：函數重載
動態（運行時期）的多態：

什麼是函數重載？靜態的多態的一部分

C調用C++：無法直接調用!怎麼辦？把C++源碼括在extern "C"裡面
C++調用C代碼：無法直接調用!怎麼辦？ 把C函數的聲明放在extern "C"裡面
extern "C"{int sum(int a, intb);}
*/
//__FILE__
//__LINE__
//只要是C++編譯器，都內置了__cplusplus這個宏名

#ifdef __cplusplus
extern "C"{
#endif
    int sum(int a, int b)
    {
        return a+b;
    }
#ifdef __cplusplus
}
#endif

#if 0
extern "C"
{
    int sum (int a, int b)
    {
        return a+b;
    }
}

int main()
{

}

bool compare(int a, int b)//compare_int_int
{
    cout<<"compare_int_int"<<endl;
    return a > b;
}
bool compare(double a, double b)//compare_double_double
{
    cout<<"compare_double_double"<<endl;
    return a > b;
}
bool compare(const char *a, const char *b)//compare_char*_char*
{
    cout<<"compare_char*_char*"<<endl;
    return strcmp(a,b) > 0;
}
int main()
{
    // bool compare(int a, int b);//函數的聲明

    compare(10, 20);
    compare(10.0, 20.0);//double -> int;
    compare("aaa", "bbb");//const char* -> int

    return 0;
}
#endif
