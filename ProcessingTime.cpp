#include <chrono>
#include <iostream>
using namespace std;

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
 
    for(long int i=0, j=0; i<9999; i++)
    {
        cout<<i;
    }
    cout<<endl;
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "\nElapsed time: " << elapsed.count()*1000 << " s\n";
  
}
