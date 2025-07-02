#include<bits/stdc++.h>
using namespace std;

void Insert_In_descending_stack(stack<int>& st,int n){
    stack<int> temp;
    while(!st.empty() && st.top() < n){
        temp.push(st.top());
        st.pop();
    }
    st.push(n);
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
}

int kth_largest_number(vector<int>& arr,int k){
    stack<int> first_k;
    for(int n: arr){
        Insert_In_descending_stack(first_k,n);
        if(first_k.size() > k){
            stack<int> reverse;
            while(first_k.size() > 1){
                reverse.push(first_k.top());
                first_k.pop();
            }
            first_k.pop();
            while(!reverse.empty()){
                first_k.push(reverse.top());
                reverse.pop();
            }
        }
    }
    int kthLargest = INT_MIN ;
    for (int i = 0; i < k; ++i) {
        kthLargest = first_k.top();
        first_k.pop();
    }
    return kthLargest;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {5, 2, 9, 1, 7};
    int k = 3;
    cout << "3rd largest is: " << kth_largest_number(arr, k) << "\n";
    return 0;
}
