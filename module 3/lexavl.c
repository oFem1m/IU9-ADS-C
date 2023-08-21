#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int max(int x, int y) {
    return x > y ? x : y;
}

// self-written avl
typedef struct Node Node;

struct Node {
    int key;
    int value;
    Node *l;
    Node *r;
    int height;
};

Node *makeNode(int key, int value) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->l = 0;
    node->r = 0;
    node->key = key;
    node->value = value;
    node->height = 1;
    return node;
}

void freeNode(Node *node) {
    if (node->l)
        freeNode(node->l);
    if (node->r)
        freeNode(node->r);
    free(node);
}

int height(Node *node) {
    if (node == 0)
        return 0;
    return node->height;
}

int getBalance(Node *node) {
    if (node == 0)
        return 0;
    return height(node->l) - height(node->r);
}

bool contains(int key, Node *node) {
    if (key < node->key) {
        if (!node->l)
            return false;
        return contains(key, node->l);
    } else if (key > node->key) {
        if (!node->r)
            return false;
        return contains(key, node->r);
    } else {
        return true;
    }
}

int get(int key, Node *node) {
    if (key < node->key) {
        return get(key, node->l);
    } else if (key > node->key) {
        return get(key, node->r);
    } else {
        return node->value;
    }
}

Node *rightRotate(Node *y) {
    Node *x = y->l;
    Node *z = x->r;

    x->r = y;
    y->l = z;

    y->height = max(height(y->l), height(y->r)) + 1;
    x->height = max(height(x->l), height(x->r)) + 1;

    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->r;
    Node *z = y->l;

    y->l = x;
    x->r = z;

    x->height = max(height(x->l), height(x->r)) + 1;
    y->height = max(height(y->l), height(y->r)) + 1;

    return y;
}

Node *insert(int key, int value, Node *node) {
    if (node == 0)
        return makeNode(key, value);

    if (key < node->key)
        node->l = insert(key, value, node->l);
    else if (key > node->key)
        node->r = insert(key, value, node->r);
    else
        return node;


    node->height = max(height(node->l), height(node->r)) + 1;
    int x = getBalance(node);
    if (x > 1 && key < node->l->key)
        return rightRotate(node);

    if (x < -1 && key > node->r->key)
        return leftRotate(node);

    if (x > 1 && key > node->l->key) {
        node->l = leftRotate(node->l);
        return rightRotate(node);
    }

    if (x < -1 && key < node->r->key) {
        node->r = rightRotate(node->r);
        return leftRotate(node);
    }
    return node;
}
// endof self-written avl

typedef struct Reader {
    bool closed;
    char c;
} Reader;

bool closed(Reader *reader) {
    return reader->closed;
}

char peek(Reader *reader) {
    return reader->c;
}

void next(Reader *reader) {
    int c;
    if ((c = getchar()) == EOF) {
        reader->closed = true;
        return;
    }
    reader->c = (char) c;
}

void parse_const(Reader *in) {
    printf("CONST ");
    while (!closed(in) && '0' <= peek(in) && peek(in) <= '9') {
        printf("%c", peek(in));
        next(in);
    }
    printf("\n");
}

#define HASH_P   277
#define HASH_MOD 1870010071

bool canBeInIdent(char c) {
    if ('0' <= c && c <= '9')
        return true;
    if ('a' <= c && c <= 'z')
        return true;
    if ('A' <= c && c <= 'Z')
        return true;
    return false;
}

void parse_ident(Reader *in) {
    static Node *root;
    if (root == 0)
        root = makeNode(-1, -1);
    static int k = 0;
    int hash = 0;
    while (!closed(in) && canBeInIdent(peek(in))) {
        unsigned int c = peek(in);
        next(in);
        hash = 1LL * hash * HASH_P + c;
    }
    int value;
    if (contains(hash, root)) {
        value = get(hash, root);
    } else {
        root = insert(hash, value = k++, root);
    }
    printf("IDENT %d\n", value);
}

void parse_spec(Reader *in) {
    char c = peek(in);
    next(in);

    int val;
    switch (c) {
        case '+':
            val = 0;
            break;
        case '-':
            val = 1;
            break;
        case '*':
            val = 2;
            break;
        case '/':
            val = 3;
            break;
        case '(':
            val = 4;
            break;
        case ')':
            val = 5;
            break;
        default:
            return;
    }
    printf("SPEC %d\n", val);
}

void parse(Reader *in) {
    if ('0' <= peek(in) && peek(in) <= '9') {
        parse_const(in);
        return;
    }
    if (('a' <= peek(in) && peek(in) <= 'z') || ('A' <= peek(in) && peek(in) <= 'Z')) {
        parse_ident(in);
        return;
    }
    parse_spec(in);
}

int main() {
    int t;
    scanf("%d", &t);
    Reader reader;
    reader.closed = false;
    next(&reader);
    while (!closed(&reader)) {
        parse(&reader);
    }
    return 0;
}