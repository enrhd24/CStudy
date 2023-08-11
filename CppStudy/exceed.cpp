// exceed.cpp

#include <iostream>
#define SERO 0
#include <climits>

int main(){
    using namespace std;

    short Dohee = SHRT_MAX;
    unsigned short Insuk = Dohee;

    Dohee++;
    Insuk++;

    cout << "이럴수락 누구가 나 몰래 대출을 했나?" << endl;

    Dohee = SERO;
    Insuk = SERO;

    Dohee--;
    Insuk--;

    cout <<  "이럴 수가 누구가 복권에 당첨되었나?" << endl;
    return 0;
}