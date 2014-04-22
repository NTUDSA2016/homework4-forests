#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include "forest_pred.h"

using std::string;

int main(int argc,char** argv) {
	int correct = 0;
  int total = 0;
	double *attr;

  std::vector<double> feature;
  double* feature_array = NULL;

  std::ifstream fin;
  string istring;
  fin.open(argv[1]);

  while (std::getline(fin, istring)) {
    total++;
    char *cstring, *tmp;
    int label;
    
    cstring = new char[istring.size() + 5];
    strcpy(cstring, istring.c_str());
    
    tmp =  strtok(cstring, ": ");
    label = atoi(tmp);

    int counter = 1;
    feature.clear();
    tmp = strtok(NULL, ": ");

    while(tmp != NULL) {
      int feature_id = atoi(tmp);
      while(counter < feature_id) {
        feature.push_back(0.0);
        counter++;
      }

      tmp = strtok(NULL, ": ");
      feature.push_back(atof(tmp));
      counter++;
      
      tmp = strtok(NULL, ": ");
    }
    delete[] cstring;
    
    int prediction = forest_predict(attr);
    if (prediction == label) correct++;
  }

	printf("Accuracy: %d/%d = %lf%%\n", correct, total, correct*100.0/total);
}
