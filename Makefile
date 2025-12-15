bin/testBSTreeDict: testBSTreeDict.cpp BSTreeDict.h BSNode.h TableEntry.h Dict.h
	mkdir -p bin
	g++ -std=c++17 -o bin/testBSTreeDict testBSTreeDict.cpp

bin/testBSTree: testBSTree.cpp BSTree.h
	mkdir -p bin
	g++ -o bin/testBSTree testBSTree.cpp

bin/testHashTable: testHashTable.cpp HashTable.h Dict.h TableEntry.h
	mkdir -p bin
	g++ -o bin/testHashTable testHashTable.cpp

bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp

clean:
	rm -rf *.o *.gch bin

