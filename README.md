dsa14hw4
========

Data Structure and Algorithm Homework 4

The first argument of both `tree_predictor.cpp` and `forest_predictor.cpp`
is the test (prediction) data in the format same as training data, and the
output is the accuray of the predictor on the test data.

For example,

    ./tree_predictor heart

Usage of the `Makefile`:

1. `make tree`: build the decision tree learner.

1. `make forest`: build the random forest learner.

1. `make run_tree FNAME=heart.train`: run the decision tree on data `heart.train`.

1. `make run_forest FNAME=heart.train T=30`:

    run the random forest with 30 trees on data `heart.train`.

1. `make predict_tree PNAME=heart.test`:

    make prediction by the decision tree model on data `heart.test`.

1. `make predict_forest PNAME=heart.test`:

    make prediction by random forest model on data `heart.test`.

You can play around with different `FNAME`, `PNAME` and `T`.
