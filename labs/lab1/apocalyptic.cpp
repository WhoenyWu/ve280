//
//  apocalyptic.cpp
//  lab1
//
//  Created by whoeny on 6/1/19.
//  Copyright © 2019 whoeny. All rights reserved.
//


// This is my no-end solution
/*
#include <iostream>
#include <cassert>
#include "lab1.h"
#include <vector>
 using namespace std;

bool is_apocalypic(int num) {
    // TODO: Your implementation here
    vector<int> a;
    int i;
    num =
    while(num > 0) {
        a.push_back(num % 10);
        num /= 10;
    }
    for (i = 0; i < a.size()); ++i;) {
        
    }
    return false;
}

void test_apocalyptic() {
    assert(!is_apocalypic(24));  // 24 is not an alternating number in base 10
    // TODO: Add more test cases
    cout << "Alternating number tests passed!" << endl;
}
*/

//next is solution 1

 
#include <iostream>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

bool is_apocalyptic(int num) {
    int result[num];
   // int test = 1;
    //cout << sizeof(test) << endl;
    //cout << num << endl;
   // cout << sizeof(result) << endl;

    memset(result, 0, sizeof(result));
 //   cout << sizeof(result) << endl;
    
    result[0] = 1;
    for (int i = 0; i < num; i++) {
        int carry = 0;
        for (int j = 0; j < i + 1; j++) {
            result[j] = 2 * result[j] + carry;
            if (result[j] > 9) {
                result[j] -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
        }
    }
//    for (int i = 0; i < sizeof(result); ++i)
  //      cout << result[i];
    
    //cout << endl << endl;
    for (int i = 0; i < num - 2; i++) {
        if (result[i] == 6 and result[i + 1] == 6 and result[i + 2] == 6) {
            return true;
        }
    }
    return false;
}

void test_apocalyptic(){
    assert(!is_apocalyptic(2));
    assert(is_apocalyptic(157));
    cout << "Apocalyptic number tests past!" << endl;
}

/*
//this is the second solution
#include "lab1.h"
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;


bool is_apocalyptic(int num) {
    vector<int> vec(1,1);
    
    for (int i = 1; i <= num; i++) {
        for (int j = 0; j <= vec.size() - 1; vec[j] *= 2, j++);
        
        for (int j = 0; (vec.size() >= 2) && (j <= vec.size() - 2); j++) {
            vec[j + 1] += vec [j] / 10;
            vec[j] = vec [j] % 10;
        }
        
        if (vec[vec.size() - 1] >= 10) {
            vec.push_back(vec[vec.size()- 1] / 10);
            vec[vec.size() - 2] = vec[vec.size() - 2] % 10;
        }
    }
    
    //for (int i = 0; i <= vec.size() - 1; i++) cout << vec[vec.size() - 1 - i];
    //cout << endl;
    
    for (int i = 0; (vec.size() >3) && (i <= vec.size() - 3); i++) {
        if ((vec[i] == 6) && (vec[i + 1] == 6) && vec[i + 2] == 6) return true;
    }
    
    return false;
    
}

void test_apocalyptic() {
    assert(!is_apocalyptic(1));
    //assert(is_apocalypse(157));
    assert(!is_apocalypse(200));
    assert(is_apocalypse(220));
    assert(is_apocalypse(931));
    //assert(!is_apocalypse(1700));
    assert(is_apocalyptic(1701));
    // TODO: Add more test cases
    cout << "Apocalypse number tests passed!" << endl;
}
*/

