// A simple representation of graph using STL
#include <iostream>
#include <vector>
#include <limits>
#include <set>
#define NumOfVertex 4
using namespace std;

class Point
{

public:
	Point()
	{
		this->id = 0;
		this->x = 0;
		this->y = 0;
	}
	Point(int id, int x, int y)
	{
		this->id = id;
		this->x = x;
		this->y = y;
	}
	int id;
	int x;
	int y;
	friend ostream &operator<<(ostream &os, const Point &pt);
};

ostream &operator<<(ostream &os, const Point &pt)
{
	os << '(' << pt.x << ',' << pt.y << ')';
	return os;
}

class Edge
{
public:
	Edge()
	{
		this->p1 = 0;
		this->p2 = 0;
		this->weight = 0;
	}
	Edge(int p1, int p2, int weight)
	{
		this->p1 = p1;
		this->p2 = p2;
		this->weight = weight;
	}
	int p1;		// id of p1;
	int p2;		// id of p2;
	int weight; // weight of p1 and p2;
	friend ostream &operator<<(ostream &os, const Edge &edge);
};

ostream &operator<<(ostream &os, Edge &edge)
{
	os << edge.p1 << '\t' << edge.p2 << '\t' << edge.weight;
	return os;
}

// To add an edge
void addEdge(vector<pair<int, int>> adj[], int u,
			 int v, int wt)
{
	adj[u].push_back(make_pair(v, wt));
	adj[v].push_back(make_pair(u, wt));
}

// Print adjacency list representation ot graph
void printGraph(vector<pair<int, int>> adj[], int V, vector<Point> &pointList)
{
	int v, w;
	for (int u = 0; u < V; u++)
	{
		cout << "Node " << u << "(" << pointList[u].x << " , " << pointList[u].y << ")"
			 << " makes an edge with \n";
		for (auto it = adj[u].begin(); it != adj[u].end(); it++)
		{
			v = it->first;
			w = it->second;
			cout << "\tNode " << v << "(" << pointList[v].x << " , " << pointList[v].y << ")"
																						  " with edge weight ="
				 << w << "\n";
		}
		cout << "\n";
	}
}

int calculateWeightBetweenNodes(Point &p1, Point &p2)
{
	int weights = 0;
	weights = abs(p1.x - p2.x) + abs(p1.y - p2.y);
	return weights;
}

void reportEdges(vector<Point> &pointList, vector<Edge> &edgeList)
{
	cout << "Report Edges: " << endl;
	for (int i = 0; i < edgeList.size(); i++)
	{
		cout << pointList[edgeList[i].p1] << "\t" << pointList[edgeList[i].p2] << "\t" << edgeList[i].weight << endl;
	}
	cout << endl
		 << endl;
}

void kruskal(vector<pair<int, int>> adj[], vector<Point> pointList, vector<Edge> edgeList);
// Driver code
int main()
{
	vector<pair<int, int>> adj[NumOfVertex];
	vector<Point> pointList;
	vector<Edge> edgeList;
	pointList.push_back(Point(0, 1, 25)); // id,x,y
	pointList.push_back(Point(1, 6, 18));
	pointList.push_back(Point(2, 30, 5));
	pointList.push_back(Point(3, 15, 20));

	// create a complete graph.
	for (int i = 0; i < NumOfVertex; i++)
	{
		for (int j = i + 1; j < NumOfVertex; j++)
		{
			int tmpWeight = calculateWeightBetweenNodes(pointList[i], pointList[j]);
			edgeList.push_back(Edge(pointList[i].id, pointList[j].id, tmpWeight));
			addEdge(adj, pointList[i].id, pointList[j].id, tmpWeight);
			cout << "(" << i << "," << j << ")\t";
		}
		cout << endl;
	}
	printGraph(adj, NumOfVertex, pointList);
	reportEdges(pointList, edgeList);
	kruskal(adj, pointList, edgeList);

	return 0;
}

void kruskal(vector<pair<int, int>> adj[], vector<Point> pointList, vector<Edge> edgeList)
{
	cout << "Kruskal: " << endl;
	// initialize of the kruskal algorithm
	vector<Edge> tmpEdgeList = edgeList;
	set<int> vNew{};
	set<int> edgeNew{};
	int sum = 0;
	// find min weight in E (edges)
	while (vNew.size() < NumOfVertex)
	{
		int minWeight = std::numeric_limits<int>::max();
		int minIndex = -1;
		for (int i = 0; i < tmpEdgeList.size(); i++)
		{
			if (tmpEdgeList[i].weight < minWeight)
			{
				minWeight = tmpEdgeList[i].weight;
				minIndex = i;
			}
		}
		cout << "Choose Edge:" << tmpEdgeList[minIndex] << endl;
		if (vNew.count(tmpEdgeList[minIndex].p1) == 0 || vNew.count(tmpEdgeList[minIndex].p2) == 0)
		{
			// add them into MST.
			if (edgeNew.count(minIndex) == 0)
			{
				edgeNew.insert(minIndex);
				sum += tmpEdgeList[minIndex].weight;
			}
			else
			{
				cerr << "error in add edge" << endl;
			}
			vNew.insert(tmpEdgeList[minIndex].p1);
			vNew.insert(tmpEdgeList[minIndex].p2);
		}
		else if (vNew.count(tmpEdgeList[minIndex].p1) == 1 && vNew.count(tmpEdgeList[minIndex].p2) == 1)
		{
			cout << "Edge \t" << tmpEdgeList[minIndex] << "\tcan not be add into MST!!!" << endl;
		}
		// both of them are in the vertex list
		// delete this edge in edgeList
		vector<Edge>::iterator it = tmpEdgeList.begin();
		tmpEdgeList.erase(it + minIndex);
	}
	cout << "The total wirelength of Minimum Rectilinear Spanning Tree is:" << sum << endl;
}
