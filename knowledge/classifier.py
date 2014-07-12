import math


class Node(object):
    left = None
    right = None
    criterion = None
    label = None
    isleaf = None
    
    def __str__(self):
        return str(self.criterion) 


class Criterion(object):
    key = None
    value = None
    
    def __str__(self):
        return "key:{} criterion:{}".format(self.key, self.value)


class Data(object):
    vector = None
    label = None

    def __str__(self):
        return "vector:{:40} label:{}".format(self.vector, self.label)


class Dataset(object):
    array = None    
    size = None
    
    def __str__(self):
        return '\n'.join(map(str, self.array))


class DatasetPair(object):
    left = None
    right = None


#def count_labels(dataset):
#    labels = {}
#    for data in dataset.array: 
#        #linear search 
#        if not(data.label in labels.keys()):
#            labels[data.label] = 0
#        labels[data.label] += 1
#    return labels


#def calc_gini(dataset):
#  total_size = dataset.size
#  counts = count_labels(dataset)
#  imp=0
#  for k1 in counts:
#    p1=float(counts[k1])/total_size
#    for k2 in counts:
#      if k1==k2: continue
#      p2=float(counts[k2])/total_size
#      imp += p1*p2
#  return imp


def count_labels(dataset):
    labels = {} 
    for data in dataset.array: 
        if not(data.label in labels):
            labels[data.label] = 0
        labels[data.label] += 1
    return labels

def calc_entropy(dataset):
    labels = count_labels(dataset)
    
    entropy = 0.0
    for label, count in labels.items():
        p = float(count)/dataset.size
        entropy -= p*math.log(p, 2)
    return entropy

#def calc_gini(dataset):
#    gini_impurity = 1.0
#    labels = count_labels(dataset)
#    for label, count in labels.items():
#        r = count/float(dataset.size)
#        gini_impurity -= r*r
#    return gini_impurity


def calc_info_gain(dataset, dataset_pair):
    p_left = float(dataset_pair.left.size)/dataset.size
    p_right = float(dataset_pair.right.size)/dataset.size
     
    L = p_left * calc_entropy(dataset_pair.left)
    R = p_right * calc_entropy(dataset_pair.right)
    
    randomness = calc_entropy(dataset)
    info_gain = randomness-L-R
    return info_gain


#def calc_info_gain(dataset, dataset_pair):
#    left_size = float(dataset_pair.left.size)
#    right_size = float(dataset_pair.right.size)
#    sum_size = float(dataset.size)
#
#    weight_left = left_size/sum_size
#    weight_right = right_size/sum_size
#    L = weight_left * calc_entropy(dataset_pair.left)
#    R = weight_right * calc_entropy(dataset_pair.right)
#    E = calc_entropy(dataset)
#    return E-L-R


#TODO (key, criterion) to criterion
def divide(dataset, key, criterion):
    left = Dataset()
    right = Dataset()

    left_size = 0
    right_size = 0
    
    left_array = []
    right_array = []
    for data in dataset.array:
        if(data.vector[key] >= criterion):
            left_array.append(data)
            left_size += 1
        else:
            right_array.append(data)
            right_size += 1

    left.array = left_array
    right.array = right_array

    left.size = left_size
    right.size = right_size

    dataset_pair = DatasetPair()
    dataset_pair.left = left
    dataset_pair.right = right
    return dataset_pair


def construct_tree(dataset, n_dim):
    best_info_gain = 0
    best_key = None
    best_criterion = None
    best_dataset_pair = None
    
    for key in range(n_dim):
        #FIXME this section has bugs
        #`criterions` has invalid values
        criterions = []
        for data in dataset.array:
            t = data.vector[key] 
            if not(t in criterions):
                criterions.append(t)

        for criterion in criterions:
            dataset_pair = divide(dataset, key, criterion)
            info_gain = calc_info_gain(dataset, dataset_pair)
            #print("size:{}".format(dataset.size)) 
            #print("L:\n{}".format(dataset_pair.left))
            #print("R:\n{}".format(dataset_pair.right))
            #print("key:{} criterion:{}".format(key, criterion))
            #print("info_gain:{}".format(info_gain))
            #print("")
            if(info_gain > best_info_gain and 
               dataset_pair.left.size > 0 and 
               dataset_pair.right.size > 0):
                best_info_gain = info_gain
                best_key = key
                best_criterion = criterion
                best_dataset_pair = dataset_pair

    isleaf = best_info_gain <= 0
    if not(isleaf): 
        node = Node()
        node.isleaf = False
        criterion = Criterion()
        criterion.key = best_key
        criterion.value = best_criterion
        node.criterion = criterion
        node.left = construct_tree(best_dataset_pair.left, n_dim)
        node.right = construct_tree(best_dataset_pair.right, n_dim)
        return node
    node = Node()
    node.isleaf = True
    node.label = dataset.array[0].label
    return node


def generate_dataset(X, y):
    dataset = Dataset()
    dataset.array = []
    
    size = 0
    for x, label in zip(X, y):
        data = Data()
        data.vector = x 
        data.label = label
        dataset.array.append(data)
        size += 1
    dataset.size = size
    return dataset


def fit(X, y, n_dim):
    dataset = generate_dataset(X, y)
    tree = construct_tree(dataset, n_dim)
    return tree


def predict_once(node, vector):
    if(node.isleaf):
        return node.label
        
    key = node.criterion.key 
    value = node.criterion.value

    if(vector[key] >= value):
        return predict_once(node.left, vector)
    else:
        return predict_once(node.right, vector)


def predict(tree, X):
    results = []
    for x in X:
        result = predict_once(tree, x)
        results.append(result)
    return np.array(results)


def show_tree(node, depth=0):
    if(node.isleaf):
        return

    s = ' ' * depth
    print("{} {}".format(s, node))

    depth += 1
    show_tree(node.left, depth)
    show_tree(node.right, depth)


def test():
    from datasets import wine
    from sklearn.datasets import load_iris
    
    #a = 3
    #b = 10 
    #c = 59
    #d = 64 
    #e = 145
    #f = 150
    #X = np.concatenate((wine.X[a:b], wine.X[c:d], wine.X[e:f]))
    #y = np.concatenate((wine.y[a:b], wine.y[c:d], wine.y[e:f]))
    X = wine.X
    y = wine.y
    print(y)
    tree = fit(X, y, len(X[0]))
    show_tree(tree)
    results = predict(tree, X)
    print(results)
    print(y)
    print((y == results).all())
    return tree

if(__name__ == '__main__'):
    import numpy as np
    test()
