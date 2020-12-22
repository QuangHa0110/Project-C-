#include <bits/stdc++.h>
#include <string.h>
char dictionary[1000000][100];
int N;
typedef struct Node
{
    char *english;
    char *vietname;
    Node *leftChild;
    Node *rightChild;
} Node;
Node *root;
Node *makeNode(char *data)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->english = data;
    p->vietname = NULL;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

void input()
{
    FILE *fptr = fopen("words.txt", "r");
    N = 0;

    while (!feof(fptr))
    {

        fscanf(fptr, "%s", dictionary[N]);
        strlwr(dictionary[N]);
        N++;
    }

    fclose(fptr);
}
void swap(char *a, char *b)
{
    char *tmp = a;
    a = b;
    b = tmp;
}
int partition(int l, int r, int index)
{
    char *pivot = dictionary[index];
    swap(dictionary[index], dictionary[r]);
    int stonesIndex = l;
    for (int i = l; i < r; i++)
    {
        if (strcmp(dictionary[i], pivot) < 0)
        {
            swap(dictionary[i], dictionary[stonesIndex]);
            stonesIndex++;
        }
    }
    swap(dictionary[stonesIndex], dictionary[r]);
    return stonesIndex;
}
void quicksort(int l, int r)
{
    int index = (l + r) / 2;
    index = partition(l, r, index);
    if (l < index)
    {
        quicksort(l, index);
    }
    if (index < r)
    {
        quicksort(index + 1, r);
    }
}
Node *makeBST(int l, int r)
{
    if (l > r)
        return NULL;
    if (l == r)
        return makeNode(dictionary[l]);
    int m = (l + r) / 2;
    Node *root = makeNode(dictionary[m]);
    root->leftChild = makeBST(l, m - 1);
    root->rightChild = makeBST(m + 1, r);
    return root;
}
int height(Node *r)
{
    if (r == NULL)
        return 0;
    int ml = height(r->leftChild);
    int mr = height(r->rightChild);
    if (ml > mr)
        return ml + 1;
    else
        return mr + 1;
}
void preOrder(Node *r)
{
    if (r == NULL)
        return;
    printf("%s\n", r->english);
    preOrder(r->leftChild);
    preOrder(r->rightChild);
}
Node *find(Node *r, char *w)
{
    if (r == NULL)
        return NULL;
    int c = strcmp(r->english, w);
    if (c == 0)
        return r;
    else if (c < 0)
        return find(r->rightChild, w);
    else
        return find(r->leftChild, w);
}

void freeTree(Node *r)
{
    if (r == NULL)
        return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    // free(r->vietname);
    free(r);
}
void finalize()
{
    // giai phong bo nho
    freeTree(root);
}
int main()
{
    input();
    quicksort(0, N - 1);
    root = makeBST(0, N - 1);

    // char  s[6]= "aah";
    // if(find(root, s)!=NULL) printf("thanhf coong");
    // else printf("That bai");

    while (1)
    {
        char cmd[60];
        printf("Enter a word: ");
        scanf("%s", cmd);
        fflush(stdin);
        if (strcmp(cmd, "find") == 0)
        {
            char word[100];
            printf("English: ");
            scanf("%s", word);
            Node *p = find(root, word);
            if (p == NULL)
                printf("Not found\n");
            else
            {
                printf("Found %s -> %s\n", p->english, p->vietname);
            }
        }
        if (strcmp(cmd, "set") == 0)
        {
            char word[100];
            printf("English: ");
            scanf("%s", word);
            fflush(stdin);
            char *vn = (char *)malloc(100);
            printf("Vietnamese: ");
            gets(vn);
            fflush(stdin);
            Node *p = find(root, word);
            if (p == NULL)
            {
                printf("Not found\n");
            }
            else
            {
                p->vietname = vn;
            }
        }
        else if (strcmp(cmd, "quit") == 0)
        {
            break;
        }
    }
    finalize();
    return 0;
}