typedef struct Map {
    int key;
    int value;
} Map;

typedef struct Dictionary {
    int size;
    Map *maps;
} Dictionary;

//Dictionary init_dictionary(Dictionary dictionary);
//int get_value(Dictionary dictionary, int key);
//Dictionary set_value(Dictionary dictionary, int key, int value);
