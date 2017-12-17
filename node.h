#pragma once
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

class Graph;
class Bulletin;

using namespace std;

class Node {
	friend class Graph;
	friend class Bulletin;
	private:
		Node (string x) : name(x), neighbors(NULL) {}
		string name;
		//int label;
		vector<Node*> neighbors; // adjacency list
};
#endif