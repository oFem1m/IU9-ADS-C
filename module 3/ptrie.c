#include <stdio.h>
#include <stdlib.h>

const int maxk = 100500;

typedef struct Node Node;

struct Node {
    Node *next[26];
    int v;
    int t;
};

void initNode(Node *node) {
    node->v = 0;
    node->t = 0;
    for (int i = 0; i < 26; ++i) {
        node->next[i] = 0;
    }
}

int insert(Node *cur, char *begin) {
    if (*begin == 0) {
        if (cur->t == 0) {
            cur->v++;
            cur->t = 1;
            return 1;
        }
        return 0;
    }
    int c = *begin - 'a';
    if (!cur->next[c]) {
        cur->next[c] = (Node *) malloc(sizeof(Node));
        initNode(cur->next[c]);
    }
    int f = insert(cur->next[c], begin + 1);
    cur->v += f;
    return f;
}

int prefix(Node *root, char *begin) {
    Node *cur = root;
    for (; *begin != 0; ++begin) {
        int c = *begin - 'a';
        if (!cur->next[c])
            return 0;
        cur = cur->next[c];
    }
    return cur->v;
}

int delete(Node *cur, char *begin) {
    if (*begin == 0) {
        cur->t = 0;
        if (cur->t == 0) {
            cur->v--;
            return 1;
        }
        return 0;
    }
    int c = *begin - 'a';
    int f = delete(cur->next[c], begin + 1);
    cur->v -= f;
    return f;
}

void free_node(Node *v) {
    for (int i = 0; i < 26; ++i) {
        if (v->next[i])
            free_node(v->next[i]);
    }
    free(v);
}

int main() {
    Node *root = (Node *) malloc(sizeof(Node));
    initNode(root);

    char c[10];
    char s[maxk];
    while (1) {
        scanf("%s", c);
        scanf("%s", s);
        if (c[0] == 'I') {
            insert(root, s);
        }
        if (c[0] == 'P') {
            int ans = prefix(root, s);
            printf("%d ", ans);
        }
        if (c[0] == 'D') {
            delete(root, s);
        }
        if (c[0] == 'E') {
            break;
        }
    }
    free_node(root);
    return 0;
}