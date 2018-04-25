//
//  naive.hpp
//  numberID
//
//  Created by Jake Elling on 4/24/18.
//

#ifndef naive_hpp
#define naive_hpp

#include "ofApp.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>

using namespace std;


    typedef map<pair<int, int>, double> Model;
    
    
    int classify(Model model, vector<double> class_probs, ofImage image);
    int return_highest(map<int, double> map);
    Model load(string filename);
string get_file_as_string(string filename);

#endif /* naive_hpp */

