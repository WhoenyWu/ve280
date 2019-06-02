//
//  lab1.cpp
//  lab1
//
//  Created by whoeny on 5/31/19.
//  Copyright © 2019 whoeny. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "lab1.h"

using namespace std;

bool is_alternating(int num, int base) {
    // TODO: Your implementation here
    if (num >= 1 && num <= 10000000 && base >= 2 && base <= 10) return true;
    return false;
}

void test_alternating() {
    int num, base;
    cout << "Input the num and base: " << endl;
    cin >> num >> base;
    
    assert(is_alternating(num, base));  //
    // TODO: Add more test cases
    
    int i = 1, transfer = 0;
    
    while(num > 0) {
        transfer = transfer + i * (num % base);    // transfer is the num in base
        num /= base;
        i *= 10;
    }
    
    //cout << transfer << endl;
    int flag = 0;
    if (transfer / 10 != 0) {    //改成 transfer >= base 更好
        //改成简洁的思路：((num % base) + (num / base % base)) % 2 或者 if(new_number[i] % 2 == new_number[i+1] % 2)更好
        int odd = transfer % 2;
        int even = (transfer / 10) % 2;
        if (odd == even) flag = 1;
        else {
            int num_odd = transfer / 100, num_even = transfer / 1000;
            //cout << num_odd << endl << num_even << endl;
            
            while (num_odd > 0) {
                //cout << num_odd % 2 << endl;
                if (odd != num_odd % 2) {flag +=1; break;}
                //cout << flag << endl;
                num_odd /= 100;
                //cout << num_odd << endl;
            }
            
            //cout << "flag " << flag << endl;
            
            while (num_even > 0) {
                //cout << num_even % 2 << endl;
                if (even != num_even % 2) {flag +=1; break;}
                //cout << flag << endl;
                num_even /= 100;
                //cout << num_even << endl;
            }
            //cout << "flag " << flag << endl;

        }
    }
    //cout << flag << endl;
    
    if (flag == 0) cout << "Alternating number tests passed!" << endl;
    else cout << "Alternating number tests failed!" << endl;
}
/*
#include <iostream>
#include <cmath>
#include <cstring>
#include <cassert>

using namespace std;

bool is_odd(int num) {
    for (int i = -9; i <= 9; i += 2) {
        if (num == i) {return true;}
    }
    return false;
}

bool is_alternating(int num, int base) {
    // TODO: Your implementation here
    int digit = ceil(log10(num));
    if (digit == 1) {
        return true;
    } else {
        digit = 4;
        cout << digit << endl;
        int number[digit];
        cout << sizeof(number) << endl;
        
        memset(number, 0, sizeof(number));
        
        cout << sizeof(number) << endl;

        for (int i = 0; i < digit; i++) {
            while (ceil(log10(num)) == digit - i | log10(num) == digit - i - 1) {
                number[i]++;
                num = num - pow(10, digit - i -1);
            }
        }
        for (int i = 0; i < digit - 1; i++) {
            if (is_odd(number[i] - number[i + 1]) == false) {
                return false;
            }
        }
    }
    return true;
}

void test_alternating() {
    assert(!is_alternating(24, 10));  // 24 is not an alternating number in base 10
    // TODO: Add more test cases
//    assert(is_alternating(1234543210, 10));
  //  assert(is_alternating(101010101, 2));
    //assert(is_alternating(2, 10));
    cout << "Alternating number tests passed!" << endl;
}

*/
