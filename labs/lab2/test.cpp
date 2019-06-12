#include <iostream>
#include "cord.h"

using namespace std;

int main(int argc, char **argv) {
    cord_t c;

    c = cord_new("");
    assert(c == nullptr);
    assert(cord_length(c) == 0);

    cord_t c1 = cord_new("1234");
    assert(cord_length(c1) == 4);

    cord_t c3 = cord_join(c1, cord_new("56"));
    assert(cord_length(c3) == 6);
    assert(cord_tostring(c3) == "123456");

    cord_t c4 = cord_new("012345");
    assert(cord_charat(c4, 0) == '0');
    assert(cord_charat(c4, 1) == '1');
    cord_t c5 = cord_sub(c4, 2, 4);
    assert(cord_length(c5) == 2);
    assert(cord_charat(c5, 0) == '2');
    assert(cord_charat(c5, 1) == '3');

    cord_t c6 = cord_new("012345");
    cord_t c7 = cord_sub(c6, 0, cord_length(c6));
    assert(c7 == c6);

    cord_t c8 = cord_new("6789");
    cord_t c9 = cord_join(c6, c8);
    cord_t c10 = cord_sub(c9, 6, 10);
    assert(c10 == c8);

    cord_t R = cord_join(cord_join(cord_new("t"), cord_new("otally")), cord_join(cord_new("efficien"), cord_new("t")));
    assert(cord_tostring(R) == "totallyefficient");

    cord_t R1 = cord_sub(R, 1, 16);
    assert(cord_tostring(R1) == "otallyefficient");
    assert(R1->left == R->left->right);
    assert(R1->right == R->right);

    cord_t R2 = cord_sub(R, 1, 11);
    assert(cord_tostring(R2) == "otallyeffi");
    assert(R2->left == R->left->right);

    cord_t R3 = cord_sub(R, 2, 11);
    assert(cord_tostring(R3) == "tallyeffi");

    assert(is_cord(c4));
    assert(is_cord(c5));
    assert(is_cord(c6));
    assert(is_cord(c7));
    assert(is_cord(c8));
    assert(is_cord(c9));
    assert(is_cord(c10));
    assert(is_cord(R));
    assert(is_cord(R1));
    assert(is_cord(R2));
    assert(is_cord(R3));

    cord_t c11 = cord_join(c8, c8);
    assert(is_cord(c11));

    cord_t ct1 = cord_new("c1");
    cord_t ct2 = cord_new("c2");
    cord_t ct3 = cord_new("c3");
    ct1->left = ct2;
    ct2->left = ct1;
    ct2->right = ct3;
    ct1->right = ct3;
    ct1->len = 0;
    ct2->len = 0;
    ct3->len = 0;
    assert(!is_cord(ct1));

    cout << "Cord tests passed!" << endl;

    return 0;
}