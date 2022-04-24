//
// Created by nanjingblue on 2022/2/21.
//
#include "keywords_process.h"

bool isAlphabet(char c) {
    return ('a' <= c && 'z' >= c);
}

void filterComments(std::ifstream &ifs, char &c) {
//    ifs.get(c);
    // 过滤注释
    if (c == '/') {
        // 判断两种类型注释
        ifs.get(c);
        // 1. "//" 型注释 则读到 '\n' 为止
        if (c == '/') {
            while (c != '\n' && !ifs.eof()) ifs.get(c);
        }// 2. "/* */" 型注释 则读到 "*/" 为止
        else if (c == '*') {
            if (!ifs.eof()) {
                ifs.get(c);
                while (c != '*') {
                    ifs.get(c);
                    if (c == '*' && !ifs.eof())
                        ifs.get(c);
                    if (c == '/') break;
                }
            }
        }
    }
//     过滤字符串 “int”
    if (c == '"') {
        ifs.get(c);
        while (c != '"' && !ifs.eof()) ifs.get(c);
    }
}

bool isKeyword(std::string key) {
    for (int i = 0; i < keyNums; ++i) {
        if (KeyWords[i] == key) {
            return true;
        }
    }
    return false;
}

