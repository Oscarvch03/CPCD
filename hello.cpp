#include <cstdio>
#include <thread>
using namespace std;

// void hello(){
//     printf("Hello Concurrent World\n");
// }

void hello(int id){
  printf("Hello Concurrent World from %d\n", id);
}

void foo(int *a, int size, int id){
    printf("Thread %d has element %d\n", id, a[id]);
}

int main(){

    // thread thr(hello);
    // thr.join();

    // thread thr1(hello, 1);
    // thread thr2(hello, 2);
    // thread thr3(hello, 3);
    // hello(0);
    //
    // thr1.join();
    // thr2.join();
    // thr3.join();



    int a[8] = {10, 20, 30, 40, 50, 60, 70, 80};

    foo(a, 8, 7);

    thread thr1(foo, a, 8, 0);
    thread thr2(foo, a, 8, 1);
    thread thr3(foo, a, 8, 2);
    thread thr4(foo, a, 8, 3);
    thread thr5(foo, a, 8, 4);
    thread thr6(foo, a, 8, 5);
    thread thr7(foo, a, 8, 6);

    hello(12);

    thr1.join();
    thr2.join();
    thr3.join();
    thr4.join();
    thr5.join();
    thr6.join();
    thr7.join();

    hello(1164);


    return 0;
}
