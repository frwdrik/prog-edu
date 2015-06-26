#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
using namespace std;


struct descendant {
	string name;
	double blood;
	pair<string, string> parents;
    };
string founder;

vector<string> contestants;
int M, N;

double getBloodValue (map<string, descendant>& desc_map, string name) {
    double blood_father = 0, blood_mother = 0;

    if (desc_map[name].parents.first == founder)
	blood_mother = 1;
    else if (desc_map.find(desc_map[name].parents.first) != desc_map.end())
	blood_mother = getBloodValue(desc_map, desc_map[name].parents.first);
    else
	blood_mother = 0;
    
    if (desc_map[name].parents.second == founder)
	blood_father = 1;
    else if (desc_map.find(desc_map[name].parents.second) != desc_map.end())
	blood_father = getBloodValue(desc_map, desc_map[name].parents.second);
    else
	blood_father = 0;
    
    return (blood_father + blood_mother) / 2;
    
}
int main()
{
    map <string, descendant> descendants;
    cin >> N >> M >> founder;

    string child, mother, father;
    for (int i = 0; i < N; i++) {
	cin >> child >> mother >> father;
	descendants[child].parents.first = mother;
	descendants[child].parents.second = father;
    }

    string contestant;
    for (int i = 0; i < M; i++) {
	cin >> contestant;
	contestants.push_back(contestant);
    }

    double  max_blood_value = 0, temp_blood_value = 0;
    string curr_contestant, contestant_with_highest_blood_level;
    for (int i = 0; i < M; i++) {
	curr_contestant = contestants[i];
	temp_blood_value = getBloodValue(descendants, curr_contestant);
	if (temp_blood_value > max_blood_value) {
	    max_blood_value = temp_blood_value;
	    contestant_with_highest_blood_level = curr_contestant;
	}
    }

    cout << contestant_with_highest_blood_level; 

    return 0;
}
    
