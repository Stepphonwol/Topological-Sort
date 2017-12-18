## Topological Sort
---
### 实验的目的和要求
1. 采用C++实现
2. 熟练掌握图的应用
3. 熟练掌握图的邻接表存储结构以及拓扑排序的基本思想
---
### 实验环境
- Windows 10
- Visual Studio 2017
---
### 算法描述
- **图中结点的表示**
    - 一个string变量表示课程名
    - 一个vector变量表示邻接表
    - 一个int变量表示该课程是否必须在某个学期修读
    ```
    class Node {
	friend class Graph;
	friend class Bulletin;
	private:
		Node (string x, int n) : name(x), semester(n), neighbors(NULL) {}
		string name;
		int semester;
		vector<Node*> neighbors; // adjacency list
    };
    ```
- **拓扑排序的实现**
    - 使用一个unordered_map记录每个结点的**入度**
    - 使用另一个unordered_map记录每个结点是否被访问过
    - 遍历图，计算每个结点的**入度**
    - 将**入度为零**的结点推入一个队列
    - 遍历图，将必须在该学期修读的课程推入该学期的课表中，并标记为已访问（**该步必须在进行队列操作之前进行**）
    - 推出队列顶部的结点 
    - 若没有学期限制，且该学期还有课余量，将其推入该学期课表中，并标记其为已访问
    - 将该结点**邻接结点的所有入度都减一**
    - 将**入度为零的课程**推入队列
    - 若该学期课程已满，则开始排下一学期的课表 （**一直到队列为空为止**）
    ```
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
                    // push the course into the corresponding table
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
    ```
---
### 源程序清单
- Bulletin.h + Bulletin.cpp
- graph.h + graph.cpp
- node.h
- main.cpp
---
### 运行结果
![](TOPSORT.PNG)
- 八行分别对应八个学期
- 总共有28门课
---
### 实验运行情况分析
- 计算每个结点入度的过程中，图的每个结点与每条边都会被访问到。
- 在拓扑排序的初始化过程中，需要遍历两次结点集。
- 在拓扑排序的过程中，需要首先遍历一次结点集，以保证必须在该学期修读的课程不会被其他课程挤掉
- 综上，若图的总结点数为V，总边数为E，则该算法的时间复杂度为：O（3V + E）




