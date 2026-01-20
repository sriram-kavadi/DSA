#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int maxArea(vector<int>height){
    int n=height.size();
    vector<int>lSmaller(n);
    vector<int>rSmaller(n);
    stack<int>st;

    for(int i=0;i<height.size();i++){
        while(!st.empty()&&height[i]<=height[st.top()]){
            st.pop();
        }

        lSmaller[i]= (st.empty())? -1 : st.top();

        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&height[i]<=height[st.top()]){
            st.pop();
        }

        rSmaller[i]= st.empty()? -1 : st.top();
        st.push(i);
    }

    int mxArea=0;

    for(int i=0;i<height.size();i++){
        int width= rSmaller[i]-lSmaller[i]-1;

        int area=height[i]*width;

        mxArea=max(area,mxArea);
    }
    return mxArea;
}

int main(){
    vector<int>height={2,1,5,6,2,3};

    cout<<maxArea(height);
    return 0;
}