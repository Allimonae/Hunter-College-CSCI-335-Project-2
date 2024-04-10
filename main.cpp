#include "myVector.hpp"
#include <fstream>

int main(){
    // std::ifstream file("testinput.txt");
    // if (file.fail()){
    //     std::cerr << "File cannot be opened for reading" << std::endl;
    //     exit(1);
    // }
    // std::string junk;
    // std::string line;
    
    // std::string instr, token;
    // getline(file, junk);
    // while(file >> instr >> token){
    //     if (instr == "insert"){
    //         test.insert(stoi(token));
    //     }
    //     else if (instr == "pop"){
    //         test.popMedian();
    //     }
    // }

    // test.printElements();
    std::vector<int> nums;
    vectorInsert(nums, 14667);
    std::cout << nums.size();
    vectorInsert(nums, 3074);
    vectorInsert(nums, 11294);
    vectorInsert(nums, 26952);
    // 11167
    // 8956
    // 9292
    // 15789
    // 10697
    // 3350
    // 30176)
    std::cout << nums.size();
    for (auto it = nums.begin(); it != nums.end(); ++it){
        std::cout << *it << ", ";
    }

}