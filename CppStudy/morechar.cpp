// morechar.cpp

#include <iostream>

int main(){
    using namespace std;

    char ch = 'M';
    int i = ch;

    cout << ch << "의 아스키 코드는 " << i << "입니다." << endl;
    ch++;
    i++;

    cout.put(ch);
    cout << ch << "의 아스키 코드는 " << i << "입니다." << endl;
    

    return 0;
}