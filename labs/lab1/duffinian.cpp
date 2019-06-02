#include <iostream>
#include <cassert>
#include <cmath>
#include "lab1.h"


using namespace std;

bool is_duffinian(int num) {
    // TODO: Your implementation here
    int sqrtnum, i = 1, sum = 0;
    sqrtnum = sqrt(num);
    while (i <= sqrtnum) {
        if (num % i == 0) sum = sum + i + num/i;
        ++i;
    }
    for (i = 2; i <= num; ++i) {
        if (num % i == 0 && sum % i == 0) {return 0; break;}
    }
    return true;
}

void test_duffinian() {
    assert(is_duffinian(35));  // 6 is not a Duffinian number
    assert(!is_duffinian(6));
    assert(is_duffinian(1111));
    assert(!is_duffinian(2346));
    assert(is_duffinian(2519));
    // TODO: Add more test cases
    cout << "Duffinian number tests passed!" << endl;
}
