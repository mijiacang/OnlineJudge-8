/*************************************************************************
	> File Name: PowerofFour.cpp
	> Author: liboyang
	> Mail: 578072836@qq.com
	> Created Time: Wednesday, October 19, 2016 PM08:04:00 CST
 ************************************************************************/
// If it's power of two, it will only contain one "1" like ( 0001, 0010, 0100 so on);
// if it's power of four, it will only contain one "1" AND the "1" must be at even position.
 
#include <iostream>
#include <bitset>
using namespace std;

class Solution {
    public:
    bool isPowerOfFour(int num) {
        if(num <= 0){
            return false;
        }
        
        bitset<32> n(num);
        if(n.count() != 1){
            return false;
        }
        for(int i = 0; i < 32; i++){
            if(n[i] == 1 && i % 2 == 0){
                return true;
            }
        }
        return false;
    }
};


// 下面是大师级的位操作，其实逻辑和上面一样，但是代码量少很多
/*
bool isPowerOfFour(int n) {
        return n>0 && (n&(n-1))==0 && (n&0x55555555);
}
*/