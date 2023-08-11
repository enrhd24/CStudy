// limits.cpp

#include <iostream>
#include <climits>

int main(){
    using namespace std;
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;
    
    // sizeof 연산자는 데이터형이나 변수의 크기를 알아낸다.
        cout << sizeof(int) << sizeof n_short << 
        sizeof n_long << sizeof n_llong << endl;
    
        cout << "바이트 당 비트 수" << CHAR_BIT << endl;
    return 0;
}