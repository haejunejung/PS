#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// enroll 순서대로 되어 있다.

class info {
    private:
    std::string parent_;
    int result_;
    public:
    info (std::string parent, int result) : parent_(parent), result_(result) {}
    
    void setParent (std::string parent) {
        this->parent_ = parent;
    }
    
    void setResult (int result) {
        this->result_ = result;
    }
    
    std::string getParent () {
        return this->parent_;
    }
    
    int getResult () {
        return this->result_;
    }
};

int getValue (int val) {
    return val * 100;
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    unordered_map<string, string>   persons; // {name, parent}
    unordered_map<string, int>      results; // {name, result}

    for (size_t i = 0; i < enroll.size(); i++) {
        std::string person = enroll[i];
        std::string parent = referral[i];
        
        persons[person] = parent;
        results[person] = 0;
    }
    
    for (size_t i = 0; i < seller.size(); i++) {
        std::string person = seller[i];
        int value = getValue(amount[i]);
        
        
        while (person != "-" && value != 0) {
            if ((value / 10) < 1) {
                results[person] += value;
                person = persons[person];
                value = 0;
            }
            else {
                results[person] += value - (value / 10);
                person = persons[person];
                value = (value / 10);
            }
        }
    }
    
    for (const string &person : enroll) {
        answer.push_back(results[person]);
    }
    
    return answer;
}