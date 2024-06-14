#include "ArrayList.h"

ArrayList::ArrayList() { length = 0;}
ArrayList::~ArrayList(){} 

bool ArrayList::isEmpty()
{
    return length == 0;
}

bool ArrayList::isFull()
{
return length == MAX_LIST_SIZE;
}

void ArrayList::insert(int pos, int item)
{ 
    if(isFull()) {
        cout << "Stack is FULL" << endl;    // 프로그램 종료~!
        exit(1); 
    }   

    for (int i = length; i > pos; i--) 
        data[i] = data[i - 1];
    data[pos] = item; 
    length++;
}

int ArrayList::remove(int pos)
{ 
    if(isEmpty()) {
        cout << "Stack is EMPTY" << endl;
        exit(1);
    }
    int tmp = data[pos];
    for (int i = pos + 1; i < length; i++)
        data[i - 1] = data[i]; 
    length--;

    return tmp;
}

int ArrayList::getEntry(int pos)
{ 
    if(isEmpty()) {
        cout << "Stack is EMPTY" << endl;
        exit(1); 
    }

    return data[pos];
}

bool ArrayList::find(int item) 
{
    for (int i = 0; i < length; i++) {
        if (data[i] == item) return true; 
    }
    return false;
} 

void ArrayList::replace(int pos, int item) 
{ 
    data[pos] = item;
}

int ArrayList::size()
{ 
    return length;
}

void ArrayList::display()
{
    if(isEmpty()) cout << "Stack is EMPTY - No display" << endl; 
    else {
        for (int i = 0; i < length; i++) 
            cout << data[i] <<" ";
        cout << endl;
    }
}

void ArrayList::clear() 
{ 
    length = 0;
}
