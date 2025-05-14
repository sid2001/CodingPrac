#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

/**
 * Display the matrix elements in a m x n grid.
 *
 * @param m the number of rows in the matrix
 * @param n the number of columns in the matrix
 * @param mat reference to the matrix to be displayed
 *
 * @return void
 *
 * @throws None
 */
void display(int m,int n,vector<vector<int>> &mat){
  for(int i = 0;i<m;i++){
    for(int j = 0; j<n;j++){
      cout<<mat[i][j]<<" ";
    }
    cout<<"\n";
  }
}

/**
 * Generate a sub-matrix of size k starting from position (x, y) in the given matrix.
 *
 * @param mat the matrix from which to generate the sub-matrix
 * @param x the starting x-coordinate of the sub-matrix
 * @param y the starting y-coordinate of the sub-matrix
 * @param k the size of the sub-matrix
 *
 * @return void
 */
void dispalySubMatrix(vector<vector<int>> &mat,int x,int y,int k){
  for(int i = x;i<x+k;i++){
    for(int j = y;j<y+k;j++){
      cout<<mat[i][j]<<" ";
    }
    cout<<"\n";
  }
  return;
}
/**
 * Calculate the prefix sum of each row in a matrix.
 *
 * @param m the number of rows in the matrix
 * @param n the number of columns in the matrix
 * @param preMatrix reference to the matrix to store the prefix sums
 * @param mat the input matrix
 *
 * @return void
 *
 */
void getRowPrefixSum(int m,int n,vector<vector<int>> &preMatrix,vector<vector<int>> &mat){
  for(int i = 0;i<m;i++){
    for(int j = 0; j<n;j++){
      preMatrix[i][j] = j==0?mat[i][j]:preMatrix[i][j-1] + mat[i][j];
    }
  }
  return;
}

/**
 * Calculate the prefix sum of each column in the matrix.
 *
 * @param m the number of rows in the matrix
 * @param n the number of columns in the matrix
 * @param preMatrix the matrix to store the prefix sums
 * @param mat the input matrix to calculate prefix sums for
 *
 * @return void
 */
void getColumnPrefixSum(int m,int n,vector<vector<int>> &preMatrix,vector<vector<int>> &mat){
  for(int i = 0;i<n;i++){
    for(int j = 0; j<m;j++){
      preMatrix[j][i] = j==0?mat[j][i]:preMatrix[j-1][i] + mat[j][i];
    }
  }
  return;
}


/**
 * Find the maximum sum submatrix in the given 2D matrix.
 *
 * @param m The number of rows in the matrix
 * @param n The number of columns in the matrix
 * @param k The size of the submatrix
 * @param rm The row-wise prefix sum matrix
 * @param cm The column-wise prefix sum matrix
 * @param mat The input 2D matrix
 * @param x The row index of the top-left corner of the submatrix with maximum sum
 * @param y The column index of the top-left corner of the submatrix with maximum sum
 *
 * @return A vector containing the row index, column index, and maximum sum of the submatrix
 */
vector<int> getMaxMatrixSum(int m,int n,int k,vector<vector<int>> &rm,vector<vector<int>> &cm,vector<vector<int>> &mat,int &x,int &y){
  int isum = 0;
  int cisum = 0;
  int maxSum = INT_MIN;
  for(int i = 0;i<k;i++){
    isum += rm[i][k-1];
  }
  cisum = isum;
  for(int i = 0;i<=m-k;i++){
    if(i>0){
      isum = isum - (rm[i-1][k-1])+(rm[i+k-1][k-1]);
      cisum = isum;
    }
    // cout<<"isum: "<<isum<<"\n";
    for(int j = 0; j<=n-k;j++){
      if(j>0)
        if(i>0)
            cisum = cisum-(cm[i+k-1][j-1]-cm[i-1][j-1])+(cm[i+k-1][j+k-1]-cm[i-1][j+k-1]);
        else
            cisum = cisum-(cm[i+k-1][j-1])+(cm[i+k-1][j+k-1]);
      // cout<<"cisum: "<<cisum<<"\n";
      maxSum = max(maxSum,cisum);
      if(maxSum==cisum){
        x = i;
        y = j;
      }
    }
  }
  vector<int> vec = {x,y,maxSum};
  return vec;
}

/**
 * The main function for handling matrix operations.
 *
 * @param None
 *
 * @return 1 on successful execution
 */
int main(){
  int m,n;
  int k;
  int x=-1;
  int y=-1;
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
  std::vector<int> result = getMaxMatrixSum(m,n,k,rowPrefixSum,columnPrefixSum,mat,x,y);
  dispalySubMatrix(mat,x,y,k);
  cout<<"Maximum sum: "<<result[2]<<endl;
  
  return 1;
}