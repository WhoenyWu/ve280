#include <string>
#include <iostream>

#include "cord.h"

using namespace std;

bool is_cord(cord *c) {
    if (c == nullptr) {
        return true;
    }
    if (c->left == nullptr && c->right == nullptr && c->len && c->len == c->data.length()) {
        return true;
    }
    if (c->left != nullptr && c->right != nullptr) {
        if (c->left->len == 0 || c->right->len == 0 || c->len != c->left->len + c->right->len) {
            return false;
        }
        if (is_cord(c->left) && is_cord(c->right)) {
            return true;
        }
    }
    return false;
}

size_t cord_length(cord_t R) {
    if (R == nullptr) {
        return 0;
    } else {
        return R->len;
    }
}

cord_t cord_new(const std::string &s) {
    if (s.length()) {
        return new cord{s.length(), nullptr, nullptr, s};
    } else {
        return nullptr;
    }
}

cord_t cord_join(cord_t R, cord_t S) {
    if (R == nullptr) {
        return S;
    }
    if (S == nullptr) {
        return R;
    }
    return new cord{cord_length(R) + cord_length(S), R, S, ""};
}

string cord_tostring(cord_t R) {
    // TODO: Your implementation here
   /* if (R == nullptr)
        return "";
    else
        return cord_tostring(R->left) + cord_tostring(R->right) + R->data;
    */
    if (R == nullptr)
        return "";
    if (R->left == nullptr && R->right == nullptr)
        return R->data;
    else
        return cord_tostring(R->left) + cord_tostring(R->right);
}


char cord_charat(cord_t R, size_t i)
/*@requires 0 <= i && i < cord_length(R); @*/
{
    // TODO: Your implementation here
    //solution1: 待定
    /*
    if (R==nullptr)
        return '\0';
    string sum = cord_tostring(R);
    return sum[i]; //为啥不能直接这种方法？string 和 char？
    //照片有解法
     */
    //solution2
    if (R->left == nullptr && R->right == nullptr)
        return R->data[i];
    if (i < R->left->len)
        return cord_charat(R->left, i);
    else
        return cord_charat(R->right, i-R->left->len);
}

cord_t cord_sub(cord_t R, size_t lo, size_t hi)  //左闭右开 c++基本都是
/*@requires 0 <= lo && lo <= hi && hi <= cord_length(R); @*/
{
    //1. 完全可以利用
    //2. 保留框架
    //3. 删除框架
    //都右，都左，一左一右分情况讨论
    // TODO: Your implementation here
    if (lo == 0 && hi == R->len)
        return R;
    if (R->left == nullptr && R->right == nullptr)
        return cord_new(R->data.substr(lo, hi-lo)); //左闭右开
    
    if (hi <= R->left->len)
        return cord_sub(R->left, lo, hi);
    else if (lo >= R->left->len)
        return cord_sub(R->right, lo - R->left->len, hi-R->left->len);
    else
        return cord_join(cord_sub(R->left, lo, R->left->len), cord_sub(R->right, 0, hi-R->left->len));
}

void cord_print(cord_t R) {
    if (R == nullptr)
        cout << "\"\"";
    else if (R->left == nullptr && R->right == nullptr)
        cout << "\"" << R->data << "\"";
    else {
        cout << "( ";
        cord_print(R->left);
        cout << " ";
        cord_print(R->right);
        cout << " )";
    }
}

