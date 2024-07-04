                                           //File Handlig using Class
#include <iostream>
#include <fstream>


using namespace std;

class Base
{
private:
    int base_data;
public:
    void set_data(int data)
    {
        base_data = data;
    }
    int get_data()
    {
        return base_data;
    }

};

int main()
{
    Base b1,b2;
    
    b1.set_data(11);
    
    cout<<b1.get_data()<<endl;
    
    ofstream fout("example.dat", ios::binary);
    ifstream fin("example.dat" , ios::binary);
    
    if(!fout && !fin)
    {
        cerr<<"File Creation Failed"<<endl;
        return 1;
    }
    
    fout.write(reinterpret_cast<char*>(&b1),sizeof(Base));
    
    fout.close();
    
    fin.read(reinterpret_cast<char*>(&b2), sizeof(Base));
    cout<<b2.get_data();
    
    
    
    fin.close();

    return 0;
}