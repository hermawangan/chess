#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 101

struct DataItem
{
    int data[2];
    int key;
};

struct DataItem *hashArray[SIZE];
struct DataItem *dummyItem;
struct DataItem *item;

int hashCode(int key)
{
    return key % SIZE;
}

struct DataItem *search(int key)
{
    // get the hash
    int hashIndex = hashCode(key);

    // move in array until an empty
    while (hashArray[hashIndex] != NULL)
    {

        if (hashArray[hashIndex]->key == key)
            return hashArray[hashIndex];

        // go to next cell
        ++hashIndex;

        // wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}

void insert(int key, int data[2])
{

    struct DataItem *item = (struct DataItem *)malloc(sizeof(struct DataItem));
    item->data[0] = data[0];
    item->data[1] = data[1];
    item->key = key;

    // get the hash
    int hashIndex = hashCode(key);

    // move in array until an empty or deleted cell
    while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1)
    {
        // go to next cell
        ++hashIndex;

        // wrap around the table
        hashIndex %= SIZE;
    }

    hashArray[hashIndex] = item;
}

struct DataItem *delete(struct DataItem *item)
{
    int key = item->key;

    // get the hash
    int hashIndex = hashCode(key);

    // move in array until an empty
    while (hashArray[hashIndex] != NULL)
    {

        if (hashArray[hashIndex]->key == key)
        {
            struct DataItem *temp = hashArray[hashIndex];

            // assign a dummy item at deleted position
            hashArray[hashIndex] = dummyItem;
            return temp;
        }

        // go to next cell
        ++hashIndex;

        // wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}

void display()
{
    int i = 0;

    for (i = 0; i < SIZE; i++)
    {

        if (hashArray[i] != NULL)
            printf(" (%d, pos: (%d,%d))", hashArray[i]->key, hashArray[i]->data[0], hashArray[i]->data[1]);
        else
            printf(" ~~ ");
    }

    printf("\n");
}

int main()
{
    int arr[2] = {1, 1};
    insert(11, arr);
    // insert(12, 70);
    // insert(13, 80);
    // insert(14, 25);
    // insert(15, 44);
    // insert(16, 32);
    // insert(17, 11);
    // insert(18, 78);

    // insert(21, 20);
    // insert(22, 70);
    // insert(23, 80);
    // insert(24, 25);
    // insert(25, 44);
    // insert(26, 32);
    // insert(27, 11);
    // insert(28, 78);

    // insert(31, 20);
    // insert(32, 70);
    // insert(33, 80);
    // insert(34, 25);
    // insert(35, 44);
    // insert(36, 32);
    // insert(37, 11);
    // insert(38, 78);

    // insert(41, 20);
    // insert(42, 70);
    // insert(43, 80);
    // insert(44, 25);
    // insert(45, 44);
    // insert(46, 32);
    // insert(47, 11);
    // insert(48, 78);

    display();
}