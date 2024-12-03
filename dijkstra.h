#include <bits/stdc++.h>
using namespace std;

 class dijkstra{


int NO_PARENT = -1;


void showPath(int currentVertex, vector<int> parents)
{

	
	if (currentVertex == NO_PARENT) {
		return;
	}
	showPath(parents[currentVertex], parents);
	cout << currentVertex << " ";
}


void printAnalysis(int startVertex, vector<int> distances,
				vector<int> parents)
{
	int nVertices = distances.size();
	cout << "Vertex\t Distance\tPath";

	for (int vertexIndex = 0; vertexIndex < nVertices;
		vertexIndex++) {
		if (vertexIndex != startVertex) {
			cout << "\n" << startVertex << " -> ";
			cout << vertexIndex << " \t\t ";
			cout << distances[vertexIndex] << "\t\t";
			showPath(vertexIndex, parents);
		}
	}
}



public:
 void execute(vector<vector<int> > adjacencyMatrix,
			int startVertex)
{
	int nVertices = adjacencyMatrix[0].size();

	
	vector<int> shortestDistances(nVertices);

	
	vector<bool> added(nVertices);


	for (int vertexIndex = 0; vertexIndex < nVertices;
		vertexIndex++) {
		shortestDistances[vertexIndex] = INT_MAX;
		added[vertexIndex] = false;
	}

	
	shortestDistances[startVertex] = 0;

	
	vector<int> parents(nVertices);


	parents[startVertex] = NO_PARENT;

	for (int i = 1; i < nVertices; i++) {

	
		int nearestVertex = -1;
		int shortestDistance = INT_MAX;
		for (int vertexIndex = 0; vertexIndex < nVertices;
			vertexIndex++) {
			if (!added[vertexIndex]
				&& shortestDistances[vertexIndex]
					< shortestDistance) {
				nearestVertex = vertexIndex;
				shortestDistance
					= shortestDistances[vertexIndex];
			}
		}

		
		added[nearestVertex] = true;

		
		for (int vertexIndex = 0; vertexIndex < nVertices;
			vertexIndex++) {
			int edgeDistance
				= adjacencyMatrix[nearestVertex]
								[vertexIndex];

			if (edgeDistance > 0
				&& ((shortestDistance + edgeDistance)
					< shortestDistances[vertexIndex])) {
				parents[vertexIndex] = nearestVertex;
				shortestDistances[vertexIndex]
					= shortestDistance + edgeDistance;
			}
		}
	}

	printAnalysis(startVertex, shortestDistances, parents);
}


};
