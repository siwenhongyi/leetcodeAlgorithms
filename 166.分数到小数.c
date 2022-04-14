/*
 * @lc app=leetcode.cn id=166 lang=c
 *
 * [166] 分数到小数
 */
// #include "head.h"
#include<stdio.h>
#include<memory.h>
// using namesapce std;
// @lc code=start


char * fractionToDecimal(int a, int b){
    if(a == 0) return "0";
    char* res =(char*) malloc(sizeof(char)*100);
    int index = 0;
    if(!((a >0) ^ (b >0))) res[index++] = '-';

    long long q = a/b,r = a%b;
    if(r == 0) return res;
    res[index++] = q + '0';
    res[index++] = '.';
    int *hash = malloc(sizeof(int)*100);
    memset(hash,0,sizeof(int)*100);
    while(r){
        if(hash[r]){
            res[index-1] = '(';
            res[index++] = ')';
            break;
        }
        hash[r] = index;
        q = r*10;
        res[index++] = q/b + '0';
        r = q%b;
    }
    return res;
}
// @lc code=end

