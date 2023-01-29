import threading
import os



def neighbor(prev_node,prices,weights,result) :
    temp_node = prev_node.copy()
    value = 0

    for i in range(9):
        temp_node = prev_node.copy()
        if (temp_node[i] == 1):
            temp_node[i] = 0
        else:
            temp_node[i] = 1
        weight = 0
        print(temp_node)
        for j in range(9):
            weight = weight + (temp_node[j] * weights[j])
        if weight <= 20:
            #print(temp_node)
            temp_value = 0
            for k in range(9):
                temp_value = temp_value + (temp_node[k] * (prices[k] / weights[k]))
            if (temp_value > value) :
                value = temp_value
                node = temp_node
    result = node

def aspirationCriteration() :
    pass
    # os.system()    run aspirationCriteration.cpp




#cNode = os.system()    run findStartNode.cpp and cNode will be output node
prices = [6,5,8,5,4,7,3,6,8]
weights = [2,3,6,7,5,9,3,4,5]
result = cNode
x = threading.Thread(target=neighbor,args=(cNode,prices,weights,result))
x.start()
y = threading.Thread(target=aspirationCriteration,args=())
y.start()


# but what have to do with proc_search??????