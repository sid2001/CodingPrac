#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;

struct Point {
  int x,y;
};

void display(vector<Point> &vec,int len){

  for(int i =0;i<len;i++){
    cout<<vec[i].x<<","<<vec[i].y<<"\n";
  }
  
  return;
}
// bool compare(vector<int> &a, vector<int> &b){
//   return a[1] > b[1]?true:a[1]==b[1]?a[0]<b[0]:false;
// }
void swap(Point &a,Point &b){
  Point temp = a;
  a = b;
  b = temp;
}
void findLowest(Point &lowest,vector<Point> &points,int n){
  int indx = 0;
  for(int i = 0; i < n; i++){
    if(points[i].y <= lowest.y){
      indx = i;
      lowest = points[i].y==lowest.y?points[i].x<lowest.x?points[i]:lowest:points[i];
    }
  }
  swap(points[indx],points[0]);
}

bool orientation(Point p,Point q,Point r){
  int val = (q.y - p.y)*(r.x-q.x) - (q.x - p.x)*(r.y - q.y);
  if(val==0){
    if ((p.y-r.y)*(p.y-r.y) + (p.x-r.x)*(p.x-r.x) < (p.y-r.y)*(p.y-r.y) + (p.x-r.x)*(p.x-r.x))
      return false;
    else
      return true;
  }else{
    return val<0?true:false;
  }
}

void convexHull(vector<Point> &points,int n){
  Point lowest = points[0];
  findLowest(lowest,points,n);

  sort(points.begin()+1,points.end(),[&](Point a,Point b){
    return orientation(lowest,a,b);
  });
  // display(points,n);
  vector<Point> hull;
  hull.push_back(lowest);
  Point p = points[1];
  // cout<<orientation(Point{2,3},Point{3,1},Point{5,5})<<"\n";
  points.push_back(lowest);
  for(int i = 2; i <= n; i++){
    if(orientation(p,points[i],hull.back())){
      hull.push_back(p);
      p = points[i];
    }else{
      p = points[i];
    }
  }
  display(hull,hull.size());
}
int main(){
  int n;
  cin >> n;
  vector<Point> points(n,{0,0});

  for(int i = 0; i < n; i++){
    cin>>points[i].x >> points[i].y;
  }

  convexHull(points,n);
  return 0;
}