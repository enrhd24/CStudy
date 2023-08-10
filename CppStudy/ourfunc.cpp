// ourfunc.cpp

#include <iostream>
void simon(int);

int main(){
    using namespace std;
    simon(3);
    cout <<  "정쉬를 하나 고르시오: ";
    int count;
    cin >> count;
    simon(count);
    cout << "끝!" << endl;
    return 0;
}

void simon(int n){
    using namespace std;
    cout << "SIMON 왈, 발가락을 " << n << "범 두드려하."<< endl;
}