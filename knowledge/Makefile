CC=gcc
CCO=gcc -c
BIN=classifier_test

$(BIN):
	gcc classifier_test.c classifier.c io.c dictionary.c error.c converter.c datasetio.c dataset.c visualizer.c preprocessing.c -o classifier_test -g -w

clean:
	rm -rf ./*.o $(BIN)
