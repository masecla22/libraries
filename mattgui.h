#pragma once
#include "mattcore.h"
using namespace std;
namespace matt{namespace gui{
size_t getSlash(string a){
    size_t ss=0;
    for(size_t i=0; i<a.length(); i++)
        ss+=(a.at(i)=='/'&&a[i+1]!='/');
    return ss;
}
void showArg(string a,size_t which){size_t j=0;
    for(size_t i=0;i<a.length();i++){
        j+=(a.at(i)=='/');
        if(j==which&&a.at(i)!='/')cout<<a.at(i);
    }
}
void show(string opts,vector<int>vals){
    for(size_t i=0; i<getSlash(opts);i++,cout<<"\t\n"){
        if(vals.at(i)==1)cout<<"> ";
        showArg(opts,i);
    }
}
int gui(string opts){
    matt::core::clear();
    vector<int>vals;
    vals.push_back(1);
    for(size_t i=1; i<getSlash(opts);i++) vals.push_back(0);
    show(opts,vals);
    int pos=0;
    matt::core::ShowConsoleCursor(false);
    while(1){
        size_t a=_getch();
        matt::core::clear();
        if(a==80) (pos==(getSlash(opts)-1))?pos=0:pos++;
        if(a==72) (pos==0)?pos=(getSlash(opts)-1):pos--;
        if(a==13){matt::core::clear();break;}
        for(int i=0; i<getSlash(opts); i++)vals[i]=(pos==i);
        show(opts,vals);
    }
return pos;}}}
