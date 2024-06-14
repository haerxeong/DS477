#include "ArrayList.h"

ArrayList::ArrayList(): data{}, length(0) {} //data, length 초기화
ArrayList::~ArrayList(){}
    
bool  ArrayList::isEmpty() {
    //length의 값이 0이라면 비어있다는 의미이므로 해당 boolean 값을 반환한다.
    return length == 0;
}

bool ArrayList::isFull() {
    //length의 값이 MAX_LIST_SIZ와 동일하다면 배열이 차있다는 의미이므로 해당 boolean 값을 반환한다.
    return length == MAX_LIST_SIZE;
}


//pos값은 정상범위 값만을 가정!
void ArrayList::insert(int pos, int item) {
    //맨 마지막 데이터부터 pos에 해당하는 데이터까지 역순으로 한 칸씩 뒤로 이동한다
    for (int i = length - 1; i >= pos; i--)
        data[i + 1] = data[i];
    
    //pos 위치에 item을 삽입한다
    data[pos] = item;

    //length 값을 증가시킨다
    length++;
}

int ArrayList::remove(int pos) {
    //pos 위치에 해당하는 요소를 변수에 저장한다
    int temp = data[pos];

    //pos 위치의 그 다음 인덱스부터 마지막까지 한 칸씩 앞으로 이동한다
    for (int i = pos + 1; i < length; i++)
        data[i - 1] = data[i];
    
    //length 값을 감소시킨다
    length--;

    //값을 반환한다
    return temp;
}

bool ArrayList::find(int item) {
    //리스트를 0번 인덱스부터 탐색하며 item에 해당하는 요소가 배열에 있는지 확인한다
    for (int i = 0; i < length; i++)
        if (data[i] == item) return true;
    return false;
}
    
int ArrayList::getEntry(int pos) {
    //배열에서 pos 위치에 있는 요소를 반환한다
    return data[pos];
}

void ArrayList::replace(int pos, int item) {
    //배열에서 pos 위치에 있는 요소를 item으로 대체한다
    data[pos] = item;
}

int ArrayList::size() {
    //요소 개수에 해당하는 length를 반환한다
    return length;
}
    
void ArrayList::display() {
    if (isEmpty())
        cout << "Stack is EMPTY - No display" << endl;
    else {
        for (int i = 0; i < length; i++)
            cout << data[i] << "  ";
        cout << endl;
    }
}
void ArrayList::clear() {
    //배열을 비우기 위해 length의 값을 초기값인 0으로 설정한다
    length = 0;
}
