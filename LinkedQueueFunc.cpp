#include "LinkedQueue.h"

LinkedQueue::LinkedQueue() : front(nullptr), rear(nullptr) {} //생성자에서 front, rear을 null로 초기화

LinkedQueue::~LinkedQueue() {
    //소멸자에서 동적할당 해제
    while (!isEmpty()) {
        dequeue();
    }
}
	
bool LinkedQueue::isEmpty()
{
    return front == nullptr; //front가 nullptr = dequeue할 node가 없음 = 비어있음
}

void LinkedQueue::enqueue(int data)
{
    Node* newNode = new Node(data); //새로운 노드 생성(동적할당)

    if (isEmpty()) {
        front = rear = newNode;
    } //공백 상태일 경우의 enqueue: nullptr이었던 front, rear이 newNode를 가리킴
    else {
        rear->setNext(newNode);
        rear = newNode;
    } //공백상태가 아닐 경우 기존 rear의 next를 새로운 노드로 설정하고 rear가 새로운 노드를 가리키게 함
}

Node* LinkedQueue::dequeue() 
{
    Node* removed = front; //제일 먼저 삽입된 front를 removed에 넣음

    if (isEmpty()) cout << "Queue is Empty!" << endl; //queue가 공백상태일 경우 처리
    else if (front == rear) front = rear = nullptr; //노드가 하나인 경우: front, rear을 null로
    else front = removed->getNext(); //front가 기존의 다음 노드를 가리키도록 함
    
    return removed;    
}

int LinkedQueue::peek()
{
    if (isEmpty()) return -1; //비어있는 경우 예외처리
    return front->getData(); //front의 값 반환
}

void LinkedQueue::display()
{
    //currnt로 순회하며 출력
    Node* current = front;
    while (current != nullptr) {
        cout << current->getData() << "  ";
        current = current->getNext();
    }
    cout << endl;
}