#pragma once
#include "Define.h"
#include <iostream>
#include <string>
using namespace std;
struct Node{
	string name;
	int x, y;
	Node();
    Node(string name, int x, int y);
};
Node::Node() {
	name = ""; x = y = 0;
}
Node::Node(string name, int x, int y) {
	this->name = name;
	this->x = x;
	this->y = y;
}
struct Button{
	string name;
	int x1, y1, x2, y2;
};
struct Graph{
	int numberNode;
	int adj[MAXN][MAXN], type[MAXN][MAXN];
	Node *node[MAXN];
	Graph();
	~Graph();
};
Graph::Graph() {
	numberNode = 0;
	for(int i = 0; i < MAXN; ++i){
		node[i] = NULL;
		for(int j = 0; j < MAXN; ++j){
			adj[i][j] = 0;
			type[i][j] = 0;
		}
	}
}
Graph::~Graph() { }