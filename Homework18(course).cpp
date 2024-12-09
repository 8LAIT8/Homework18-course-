/*1)
#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string name;  

public:
    Animal(const string& animalName) : name(animalName) {}

    string getName() const {
        return name;
    }

    void setName(const string& animalName) {
        name = animalName;
    }

    void displayInfo() const {
        cout << "This animal is a " << name << "." << endl;
    }
};

int main() {
    Animal dog("Dog");

    dog.displayInfo();
    dog.setName("Cat");
    dog.displayInfo();

    return 0;
}*/
/*2)
#include <iostream>
using namespace std;

class BoundedAray {
private:
    int* arr;        
    int size;        

public:
    BoundedAray(int size) {
        if (size <= 0) {
            throw invalid_argument("Size must be positive.");
        }
        this->size = size;
        arr = new int[size]; 
    }

    ~BoundedAray() {
        delete[] arr;
    }

    void set(int index, int value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range.");
        }
        arr[index] = value;
    }

    int get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range.");
        }
        return arr[index];
    }

    int getSize() const {
        return size;
    }
};

int main() {
    try {
        BoundedAray myArray(5); 

        for (int i = 0; i < myArray.getSize(); ++i) {
            myArray.set(i, i * 2); 
        }

        for (int i = 0; i < myArray.getSize(); ++i) {
            cout << "Element at index " << i << ": " << myArray.get(i) << endl;
        }
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}*/
/*3)
#include <iostream>
using namespace std;

class BoundedArray {
private:
    int* arr;       
    int size;        

public:
    BoundedArray(int size) {
        if (size <= 0) {
            throw invalid_argument("Size must be positive.");
        }
        this->size = size;
        arr = new int[size]; 
    }

    ~BoundedArray() {
        delete[] arr;
    }

    void set(int index, int value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range.");
        }
        arr[index] = value;
    }

    int get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range.");
        }
        return arr[index];
    }

    int getSize() const {
        return size;
    }
};

class Set {
private:
    BoundedArray* array;  
    int capacity;         
    int currentSize;      

public:
    Set(int capacity) {
        this->capacity = capacity;
        this->currentSize = 0;
        array = new BoundedArray(capacity);  
    }

    ~Set() {
        delete array;  
    }

    bool contains(int value) {
        for (int i = 0; i < currentSize; ++i) {
            if (array->get(i) == value) {
                return true;
            }
        }
        return false;
    }

    void add(int value) {
        if (currentSize >= capacity) {
            throw overflow_error("Set is full.");
        }
        if (!contains(value)) {
            array->set(currentSize, value);
            currentSize++;
        }
    }

    void remove(int value) {
        int index = -1;
        for (int i = 0; i < currentSize; ++i) {
            if (array->get(i) == value) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            for (int i = index; i < currentSize - 1; ++i) {
                array->set(i, array->get(i + 1));
            }
            currentSize--;
        }
    }

    void display() {
        if (currentSize == 0) {
            cout << "Set is empty." << endl;
            return;
        }

        for (int i = 0; i < currentSize; ++i) {
            cout << array->get(i) << " ";
        }
        cout << endl;
    }

    int size() const {
        return currentSize;
    }
};

int main() {
    Set mySet(5);  

    mySet.add(1);
    mySet.add(2);
    mySet.add(3);
    mySet.add(4);
    mySet.add(5);

    
    cout << "Elements in the set: ";
    mySet.display();

    mySet.add(3);  

    cout << "Elements in the set after trying to add duplicate: ";
    mySet.display();

    mySet.remove(3);

    cout << "Elements in the set after removing 3: ";
    mySet.display();

    return 0;
}
*/
/*6)
#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    Animal() : itsWeight(0), itsAge(0) {}
    int GetWeight() const { return itsWeight; }
    int GetAge() const { return itsAge; }

    friend void setValue(Animal &, int);

private:
    int itsWeight;
    int itsAge;
};

void setValue(Animal &theAnimal, int theWeight)
{
    theAnimal.itsWeight = theWeight;
}

int main()
{
    Animal peppy;
    setValue(peppy, 5);
    cout << "Weight of peppy: " << peppy.GetWeight() << endl;
    return 0;
}
*/
/*7) #include <iostream>
#include <string>

using namespace std;

class Animal;

void setValue(Animal &, int);
void setValue(Animal &, int, int);

class Animal
{
    friend void setValue(Animal &, int);       
    friend void setValue(Animal &, int, int); 

private:
    int itsWeight;
    int itsAge;
};

void setValue(Animal &theAnimal, int theWeight)
{
    theAnimal.itsWeight = theWeight;
}

void setValue(Animal &theAnimal, int theWeight, int theAge)
{
    theAnimal.itsWeight = theWeight;
    theAnimal.itsAge = theAge;
}

int main()
{
    Animal peppy;
    setValue(peppy, 5);
    setValue(peppy, 7, 9);
    return 0;
}
*/