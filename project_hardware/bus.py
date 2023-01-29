import subprocess
import threading
import os


def neighbor(prev_node, prices, weights, result: list):
    value = 0
    node = []
    for i in range(9):
        temp_node = prev_node.copy()
        if temp_node[i] == 1:
            temp_node[i] = 0
        else:
            temp_node[i] = 1
        weight = 0
        # print(temp_node)
        for j in range(9):
            weight = weight + (temp_node[j] * weights[j])
        if weight <= 20:
            # print(temp_node)
            temp_value = 0
            for k in range(9):
                temp_value = temp_value + (temp_node[k] * (prices[k] / weights[k]))
            if temp_value > value:
                value = temp_value
                node = temp_node
    result.append(node)


def aspirationCriteration():
    subprocess.run(['g++ aspirationCriterion.cpp && ./a.out'], stdout=subprocess.PIPE, shell=True)


def findStartNode():
    result = subprocess.run(['g++ findStartNode.cpp && ./a.out'], stdout=subprocess.PIPE, shell=True)
    cNode = decimalToBinary(int(result.stdout.decode('utf-8')))
    return cNode


def decimalToBinary(n) -> list:
    res = list("{:09b}".format(n))
    for i in range(len(res)):
        res[i] = int(res[i])
    return res


def search(cNode, prices, weights):
    result = []
    x = threading.Thread(target=neighbor, args=(cNode, prices, weights, result))
    x.start()
    y = threading.Thread(target=aspirationCriteration, args=())
    y.start()
    x.join(), y.join()
    result = result[0]
    print(result)
    return result


if __name__ == "__main__":
    cNode = findStartNode()

    prices = [6, 5, 8, 5, 4, 7, 3, 6, 8]
    weights = [2, 3, 6, 7, 5, 9, 3, 4, 5]

    for i in range(0, 29):
        result = search(cNode, prices, weights)
        cNode = result
