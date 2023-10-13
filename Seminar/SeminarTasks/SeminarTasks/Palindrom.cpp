#include <iostream>

// ��������� �� ������� �� ������������ ������
struct Node {
    char data;
    Node* next;
    Node* prev;
    Node(char value) : data(value), next(nullptr), prev(nullptr) {}
};

// �������, ����� ������ ��� ������� ��� ������������ ������
void appendNode(Node*& head, char value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// �������, ����� ������� ���������� �� ������������ ������
void printList(const Node* head) {
    const Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// �������, ����� ��������� ���� ������������� ������ � ���������
bool isPalindrome(const Node* head) {
    const Node* front = head;
    const Node* rear = head;

    // �������� ��������� ������� �� �������
    while (rear != nullptr && rear->next != nullptr) {
        rear = rear->next;
    }

    while (front != rear && front != nullptr && rear != nullptr) {
        if (front->data != rear->data) {
            return false;
        }
        front = front->next;
        rear = rear->prev;
    }

    return true;
}

int main() {
    Node* head = nullptr;

    // ������� �� ���������� � ������������
    appendNode(head, 'A');
    appendNode(head, 'B');
    appendNode(head, 'A');
    std::cout << "������ 1: ";
    printList(head);
    std::cout << "� ���������: " << isPalindrome(head) << std::endl;
    std::cout << std::endl;

    Node* head2 = nullptr;
    appendNode(head2, 'A');
    appendNode(head2, 'B');
    appendNode(head2, 'C');
    appendNode(head2, 'B');
    appendNode(head2, 'A');
    std::cout << "������ 2: ";
    printList(head2);
    std::cout << "� ���������: " << isPalindrome(head2) << std::endl;

    return 0;
}
