// Leetcode 1352
#include<bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
private:
    vector<int> prefixProduct;
public:
    ProductOfNumbers() {    
        prefixProduct = {1};
    }
    
    void add(int num) {
        if(num == 0) {
            prefixProduct = {1};
        } else {
            prefixProduct.push_back(prefixProduct.back() * num);
        }
    }
    
    int getProduct(int k) {
        int size = prefixProduct.size();
        return (k < size) ? (prefixProduct.back() / prefixProduct[size - k - 1]) : 0;
    }
};

int main () {
    int num;
    cin >> num;
    ProductOfNumbers* obj = new ProductOfNumbers();
    obj->add(num);
    int k;
    cin >> k;
    int param_2 = obj->getProduct(k);
}