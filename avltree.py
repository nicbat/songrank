class AVLNode:
    def __init__(self, data):
        self.height = 0
        self.children = [None, None]
        self.data = data

    def getChildHeight(self, child):
        if self.children[child] is None:
            return -1
        else:
            return self.children[child].height

    def updateHeight(self):
        self.height = max(self.getChildHeight(0), self.getChildHeight(1)) + 1
    
    def getBalanceFactor(self):
        return self.getChildHeight(0) - self.getChildHeight(1)

    def compareData(self, data):
        answer = -1
        while answer not in [0,1,2,3]:
            print(str(self.data) + " or " + str(data) + ":")
            answer = int(input())
        return answer

class AVLTree:
    def __init__(self):
        self.root = None
        self.size = 0

    def treeRankings(self):
        def printRankingsHelper(node, output="", ranking=1):
            if node is not None:
                output, ranking = printRankingsHelper(node.children[0], output, ranking)
                output += "\n" + str(ranking) + ". " + str(node.data)
                ranking += 1
                output, ranking = printRankingsHelper(node.children[1], output, ranking)
            return output, ranking
        output, ranking = printRankingsHelper(self.root)
        return output

    def rotateLeft(self, node):
        left = node.children[0]
        node.children[0] = left.children[1]
        left.children[1] = node

        node.updateHeight()
        left.updateHeight()

        return left

    def rotateRight(self, node):
        right = node.children[1]
        node.children[1] = right.children[0]
        right.children[0] = node

        node.updateHeight()
        right.updateHeight()

        return right

    def rotate(self, node):
        if node.getBalanceFactor() < -1:
            node = self.rotateRight(node)
            if node.getBalanceFactor() > 1:
                node = self.rotateLeft(node)
        elif node.getBalanceFactor() > 1:
            node = self.rotateLeft(node)
            if node.getBalanceFactor() < -1:
                node = self.rotateRight(node)
        
        return node
    


    # return 0 on cancel or fail, 1 on success
    def insert(self, newdata):
        path = [] # list of nodes
        pathDirection = [] # list of directions
        current = self.root
        prev = None
        while current is not None:
            direction = current.compareData(newdata)
            if direction == 0 or direction == 3:
                # cancel the insertion
                return direction
            child = direction - 1
            prev = current
            current = current.children[child]
            path.append(prev)
            pathDirection.append(child)
        
        current = AVLNode(newdata)
        if self.root is None:
            self.root = current
        else:
            prev.children[child] = current
            prev.updateHeight()
            self.size += 1
        
        # going through path and rotating
        node = None
        path_direction = 0
        while len(path) > 0:
            node = path.pop()
            path_direction = pathDirection.pop()
            node.updateHeight()
            if abs(node.getBalanceFactor()) >= 2:
                if len(path) == 0:
                    self.root = self.rotate(node)
                else:
                    prev = path.pop()
                    path_direction = pathDirection.pop()
                    prev.children[path_direction] = self.rotate(prev.children[path_direction])
                    prev.children[path_direction].updateHeight()
                    prev.updateHeight()

        if node is not None:
            self.root.updateHeight()
            node.updateHeight()
        
        return 1

class Song:
    def __init__(self, title, album, artist):
        self.title = title
        self.album = album
        self.artist = artist
    
    def __str__(self):
        output = "\"" + self.title + "\"" + " (" + self.album + ")"
        return output
        # if withArtist:
        #     output += " ~ " + self.artist