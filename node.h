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
		Node (string x, int n) : name(x), semester(n), neighbors(NULL) {}
		string name;
		int semester;
		vector<Node*> neighbors; // adjacency list
};
#endif