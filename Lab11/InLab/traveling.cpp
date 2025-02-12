/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date: 4/25/20
	File Name:traveling.cpp
*/



#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.cpp"

float computeDistance(MiddleEarth me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);


    
    // TODO: YOUR CODE HERE

    //First calculate minimum distance of originial permutation
    float originDistance = computeDistance(me, dests[0], dests);
    float minDistance = 0;
    minDistance = originDistance;

    //Sort destination vector
    sort(dests.begin()+1, dests.end());

    //Now go through each permutation and find the shortest one
    while(next_permutation(dests.begin()+1, dests.end())){
      float nextDistance = computeDistance(me, dests[0], dests);

      if(nextDistance < minDistance){
	minDistance = nextDistance;
      }
    }

    
   
    cout << "Minimum path has distance " << minDistance << ": ";
    printRoute(dests[0], dests);
    cout << endl;
    
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
  float distance = 0;
  float dist = 0;
  string pointA;
  pointA = start;
  
  for(int i = 0; i < dests.size(); i++){
    dist = me.getDistance(pointA, dests[i]);
    distance = distance + dist;
    pointA = dests[i]; 
  }

  dist = me.getDistance(dests[0], dests[dests.size()-1]);
  distance = distance + dist;  
  return distance;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE

  for(int i = 0; i < dests.size(); i++){
    cout << dests[i] << "->";
  }
  cout << start <<  endl;
 
}
