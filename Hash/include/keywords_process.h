//
// Created by nanjingblue on 2022/2/21.
//
#pragma once

#ifndef HASH_KEYWORDS_PROCESS_H
#define HASH_KEYWORDS_PROCESS_H

#include <iostream>
#include <fstream>

static int keyNums = 39;
static std::string KeyWords[39]={ "asm","auto","break","case","cdecl","char",
"const","continue","default","do","double",
"else","enum","extern","far","float","for",
"goto","huge","if","int","interrupt","long",
"near","pascal","register","return","short",
"signed","sizeof","static","struct","switch",
"typedef","union","unsigned","void","volatile",
"while"};



// isAlphabet 判断字符是否为字母 关键词的字符组成都为字母
bool isAlphabet(char c);

// gilterComments 过滤C源程序文件中的注释
void filterComments(std::ifstream &ifs, char &c);

// isKeyword 判断是否为关键字
bool isKeyword(std::string key);


#endif //HASH_KEYWORDS_PROCESS_H
