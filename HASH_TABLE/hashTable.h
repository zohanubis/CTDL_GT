#ifndef HashTable_h
#define HashTable_h
using namespace std;
struct set
{
    int key;
    int data;
};
struct set *array;
int capacity = 10;
int size = 0;

int hashFunction(int key);
int checkPrime(int n);
int getPrime(int n);
void initArray();
void insert(int key, int data);
void removeElement(int key);
void display();
#endif // !HashTable_h
