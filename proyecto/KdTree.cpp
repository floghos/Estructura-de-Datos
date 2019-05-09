#include "KdTree.h"
#include <bits/stdc++.h>

using namespace std;

KdTree::KdTree() {
    root = NULL;
}

void KdTree::sort(vector<pair<int, int> > * v, int axis) {
    for (int i = 1; i < v->size(); ++i) {
        int j = i;
        pair<int, int> aux;
        if (axis) {//eje y
            while (v[j].second < v[j-1].second) {
                swap(&v[j], &v[j-1]);
                j--;
                if (j == 0) break;
            }
        } else { //equivale a: axis == 0 (eje x
            while (v[j].first < v[j-1].first) {
                swap(&v[j], &v[j-1]);
                j--;
                if (j == 0) break;
            }
        }
    }
}

void KdTree::swap(pair<int, int> *a, pair<int, int> *b) {
    //queremos cambiar los contenidos de a con los de b, no las direcciones de memoria
    pair<int, int> aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void KdTree::construir(vector<pair<int, int> > v) {
    sort(&v, 0);
    int median = (v.size() - 1) / 2;

    vector<pair<int, int> > l;
    for (int i = 0; i <= median; ++i) {
        l.push_back(v[i]);
    }

    vector<pair<int, int> > r;
    for (int i = median+1; i < v.size(); ++i) {
        r.push_back(v[i]);
    }

    root = new node();
    root->x = v[median].first;
    root->y = -1;
    root->left = construir(l, 1);
    root->right = construir(r, 1);
}

node * KdTree::construir(vector<pair<int, int> > v, int depth) {
    int axis = depth % 2; //0, 1 dependiendo si es par o impar (0 = x, 1 = y)
    sort(v, axis); //ordenamos respecto a axis

    int median = (v.size() - 1) / 2;

    if (v->size() > 1) {
        vector<pair<int, int> > l; //mitad izquierda
        for (int i = 0; i <= median; ++i) {
            l.push_back(v[i]);
        }

        vector<pair<int, int> > r; //mitad derecha
        for (int i = median+1; i < v.size(); ++i) {
            r.push_back(v[i]);
        }

        node nuevoNodo = new node();
        if (axis) { //division en eje y
            nuevoNodo->y = v[median].second;
            nuevoNodo->x = -1;
        } else { //division en eje x
            nuevoNodo->x = v[median].first;
            nuevoNodo->y = -1;
        }

        nuevoNodo->left = construir(l, depth+1);
        nuevoNodo->right = construir(r, depth+1);

        return nuevoNodo;
    } else {
        node nuevoNodo = new node();
        nuevoNodo->x = v->first;
        nuevoNodo->y = v->second;
    }

}


vector<point> KdTree::buscar(int x1, int y1, int x2, int y2) {

}
