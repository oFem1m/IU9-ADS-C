#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct Node Node;
typedef struct HashTable HashTable;

struct Node {
    Node *next;
    int key;
    int val;
};

struct HashTable {
    int m;
    Node **h;
};

Node *make_node() {
    Node *node = (Node *) malloc(sizeof(Node));
    node->next = 0;
    return node;
}

void free_node(Node *node) {
    if (node == 0)
        return;
    free_node(node->next);
    free(node);
}

void set(HashTable *map, int i, int x) {
    int key = i;
    i %= map->m;
    if (!(map->h[i])) {
        map->h[i] = make_node();
        map->h[i]->key = -1;
    }
    Node *node = map->h[i];
    while (node->next) {
        if (node->key == key) {
            node->val = x;
            return;
        }
        node = node->next;
    }
    node->next = make_node();
    node->key = key;
    node->val = x;
}

int get(HashTable *map, int i) {
    int key = i;
    i %= map->m;
    if (!(map->h[i])) {
        map->h[i] = make_node();
        map->h[i]->key = -1;
    }
    Node *node = map->h[i];
    while (node->next) {
        if (node->key == key) {
            return node->val;
        }
        node = node->next;
    }
    return 0;
}

int main() {
    int m;
    scanf("%d", &m);
    HashTable map;
    map.m = m;
    map.h = (Node **) malloc(sizeof(Node *) * m);
    memset(map.h, 0, sizeof(Node *) * m);

    char s[10];
    while (1) {
        scanf("%s", s);
        if (s[1] == 'S') {
            int i, v;
            scanf("%d %d", &i, &v);
            set(&map, i, v);
        }
        if (s[1] == 'T') {
            int i;
            scanf("%d", &i);
            int ans = get(&map, i);
            printf("%d\n", ans);
        }
        if (s[1] == 'N') {
            break;
        }
    }
    for (int i = 0; i < m; ++i) {
        free_node(map.h[i]);
    }
    free(map.h);
    return 0;
}