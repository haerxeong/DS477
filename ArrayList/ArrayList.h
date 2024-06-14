#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__

#include <iostream>

#define MAX_LIST_SIZE    50

using namespace std;

class ArrayList
{
private:
    int    data[MAX_LIST_SIZE];    // 요소의 배열
    int    length;                    // 요소의 개수

public:
    ArrayList();
    ~ArrayList();
    
    bool isEmpty();
    bool isFull();


    //pos값은 정상범위 값만을 가정!
    void insert(int pos, int item);
    int remove(int pos);
    bool find(int item);
    
    int getEntry(int pos);
    void replace(int pos, int item);
    int size();
    
    void display();
    void clear();       //배열 완전 비우기
};

#endif
