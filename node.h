#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

class Graph;

using namespace std;

class Node {
	friend class Graph;
	private:
		Node (string x) : name(x), neighbors(NULL) {}
		string name;
		//int label;
		vector<Node*> neighbors; // adjacency list
};