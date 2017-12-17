#pragma once
#include "node.h"

class Graph;

class Bulletin {
	friend class Graph;
	private:
		Bulletin();
		void arrange();
		vector<Node*> courses;
};
