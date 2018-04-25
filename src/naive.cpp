//
//  naive.cpp
//  numberID
//
//  Created by Jake Elling on 4/24/18.
//

#include "naive.hpp"

using namespace std;


int classify(Model model, vector<double> class_probs, ofImage image) {

    map<int, double> number_and_prob;
    ofPixels pixels = image.getPixels();

    for (int i = 0; i < 10; i++) {

        double probability = 0.0;
        probability += log(class_probs[i]);
        
        for (int j = 0; j < 784; j++) {

            double a = model.at(make_pair(j, i));
            ofColor co = pixels.getColor(j);

            if (pixels.getColor(j).getHex() != 0xffffff) {
                probability += log(a);
            } else {
                probability += log(1 - a);
            }
        }
        number_and_prob[i] = probability;
    }
    return return_highest(number_and_prob);
}


int return_highest(map<int, double> map) {
    double highest = -100000.0;
    int key = 0;

    for (auto e: map) {
        if (e.second >= highest) {
            highest = e.second;
            key = e.first;
        }
    }
    return key;
}

/*
 * takes in a filename and returns a model from a file
 */
Model load(string filename) {
    string str = get_file_as_string(filename);

    map<pair<int, int>, double> g;
    vector<string> out;

    stringstream x(str);
    string buf;
    while (x >> buf) {
        out.push_back(buf);
    }

    for (int i = 2; i < out.size(); i += 3) {
        int first_int = stoi(out.at(i-2).c_str());
        int second_int = stoi(out.at(i-1).c_str());
        double doubl = strtod(out.at(i).c_str(), NULL);

        pair<int, int> pair = make_pair(first_int, second_int);
        g[pair] = doubl;
    }
    return g;
}

/*
 * takes in a filename and returns a single string of all characters
 */
string get_file_as_string(string filename) {
    string result;
    ifstream in;
    in.open(filename);

    if (!in) {
        cout << "Error";
    }

    while(in) {
        string line;
        getline(in, line);
        result.append(line);
    }

    in.close();
    return result;
}
