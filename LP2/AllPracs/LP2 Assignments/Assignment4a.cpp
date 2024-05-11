#include<bits/stdc++.h>
#include <iostream>
using namespace std;
struct Variable{
    int id;
    int value;
    bool assigned;
};
struct Constraint{
    int var1;
    int var2;
    int difference;
};
bool isConsistent(vector <Variable> &assignment, const vector <Constraint> constraints, int varIndex, int value){
    for(const auto& constraint : constraints){
        if(constraint.var1 == varIndex && assignment[constraint.var2].assigned){
            if(abs(value-assignment[constraint.var2].value)<constraint.difference){
                return false;
            }
        }
        if(constraint.var2 == varIndex && assignment[constraint.var1].assigned){
            if(abs(value-assignment[constraint.var1].value)<constraint.difference){
                return false;
            }
        }
    }
    return true;
}

int selectVariable(vector <Variable> &assignment, const vector <Constraint> constraints){
    int mostConstrainedVar = -1;
    int minDomainSize = INT32_MAX;

    for(int i =0; i<assignment.size(); i++){
        if(!assignment[i].assigned){
            int domainSize=0;
            for(int val = 1; val<=10; val++){
                if(isConsistent(assignment, constraints, i, val)){
                    domainSize++;
                }
            }
            if(domainSize<minDomainSize){
                minDomainSize=domainSize;
                mostConstrainedVar=i;
            }
        }
    }
    return mostConstrainedVar;
}

bool backtracking(vector <Variable> &variables, const vector <Constraint> constraints ){
    bool allAssigned = true;
    for(const auto& i: variables){
        if(!i.assigned){
            allAssigned=false;
            break;
        }
    }
    if(allAssigned==true){
        for(const auto& var: variables){
            cout<<"Variable"<<var.id<<" = "<<var.value<<" "<<var.assigned<<endl;
        }
        return true;
    }

    int varIndex = selectVariable(variables,constraints);

    for(int value =0; value<=10; value++ ){
        if(!variables[varIndex].assigned && isConsistent(variables, constraints, varIndex, value)){
            variables[varIndex].value = value;
            variables[varIndex].assigned = true;

            if(backtracking(variables, constraints)){
                return true;
            }

            variables[varIndex].assigned=false;
        }
    }

    return false;
}
int main(){
    vector<Variable> variables= {{1,0,false},{2,0,false},{3,0,false}};
    vector<Constraint> constraints = {{0,1,2},{1,2,3}};

    if(!backtracking(variables, constraints))
        cout<<"No solution exists!";
    return 0;
}