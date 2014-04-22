#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include "tree_pred.h"

using std::string;

int main(int argc,char** argv) {

	int correct = 0;
  int total = 0;
  
  std::vector<int> feature_id;
  std::vector<double> feature_value;
  int* id_array = NULL;
  double* value_array = NULL;

  std::ifstream fin;
  string istring;
  fin.open(argv[1]);

  while (std::getline(fin, istring)) {
    total++;
    char *cstring, *tmp;
    int label;
    
    cstring = new char[istring.size() + 1];
    strncpy(cstring, istring.c_str(), istring.size()+1);

    tmp =  strtok(cstring, ": ");
    label = atoi(tmp);
    feature_id.clear();
    feature_value.clear();
    tmp = strtok(NULL, ": ");

    while(tmp != NULL) {
      int id = atoi(tmp);
      feature_id.push_back(id);
      tmp = strtok(NULL, ": ");
      feature_value.push_back(atof(tmp));
      tmp = strtok(NULL, ": ");
    }

    delete[] cstring;
    
    id_array = new int[feature_id.size()];
    value_array = new double[feature_value.size()];
    
    for (unsigned i = 0; i < feature_id.size(); i++) {
      id_array[i] = feature_id[i];
      value_array[i] = feature_value[i];
    }
    int prediction = tree_predict(id_array, value_array, feature_id.size());
    delete[] id_array;
    delete[] value_array;
    if (prediction == label) correct++;
  }
 
	printf("Accuracy: %d/%d = %lf%%\n", correct, total, correct*100.0/total);
}
