#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#include <vector>
#include <bits/stdc++.h>

class Solution {
public:
    int minFlips(int a, int b, int c) {
        /*
        预备知识：
            1.对于十进制整数 x，我们可以用 x & 1 得到 x 的二进制表示的最低位，它等价于 x % 2
            2.对于十进制整数 x，我们可以用 x & (1 << k) 来判断 x 二进制表示的第 k 位（最低位为第 0 位）是否为 1。如果该表达式的值大于零，那么第 k 位为 1
            3.对于十进制整数 x，我们可以用 (x >> k) & 1 得到 x 二进制表示的第 k 位（最低位为第 0 位）。如果 x 二进制表示的位数小于 k，那么该表达式的值为零
        
        方法：枚举+位运算
            设 a、b 和 c 二进制表示的第 i 位分别为 bit_a、bit_b 和 bit_c，根据 bit_c 的值，会有以下两种情况：
                若 bit_c 的值为 0，那么 bit_a 和 bit_b 必须都为 0，需要的翻转次数为 bit_a + bit_b；
                若 bit_c 的值为 1，那么 bit_a 和 bit_b 中至少有一个为 1，只有当它们都为 0 时，才需要 1 次翻转；
        */
        int ans = 0;
        for(int i = 0; i < 31; i++){
            int bit_a = (a >> i) & 1;
            int bit_b = (b >> i) & 1;
            int bit_c = (c >> i) & 1;
            if(bit_c == 0){
                ans += bit_a + bit_b;
            }
            else{
                ans += (bit_a + bit_b == 0);
            }

        }
        return ans;



    }
};


