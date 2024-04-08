#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void display(int m,int n,vector<vector<int>> &mat){
  for(int i = 0;i<m;i++){
    for(int j = 0; j<n;j++){
      cout<<mat[i][j]<<" ";
    }
    cout<<"\n";
  }
}
void getRowPrefixSum(int m,int n,vector<vector<int>> &preMatrix,vector<vector<int>> &mat){
  for(int i = 0;i<m;i++){
    for(int j = 0; j<n;j++){
      preMatrix[i][j] = j==0?mat[i][j]:preMatrix[i][j-1] + mat[i][j];
    }
  }
  return;
}

void getColumnPrefixSum(int m,int n,vector<vector<int>> &preMatrix,vector<vector<int>> &mat){
  for(int i = 0;i<n;i++){
    for(int j = 0; j<m;j++){
      preMatrix[j][i] = j==0?mat[j][i]:preMatrix[j-1][i] + mat[j][i];
    }
  }
  return;
}

int getMaxMatrixSum(int m,int n,int k,vector<vector<int>> &rm,vector<vector<int>> &cm,vector<vector<int>> &mat){
  int isum = 0;
  int cisum = 0;
  int maxSum = INT_MIN;
  for(int i = 0;i<k;i++){
    isum += rm[i][k-1];
  }
  cisum = isum;
  for(int i = 0;i<=n-k;i++){
    if(i>0){
      isum = isum - (rm[i-1][k-1])+(rm[i+k-1][k-1]);
      cisum = isum;
    }
    // cout<<"isum: "<<isum<<"\n";
    for(int j = 0; j<=m-k;j++){
      if(j>0)
        if(i>0)
            cisum = cisum-(cm[i+k-1][j-1]-cm[i-1][j-1])+(cm[i+k-1][j+k-1]-cm[i-1][j+k-1]);
        else
            cisum = cisum-(cm[i+k-1][j-1])+(cm[i+k-1][j+k-1]);
      // cout<<"cisum: "<<cisum<<"\n";
      maxSum = max(maxSum,cisum);
    }
  }
  return maxSum;
}

int main(){
  int m,n;
  int k;
  cin>>m>>n;

  vector<vector<int>> mat(m,vector<int>(n,0));
  vector<vector<int>> rowPrefixSum(m,vector<int>(n,0));
  vector<vector<int>> columnPrefixSum(m,vector<int>(n,0));

  for(int i = 0;i<m;i++){
    for(int j = 0; j<n;j++){
      cin>>mat[i][j];
    }
  }
  cin>>k;
  getRowPrefixSum(m,n,rowPrefixSum,mat);
  getColumnPrefixSum(m,n,columnPrefixSum,mat);

  // cout<<"Row"<<"\n";
  // display(m,n,rowPrefixSum);
  // cout<<"Col"<<"\n";
  // display(m,n,columnPrefixSum);
  if(k>min(m,n)){
    cout<<"Maximum size of k can be: "<<min(m,n)<<endl;
    return 1;
  }
  cout<<"Max Sum: " << getMaxMatrixSum(m,n,k,rowPrefixSum,columnPrefixSum,mat)<<endl;
  return 1;
}