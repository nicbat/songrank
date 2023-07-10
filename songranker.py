import csv
import avltree
import random
import datetime

songlist = []
unknown = []
tree = avltree.AVLTree()
csvPath = "songs.csv"
currentTime = datetime.datetime.now().strftime("%m%d%Y%H%M%S")
outputPath = "TSrankings" + currentTime + ".txt"

def listRankings(input):
    output = ""
    for i, song in enumerate(input, start=1):
        output += "\n" + str(i) + ". " + str(song)
    return output

def writeRankings(treeRankings, listRankings, filePath):
    with open(filePath, "w") as f:
        f.write("Song Rankings:")
        f.write(treeRankings)
        f.write("\n-----------------------\nSongs you don't know:")
        f.write(listRankings)

with open(csvPath, newline='') as f:
    reader = csv.reader(f, delimiter = ',')
    for row in reader:
        songlist.append(avltree.Song(row[0], row[1], "Taylor Swift"))
random.shuffle(songlist)

start = 0
for i, song in enumerate(songlist):
    print("Do you know this song? (1 for yes, anything else for no): " + str(song))
    knownAnswer = int(input())
    if knownAnswer != 1:
        unknown.append(song)
        start += 1
    else:
        print("------------")
        print("For the following questions, answer 1 or 2 (0 to exit, 3 for don't know song on the right)")
        tree.insert(song)
        break
    if start % 10 == 0:
        writeRankings(tree.treeRankings(), listRankings(unknown), outputPath)

for i, song in enumerate(songlist[start+1:]):
    result = tree.insert(song)
    if result == 0:
        break
    if result == 3:
        unknown.append(song)
    if i % 10 == 0:
        writeRankings(tree.treeRankings(), listRankings(unknown), outputPath)

writeRankings(tree.treeRankings(), listRankings(unknown), outputPath)