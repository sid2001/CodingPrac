#include <vector>
#include <iostream>

using namespace std;

struct Point {
  int x, y;
};
void swap(Point &a, Point &b){
  Point temp = a;
  a = b;
  b = temp;
  return;
}
int dist(Point a,Point b){
  return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
bool orientation(Point &p,Point &q,Point &curr){
  int val = (p.x-curr.x)*(q.y-p.y) - (p.y-curr.y)*(q.x-p.x);
  if(val==0){
    if(dist(p,curr)<dist(q,curr)){
      return true;
    }else{
      return false;
    }
  }else{
    return val<0?true:false;
  }
}

void display(vector<Point> &vec,int len){

  for(int i =0;i<len;i++){
    cout<<vec[i].x<<","<<vec[i].y<<"\n";
  }
  
  return;
}
void convexHull(vector<Point> &points, int n, Point lowest) {
  vector<Point> hull;
  hull.push_back(lowest);
  Point curr = hull.back();
  Point p = points[1];
  for(int i = 2;i<n;i++){
    if(orientation(p, points[i], curr)) {
      p = points[i];
    }
  }
  hull.push_back(p);
  display(hull,hull.size());
  curr = hull.back();
  while(curr.x!=lowest.x||curr.y!=lowest.y) {
    Point low = points[0];
    for(int i = 0;i<n;i++){
      if(orientation(low,points[i],curr)){
        low = points[i];
      }
    }
    hull.push_back(low);
    curr = hull.back();
  }
  display(hull,hull.size());
  return;
}
int main() {
  int n; 
  cin >> n;
  vector<Point> points(n,{0,0});
  Point lowest;
  int indx = 0;
  for(int i = 0; i < n; i++){
    cin>>points[i].x >> points[i].y;
    if(i==0) {
      lowest = points[i];
      continue;
    }else if(lowest.y>=points[i].y){
      lowest = points[i];
      indx = i;
    }
  }
  swap(points[indx],points[0]);
  convexHull(points,n,lowest);
  return 0;  
}