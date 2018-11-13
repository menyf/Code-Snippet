// Wrote by MenYifan on 2015-04-12 19:44:15
// Exe.Time 31ms Exe.Memory 4K
//
//  20150412a.cpp
//  Cfiles
//
//  Created by ??? on 15/4/12.
//  Copyright (c) 2015? ???. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    int black=0,white=0;
    for (int i=0; i<72; i++) {
        char ch=getchar();
        switch (ch) {
            case 'Q':
                white+=9;
                break;
            case 'q':
                black+=9;
                break;
                
            case 'R':
                white+=5;
                break;
            case 'r':
                black+=5;
                break;
                
            case 'B':
                white+=3;
                break;
            case 'b':
                black+=3;
                break;
                
            case 'N':
                white+=3;
                break;
            case 'n':
                black+=3;
                break;
                
            case 'P':
                white+=1;
                break;
            case 'p':
                black+=1;
                break;
                
            default:
                break;
        }

    }
  //  printf("white :%d Black :%d\n",white,black);
    if (white>black) {
        printf("White");
    }
    else if (white<black){
        printf("Black");
    }
    else
        printf("Draw");
}