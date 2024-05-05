''' 🔘PROBLEM STATEMET:-
Consider a telephone book database of N clients. Make use of a hash table implementation
to quickly look up client‘s telephone number. Make use of two collision handling
techniques and compare them using number of comparisons required to find a set of
telephone numbers (Python) '''


class hashtable:
    def __init__(self):
        self.m = int(input("enter size of hash table : "))
        self.hashTable = [None] * self.m
        self.elecount = 0
        self.comparisms = 0
        print(self.hashTable)
    
    def hashFunction(self, key):
        return key % self.m

    def isfull(self):
        if self.elecount == self.m:
            return True
        else:
            return False
    
    def linearprobr(self, key, data):
        index = self.hashFunction(key)
        compare = 0
        while self.hashTable[index] != None:
            index = index + 1
            compare = compare + 1
            if index == self.m:
                index = 0
        self.hashTable[index] = [key, data]
        self.elecount += 1
        print("data inserted at ", index)
        print(self.hashTable)
        print("no of comparisons : ", compare)

    def getlinear(self, key, data):
        index = self.hashFunction(key)
        while self.hashTable[index] is not None:
            if self.hashTable[index] == [key, data]:
                return index
            index = (index + 1) % self.m
        return None
    
    def quadraticprobr(self, key, data):
        index = self.hashFunction(key)
        compare = 0
        i = 0
        while self.hashTable[index] != None:
            index = (index + i*i) % self.m
            compare = compare + 1
            i = i + 1
        self.hashTable[index] = [key, data]
        self.elecount += 1
        print("data inserted at ", index)
        print(self.hashTable)
        print("no of comparisons : ", compare)
    	
    def getQuadratic(self, key, data):
        index = self.hashFunction(key)
        i = 0
        while self.hashTable[index] is not None:
            if self.hashTable[index] == [key, data]:
                return index
            i = i + 1
            index = (index + i*i) % self.m
        return None
    
    

    def insert(self, key, data, probing_method):
        if self.isfull():
            print("table is full")
            return False
        index = self.hashFunction(key)
        if self.hashTable[index] is None:
            self.hashTable[index] = [key, data]
            self.elecount += 1
            print("data inserted at ", index)
            print(self.hashTable)
        else:
            print("collision occurred, applying {} method".format(probing_method.__name__))
            probing_method(key, data)

    def search(self, key, data, probing_method):
        index = self.hashFunction(key)
        i = 0
        while self.hashTable[index] is not None:
            if self.hashTable[index] == [key, data]:
                return index
            i += 1
            index = (index + i*i) % self.m
        return None

    def menu(self):
        ch = 0
        while ch != 3:
            print("************************")
            print("1. Linear Probe    *")
            print("2. Quadratic Probe  *")
            print("3.Exit")
            print("************************")
            ch = int(input("Enter Choice : "))
            if ch == 1 or ch == 2:
                probing_method = self.linearprobr if ch == 1 else self.quadraticprobr
                while True:
                    print("** 1.Insert **")
                    print("** 2.Search **")
                    print("** 3.Exit **")
                    ch2 = int(input("enter your choice : "))
                    if ch2 == 1:
                        a = int(input("enter phone number : "))
                        b = str(input("enter name : "))
                        self.insert(a, b, probing_method)
                    elif ch2 == 2:
                        k = int(input("enter key to be searched : "))
                        b = str(input("enter name : "))
                        f = self.search(k, b, probing_method)
                        if f is None:
                            print("Key not found")
                        else:
                            print("key found at", f)
                    elif ch2 == 3:
                        break
            elif ch == 3:
                print("thank you:")
            break

if __name__ == "__main__":
    obj = hashtable()
    obj.menu()
