#include "graph.h"

Graph::Graph()
{
	V = 0;
	E = 0;
	string input_name;
	cout << "Input text name: " << endl;
	cin >> input_name;
	in.open(input_name, fstream::in);
	string output_name;
	cout << "Output text name: " << endl;
	cin >> output_name;
	out.open(output_name, fstream::out);
	init_vertices();
	init_edges();
}

void Graph::init_vertices()
{
	Node* dummy = new Node(" ");
	cont.push_back(dummy);
	cout << "Input the number of courses: " << endl;
	int n{ 0 }; // number of courses
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string temp_name;
		getline(in, temp_name);
		Node* temp_node = new Node(temp_name);
		cont.push_back(temp_node);
		++V;
	}
}

void Graph::init_edges()
{
	while (1) {
		int v, w;
		in >> v >> w;
		addEdge(v, w);
		if (in.eof()) {
			break;
		}
	}
}

void Graph::addEdge(int v, int w)
{
	cont[v]->neighbors.push_back(cont[w]);
	++E;
}

void Graph::topological_sort()
{

}