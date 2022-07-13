#include <iostream>
#include <memory>
using namespace std;

class Student{
private:
    string name;
    int age;
public:
    Student(string name, int age) : name(name), age(age) {cout << "Constructor\n";}
    ~Student(){cout << "Destructor\n";}
    void Print(){
        cout << "Name: " << this->name << " " << " Age: " << this->age << endl;
    }
};

int main()
{
    shared_ptr<Student> P1(new Student("Dat", 23));
    weak_ptr<Student> P;
    P = P1;
    P1->Print();
    {
    shared_ptr<Student> P2;
    P2 = P1;
    P2->Print();
    }
    P1->Print();

    cout << P1.use_count() << endl;
    return 0;
}

//int main()
//{

//    shared_ptr<Student> P1(new Student("Dat", 23));
//    P1->Print();
//    {
//    shared_ptr<Student> P2;
//    P2 = P1;
//    P2->Print();
//    }
//    P1->Print();

//    cout << P1.use_count() << endl;
//    return 0;
//}

//int main(){
//    unique_ptr<Student> P1(new Student("Dat", 23));
//    P1->Print();

//    // unique_ptr<Rectangle> P2(P1);
//    unique_ptr<Student> P2;
//    P2 = move(P1);

//    // This'll print 50
//    P2->Print();
//}

//void fun()
//{
//    Student* p = new Student();
//}

//int main()
//{
//    while (1) {
//        fun();
//    }
//}
