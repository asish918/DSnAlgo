#include <iostream>
using namespace std;

int main(){
    int no_of_vertices = 5;

    int total_edges = no_of_vertices * (no_of_vertices-1) / 2;

    cout << (1<<total_edges);
    
    return 0;
}
