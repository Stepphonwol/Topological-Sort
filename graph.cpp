#include "graph.h"

Graph::Graph()
{
	V = 0;
	E = 0;
	string input_name;
	cout << "Input text name: " << endl;
	cin >> input_name;
	in.open(input_name, fstream::in);
	/*string output_name;
	cout << "Output text name: " << endl;
	cin >> output_name;
	out.open(output_name, fstream::out);*/
	init_board();
	init_vertices();
	//init_edges();
}

void Graph::init_board()
{
	int x1, x2, x3, x4, x5, x6, x7, x8;
	in >> x1 >> x2 >> x3 >> x4 >> x5 >> x6 >> x7 >> x8;
	cnt.push_back(0);
	cnt.push_back(x1);
	cnt.push_back(x2);
	cnt.push_back(x3);
	cnt.push_back(x4);
	cnt.push_back(x5);
	cnt.push_back(x6);
	cnt.push_back(x7);
	cnt.push_back(x8);
	V = x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8;
}

void Graph::init_vertices()
{
	Node* dummy = new Node(" ", 0);
	cont.push_back(dummy);
	in.get();
	for (int i = 0; i < V; ++i) {
		if (in.eof()) {
			break;
		}
		string temp_name;
		int temp_semester, temp_preliminary;
		in >> temp_name;
		in >> temp_semester;
		in >> temp_preliminary;
		Node* temp_node = new Node(temp_name, temp_semester);
		cont.push_back(temp_node);
		if (temp_preliminary != 0) {
			cont[temp_preliminary]->neighbors.push_back(temp_node);
		}
	}
}

/*void Graph::init_edges()
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
}*/

void Graph::topological_sort()
{
	Bulletin b;
	queue<Node*> q;
	unordered_map<Node*, int> mp; // stores in-degrees for each course
	unordered_map<Node*, bool> mark; // true : visited; false : not visited
	for (auto it = cont.begin() + 1; it != cont.end(); ++it) {
		Node* temp = *it;
		mp[temp] = 0;
		mark[temp] = false;
	} // initialize map
	for (auto it = cont.begin() + 1; it != cont.end(); ++it) {
		Node* temp = *it;
		for (auto jt = temp->neighbors.begin(); jt != temp->neighbors.end(); ++jt) {
			Node* inner = *jt;
			++mp[inner];
		}
	} // initialize map
	for (auto it = cont.begin() + 1; it != cont.end(); ++it) {
		Node* temp = *it;
		if (mp[temp] == 0) {
			q.push(temp);
		}
	} // initialize queue
	for (int i = 1;  i <= 8; ++i) {
		for (auto it = cont.begin() + 1; it != cont.end(); ++it) {
			Node* temp = *it;
			if (temp->semester == i) {
				b.courses.push_back(temp);
				mark[temp] = true;
			}
		} // arrange the courses which must be learned during this semester first
		while (!q.empty()) {
			Node* temp = q.front();
			q.pop();
			if (mark[temp] == true) {
				continue;
			}
			if (temp->semester == i) {
				b.courses.push_back(temp);
				mark[temp] = true;
			}
			else if (temp->semester == 0) { // no restrictions on semester
				b.courses.push_back(temp);
				mark[temp] = true;
			}
			for (auto jt = temp->neighbors.begin(); jt != temp->neighbors.end(); ++jt) {
				Node* inner = *jt;
				--mp[inner];
				if (mp[inner] == 0) {
					q.push(inner);
				}
			}
			if (b.courses.size() >= cnt[i]) {
				break;
			}
		}
		b.arrange();
		b.courses.clear();
	}
}