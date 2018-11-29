#include <iostream>
#include "UnsortedType.cpp"
using namespace std;

int main()
{
    UnsortedType<int> obj1;
    UnsortedType<int> obj2;
    UnsortedType<int> newObj;

    int a, b;
    cin >> a;
    for(int i=0; i<a; i++){
        int x;
        cin >> x;
        obj1.InsertItem(x);
    }

    cin >> b;
    for(int i=0; i<b; i++){
        int y;
        cin >> y;
        obj2.InsertItem(y);
    }

    obj1.ResetList();
    obj2.ResetList();

    int temp1, temp2;
    while(obj1.LengthIs()!=0 && obj2.LengthIs()!=0){
        obj1.GetNextItem(temp1);
        obj2.GetNextItem(temp2);

        if(temp1 > temp2){
            newObj.InsertItem(temp1);
            obj1.DeleteItem(temp1);
            obj1.ResetList();
            obj2.ResetList();
        } else if(temp2 > temp1) {
            newObj.InsertItem(temp2);
            obj2.DeleteItem(temp2);
            obj1.ResetList();
            obj2.ResetList();
        } else if(temp1 == temp2) {
            obj2.DeleteItem(temp2);
            obj2.ResetList();
        }

        if(obj1.LengthIs()==0 && obj2.LengthIs()!=0){
            newObj.InsertItem(temp2);
            obj2.DeleteItem(temp2);
            obj2.ResetList();
        } else if(obj1.LengthIs()!=0 && obj2.LengthIs()==0){
            newObj.InsertItem(temp1);
            obj1.DeleteItem(temp1);
            obj1.ResetList();
        }
    }

    int temp3;
    for(int i=0; i<newObj.LengthIs(); i++){
        newObj.GetNextItem(temp3);
        cout << temp3 << " ";
    }
    cout << endl;

    return 0;
}
