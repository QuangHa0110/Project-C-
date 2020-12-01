#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int value;
    Node *next;
} Node;

Node *head;

Node *createNode(int data)
{ // tạo một node mới
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = data;
    p->next = NULL;
    return p;
}
void printResult(Node *h)
{
    Node *t = h;
    if (h == NULL)
        printf("Danh sách rỗng");
    else
    {
        while (t->next != NULL)
        {
            printf("%d ", t->value);
            t = t->next;
        }
    }
}
Node *addFirst(Node *h, int data)
{                               // thêm 1 node vào đầu danh sách
    Node *p = createNode(data); // tạo mới 1 node
    if (h == NULL)
    { // nếu danh sách rỗng thì  p chính là phần tử đầu của danh sách
        h = p;
    }
    else
    {
        p->next = h;
        h = p;
    }
    return h;
}

Node *addLast(Node *h, int data)
{                               // thêm 1 node vào cuối danh sách
    Node *p = createNode(data); // tạo 1 node mới

    if (h == NULL)
    { // nếu danh sách rỗng thì node thêm vào chính là nốt đầu tiên
        h = p;
    }
    else
    {
        Node *t = h;
        while (t->next != NULL) // truy xuất đến phần tử cuối của danh sách
        {
            t = t->next;
        }
        t->next = p;
    }
    return h;
}

Node *addAt(Node *h, int data, int u) // thêm 1 node vào vị trí có value =u
{
    Node *p = createNode(data);
    if (h == NULL) // nếu danh sách rỗng thì thêm ngay ở đầu
    {
        h = p;
    }
    if (h->value == u) // nếu value của node đầu bằng u thì chèn ngay vào node đầu
    {
        p->next = h;
        h = p;
    }
    else //
    {
        Node *t = h;
        while (t->next->next != NULL && t->next->value != u) // duyệt xem node nào có giá trị bằng u
        {
            t = t->next;
        }
        p->next = t->next;
        t->next = p;
    }
    return h;
}
 
Node *deleteFirst(Node *h)  // xóa phần tử ở đầu danh sách
{
    if (h == NULL)
    {
        return NULL; // nếu danh sách rỗng thì không cần xóa
    }

    else
    {
        Node *p = h->next; // trỏ đến node thứ 2 của danh sách
        free(h);           // giải phóng bộ nhớ của node đầu tiên
        h = p;             // trỏ node đầu tiên tới node thứ 2
    }
    return h;
}

Node *deleteLast(Node*h){  // xóa node ở vị trí cuối cùng
    if(h==NULL){            // nếu danh sách rỗng thì không cần xóa
        return NULL;
    }
    else{
        Node* p=h;              
        while (p->next->next!=NULL)             // tìm vị trí đứng trước node cuối cùng trong danh sách
        {
            p=p->next;
        }
        free(p->next->next);                    // giải phóng bộ nhớ của phần tử cuối cùng.
        p->next=NULL;                           // gán node gần cuối của  danh sách thành node cuối luôn
      
         return h;
    }
   
}

Node* deleteAt(Node *h, int position){
    if(h==NULL){
        return NULL;
    }
    else{
        int count=0;
        Node *p= h;
        while(p->next->next!=NULL&& count!=position){
            p=p->next;
            count++;
        }
        

    }
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        head = addLast(head, i);
    }
    head = addAt(head, 100, 3);
  //  head = deleteLast(head);
    // head=deleteFirst(head); 
    printResult(head);
    return 0;
}