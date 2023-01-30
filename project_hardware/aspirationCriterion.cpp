#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    int size;
    cin >> size;

    int tabuList[size], tabuTenor[size];
    int in;
    for (int i=0; i<size; i++){
        cin >> in;
        tabuList[i]=in;
        cin >> in;
        tabuTenor[i]=in;
    }

    for (int i=0; i<size; i++)
        cout << tabuList[i] << ": " << tabuTenor[i] << endl;

    return 0;
}