CC=g++
PROG=tree forest
FNAME=wine.train
PNAME=wine.test
T=20
RM=rm -rf

.PHONY: all run_tree run_forest predict_tree predict_forest clean

all:$(PROG)

tree: tree.cpp 
	$(CC) ./tree.cpp -o tree

forest: forest.cpp
	$(CC) ./forest.cpp -o forest

tree_pred.h: tree $(FNAME)
	./tree $(FNAME)

run_tree: tree_pred.h

forest_pred.h: forest $(FNAME)
	./forest $(FNAME) $(T)

run_forest: forest_pred.h

predict_tree: tree_predictor.cpp tree_pred.h $(PNAME)
	$(CC) ./tree_predictor.cpp -o ./tree_predictor
	./tree_predictor $(PNAME) > ./tree_prediction.txt

predict_forest: forest_predictor.cpp forest_pred.h $(PNAME)
	$(CC) ./forest_predictor.cpp -o ./forest_predictor
	./forest_predictor $(PNAME) > ./forest_prediction.txt

clean:
	$(RM) $(PROG)

