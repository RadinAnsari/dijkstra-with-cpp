#include <bits/stdc++.h>
#include "dijkstra.h"

using namespace std;



int main()
{
	vector<vector<int> > data
		= { { 0, 10, 3, 0, 0 },
			{ 10, 0, 4, 2, 0 },
			{ 3, 4, 0, 8, 2  },
			{ 0, 2, 8, 0, 5 },
			{ 0, 0, 2, 5, 0 } };
      
  dijkstra dijkstra;
	dijkstra.execute(data, 1);
	return 0;
}
