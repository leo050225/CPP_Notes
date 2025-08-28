#include <iostream>
using namespace std;

/*
===>1.形參帶默認值的函數
1.給默認值的時候，從右向左給。
2.調用效率問題。
3.定義數可以給形參默認值，聲明可以給形參默認值。
4.形參給默認值的時候，不管是定義處給，還是聲明給，形參默認值只能出現一次。
*/

// sum(,20)
int sum(int a , int b = 20);
int sum(int a = 10, int b);

int main()
{
    int a = 10;//[ebp - 4]
    int b = 20;//[ebp - 8]

    int ret = sum(a,b);
    /*
    mov eax, dword ptr[ebp-8]
    push eax
    mov eax, dword ptr[ebp-4]
    push ecx
    call sum
    */
    cout<<"ret:"<<ret<<endl;

    ret = sum(a);
    /*
    push 14H
    mov eax, dword ptr[ebp-4]
    push ecx
    call sum
    */
    ret = sum();//ret = sum(10,20)
    /*
    push 14H
    push 0Ah
    call sum
    */

    return 0;
}

int sum(int a, int b)
{
    return a + b;
}
