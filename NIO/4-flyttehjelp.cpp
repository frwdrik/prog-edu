#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int find_max(vector<vector<int> >& roads, int node,
	     int prev_node, int cur_len, vector<vector<int> >& results);

int main()
{
    int num_corners;
    cin >> num_corners;
    // roads holds one vector for each node which describes
    // which nodes it is connected to.
    vector<vector<int> > roads(num_corners);
    // results holds previously stored information about
    // the length of each node in a certain direction
    vector<vector<int> > results(num_corners, vector<int>(num_corners));

    for (int i = 0; i < num_corners; i++)
	for (int j = 0; j < num_corners; j++)
	    results[i][j] = 0;
    
    // Store roads between two vectors in each
    // node's corresponding vector.
    int n1, n2;
    for (int cnt = 0; cnt < num_corners - 1; cnt++) {
	cin >> n1 >> n2;
	roads[n1].push_back(n2);
	roads[n2].push_back(n1);
    }    
    // Calculate the longest path for each node
    int min = INT_MAX, result, node_ptr = 0;
    for (int i = 0; i < num_corners; i++) {
    	result = find_max(roads, i, -1, 0, results); 
    	if (result < min) {
    	    min = result;
    	    node_ptr = i;
    	}
    }
    
    cout << node_ptr;
    
    return 0;
}

int find_max(vector<vector<int> >& roads, int node,
	     int prev_node, int cur_len, vector<vector<int> >& results)
{
    int length = 0, temp = -1, next_node;
    for (int i = 0; i < roads[node].size(); i++) {
	next_node = roads[node][i];
	if (next_node != prev_node) {
	    if (results[node][next_node])
		temp = results[node][next_node];
	    else {
		temp = 1 + find_max(roads, next_node, node, cur_len + 1, results);
		results[node][next_node] = temp;
	    }
	    if (temp > length)
		length = temp;
	}
    }
    
    return length;
}

