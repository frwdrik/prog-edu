#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;


int main()
{
    vector< queue<int> > buff(10);
    
    for(int i = 0; i < 10; i++)
	for(int j = 0; j < 10; j++ ){
	int y = 4 ; //gen random num to test operability
	buff[i].push(y);
    }

    int i = 0;
    while(i < 20 && !(buff[1].empty())) {
	cout << buff[1].front();
	buff[1].pop();
	i++;
    }

    cout << endl << buff[1].front() << endl;
    return 0;
}

