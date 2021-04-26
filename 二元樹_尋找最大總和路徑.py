# 測資
# 2 1 3 8 5 16 2 9 11 20 15 8 7 5 9 3 - 8 - - 2 1 5 - - - - - 10
#Node物件
class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        self.direction = None #指向哪邊才是加總較大的路徑; False = 左; True = 右
        self.maxPathSum = None #把子孫最大路徑加總，再加上自己
    def obtainDirection(self):
        if(self.left is None and self.right is None): #該node沒有child，maxPathSum是自己
            self.maxPathSum = self.value
        elif(self.left is None): #該node沒有left child，maxPathSum = right child的maxPathSum + 自己
            self.maxPathSum = self.value + self.right.maxPathSum
            self.direction = True
        elif(self.right is None): #該node沒有right child，maxPathSum = left child的maxPathSum + 自己
            self.maxPathSum = self.value + self.left.maxPathSum
            self.direction = False
        else: #該node有兩個child，比較誰大再 + 自己
            self.maxPathSum = max(self.left.maxPathSum, self.right.maxPathSum) + self.value
            if(self.left.maxPathSum > self.right.maxPathSum):
                self.direction = False
            else:
                self.direction = True

#輸入參數
n = int(input('深度: '))
max_node = 2**(n+1) -1
while(True):
    nodes = []
    for i in input('輸入node(空的節點輸入-): ').split():
        try:
            i = Node(float(i))
        except ValueError: #使用者輸入非數字，在陣列加入None
            i = None
        finally:
            nodes.append(i)
    if(len(nodes) > max_node):
        print('太多node')
    else:
        break

#物件間互相指定left child和right child
for i in range(len(nodes)):
    Index = i + 1
    try:
        nodes[i].left = nodes[(Index * 2) - 1] #node的left child: 自己index * 2
        nodes[i].right = nodes[(Index * 2 + 1) - 1] #node的right child: 自己index *2 -1
    except IndexError: #接下來node都沒child了，跳出
        break

#從最尾端的node開始產生direction
for i in range(len(nodes) - 1, -1, -1):
    if(nodes[i] is not None):
        nodes[i].obtainDirection()

#從第一個node(root)沿著direction標記出路徑
path = []
currentNode = nodes[0] 
while(currentNode.direction is not None): #一直標記直到沒有direction為止(leaf node)
    path.append(currentNode.value)
    if(currentNode.direction is False):
        currentNode = currentNode.left
    else:
        currentNode = currentNode.right
path.append(currentNode.value)

#印出最大總和路徑(兩條路徑加總相等會優先選擇右邊)
print(f'最大總和路徑：{path}')