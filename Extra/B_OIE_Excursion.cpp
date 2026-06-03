#include<iostream>
#include<vector>
using namespace std;
class CalculateTax{
    public:
    static int calculateTax(int salary){
        int tax;
        if(salary > 5000){
            tax = salary * 0.2;
        }
        else{
            tax = salary * 0.1;
        }
        return tax;
    }
};
class CalculateSalary{
    public:
    static int calculateSalary(int basic,int bonus){
        int netSalary = 0;
        int total = basic + bonus;
        int tax = CalculateTax::calculateTax(total);
        netSalary = total - tax;
        return netSalary;
    }
};
class Employee{
    private:
    string name;
    int basic;
    int bonus;
    int tax;
    public:
    void setName(string name){
        this->name = name;
    }

    void setBasic(int basic){
        this->basic = basic;
    }
    void setBonus(int bonus){
        this->bonus = bonus;
    }
    void setTax(int tax){
        this->tax = tax;
    }
    string getName(){
        return name;
    }
    int getBasic(){
        return basic;
    }
    int getBonus(){
        return bonus;
    }
    int Salary(){
        int sal = CalculateSalary::calculateSalary(basic,bonus);
        return sal;
    }
    void display(){
        cout<<"Name of the employee is --> "<<name<<endl;
        cout<<"Salary of the employee is --> "<<Salary()<<endl;
    }
};
int main(){
    Employee e1;
    e1.setName("Vivek");
    e1.setBasic(40000);
    e1.setBonus(15000);
    e1.display();
}
