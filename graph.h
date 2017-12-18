#pragma once
#include "node.h"
#include "Bulletin.h"

class Graph {
	public:
		Graph();
		void topological_sort();
	private:
		void init_board();
		void init_vertices();
		//void init_edges();
		//void addEdge(int v, int w);
		fstream in;
		//fstream out;
		int V; // number of vertices
		int E; // number of edges
		vector<int> cnt; // number of courses for each semester
		vector<Node*> cont; // container of classes
};