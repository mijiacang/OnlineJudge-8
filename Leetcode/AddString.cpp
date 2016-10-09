/*************************************************************************
	> File Name: AddString.cpp
	> Author: liboyang
	> Mail: 578072836@qq.com
	> Created Time: Sunday, October 09, 2016 PM07:33:16 CST
 ************************************************************************/
/* 实现太过复杂，做了太多不必要的比较和判断。最后那段别人写的代码要好很多，要学习借鉴。 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2);
};

string Solution::addStrings(string num1, string num2)
{
    int flag = 0;
    int num1Len = num1.length();
    int num2Len = num2.length();
    int minLen = 0;
    string head;
    string ret;
    string retFlag = "0";
   
    if(num1Len > num2Len) {
        minLen = num2Len;
        ret = num2;
        head = num1.substr(0, num1Len - num2Len);
        num1 = num1.substr(num1Len - num2Len, num2Len);
    }
    else {
        minLen = num1Len;
        ret = num1;
        head = num2.substr(0, num2Len - num1Len);                        
        num2 = num2.substr(num2Len - num1Len, num1Len);
    }
   
    for(int i = minLen - 1; i >= 0; i --) {
        ret[i] = (char)('0' + (int)(num1[i] - '0') + (int)(num2[i] - '0') + flag);
        if(ret[i] > '9') {
            ret[i] = char(ret[i] - 10);
            flag = 1;
        }
        else {
            flag = 0; 
        }
    }

    if(flag == 0) {
        ret = head + ret;
		return ret;
    }
    else {
        if(head.empty()) {
            ret = "1" + ret;
            return ret;
        }
		
        int i = head.length() - 1;
        while(flag == 1)
        {
            if(i == 0) {
                if(head[0] == '9') {
                    head[0] = '0';
                    head = "1" + head;
                }
                else {
                    head[0] = char(head[0] + 1);
                }
                flag = 0;
            }

            else {
                head[i] = (char)(head[i] + 1);
                    if(head[i] > '9') {
                        head[i] = char(head[i] - 10);
                        flag = 1;
                        i--;
                    }
                    else {
                        flag = 0;
                    }
            }
        }
    }

    ret = head + ret;
    return ret;
}



/* 这是我目前所见到的最好的方法 */
/*
class Solution {
public:
string addStrings(string num1, string num2) {
    int n1 = num1.size(), i = n1 - 1;
    int n2 = num2.size(), j = n2 - 1;
    int carry = 0;
    string res = "";
    while(i>=0 || j>=0 || carry){
        long sum = 0;
        if(i >= 0){sum += (num1[i] - '0');i--;}
        if(j >= 0){sum += (num2[j] - '0');j--;}
        sum += carry; 
        carry = sum / 10;
        sum = sum % 10;
        res = to_string(sum) + res;
    }
    return res;
}
};
*/
