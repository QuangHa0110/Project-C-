#include <stdio.h>
typedef struct Node
{ // Tạo một struct
    int value;
    Node *next;
} Node;

Node *makeNode(int data)
{ // Tạo một node mới trong Stack
    Node *p = new Node();
    p->value = data;
    p->next = NULL;
    return p;
}

bool isEmpty(Node *st)
{ // Kiểm tra xem Stack có rỗng hay không ?
    return st == NULL;
}

Node *push(Node *st, int data)
{ // Thêm phần tử vào trong Stack
    Node *p = makeNode(data);
    if (isEmpty(st))
    {
        st = p;
    }
    else
    {
        p->next = st;
        st = p;
    }
    return st;
}
Node *pop(Node *st)
{ // xóa bỏ phần tử đầu tiên của Stack, số phần tử của Stack giảm đi 1
    if (isEmpty(st))
        return NULL;
    else
    {
        Node *p = st->next;
        st = p;
    }
    return st;
}

int top(Node *st)
{ // Lấy ra phần tử đầu tiên của Stack
    if (isEmpty(st))
        return NULL;
    else
    {
        int rs = st->value;
        pop(st);
        return rs;
    }
}
int sizeOfStack(Node *st)
{ // lấy ra số phần tử trong Stack
    if (isEmpty(st))
        return 0;
    else
        return sizeOfStack(st->next) + 1;
}
void printStack(Node *st)
{ // In ra danh sách các phần tử trong Stack
    if (isEmpty(st))
        return;
    else
    {
        printf("%d-", st->value);
        printStack(st->next);
    }
}
int main()
{
    Node *st = NULL;
    st = push(st, 1);
    st = push(st, 2);
    st = push(st, 3);
    st = push(st, 4);
    st = push(st, 5);
    st = push(st, 6);
    st = push(st, 7);
    st = push(st, 10);
    st = push(st, 9);
    st = pop(st);
    printStack(st);
    printf("\n%d", top(st));
    printf("\n%d", sizeOfStack(st));
    return 0;
}