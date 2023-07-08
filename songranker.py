import csv
import avltree

songlist = []
with open('TSSongs.csv', newline='') as f:
    reader = csv.reader(f, delimiter = ',')
    for row in reader:
        songlist.append(avltree.Song(row[0], row[1], "Taylor Swift"))

# for song in songlist:
#     print(str(song))

unknown = []
tree = avltree.AVLTree()

knownAnswer = 0
for song in songlist:
    while knownAnswer is not 1:
        print("Do you know this song? (1 for yes, anything else for no): " + str(song))
        knownAnswer = input()
        if knownAnswer is not 1:
            unknown.append(song)
        else:
            print("------------")
            print("For the following questions, answer 1 or 2 (0 to exit, 3 for don't know song)")
        result = tree.insert(song)
        if result is 0:
            break
        if result is 3:
            unknown.append(song)

tree.printRankings()