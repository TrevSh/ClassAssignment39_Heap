//Dynamic Memory Example
#include <iostream>

int* intOnHeap();   //returns an int on the heap
void leak1();       //creates a memory leak
void leak2();       //creates another memory leak


int main()
{
    int* pHeap = new int;       //'new' allocates memory on the heap and returns its address. pHeap points to it.
    *pHeap = 10;                //Next line assigns 10 to the heap allocated above.
    std::cout << "*pHeap: " << *pHeap << "\n\n";

    int* pHeap2 = intOnHeap();  //Points to the object made by inOnHeap() which is 20.
    std::cout << "*pHeap2: "<<*pHeap2<<"\n\n";

    std::cout << "Freeing memory pointed to by the pHeap. \n\n";
    delete pHeap;               //Everytime you use new, you should also use delete after to free the memory you've used. Otherwise you get memory leaks.
    
    std::cout << "Freeing memory pointed to by the pHeap2. \n\n";
    delete pHeap2;

    //get rid of dangling pointers. Dangling pointers point to unused memory, taking up space. The following frees the space by pointing them towards null.
    pHeap = 0;
    pHeap2 = 0;

    system("pause");
}
//Allocates a chunk of memory on the heap and assigns 20 to it.
int* intOnHeap() {
    int* pTemp = new int(20);
    return pTemp;
}

//Dont call. This memory would be lost during runtime. Memory leaks can lead to program crashes.
void leak1() {
    int* drip1 = new int(30);
}
//Dont call
void leak2() {
    int* drip2 = new int(50);
    drip2 = new int(100);       //Moving the pointer from 50 to 100 creates a memory leak, as 50 is not unaccounted for. Notice there are two 'new's and only one delete.
    delete drip2;
}