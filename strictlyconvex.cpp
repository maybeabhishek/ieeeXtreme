#include <iostream> 
#include <cmath>
using namespace std; 

// Define Infinite (Using INT_MAX caused overflow problems) 
#define INF 10000 

struct Point 
{ 
	double x; 
	double y; 
}; 

// Given three colinear points p, q, r, the function checks if 
// point q lies on line segment 'pr' 
bool onSegment(Point p, Point q, Point r) 
{ 
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
			q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
		return true; 
	return false; 
} 

// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
int orientation(Point p, Point q, Point r) 
{ 
	double val = (q.y - p.y) * (r.x - q.x) - 
			(q.x - p.x) * (r.y - q.y); 

	if (val == 0) return 0; // colinear 
	return (val > 0)? 1: 2; // clock or counterclock wise 
} 

// The function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
	// Find the four orientations needed for general and 
	// special cases 
	int o1 = orientation(p1, q1, p2); 
	int o2 = orientation(p1, q1, q2); 
	int o3 = orientation(p2, q2, p1); 
	int o4 = orientation(p2, q2, q1); 

	// General case 
	if (o1 != o2 && o3 != o4) 
		return true; 

	// Special Cases 
	// p1, q1 and p2 are colinear and p2 lies on segment p1q1 
	// if (o1 == 0 && onSegment(p1, p2, q1)) return true; 

	// // p1, q1 and p2 are colinear and q2 lies on segment p1q1 
	// if (o2 == 0 && onSegment(p1, q2, q1)) return true; 

	// // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
	// // if (o3 == 0 && onSegment(p2, p1, q2)) return true; 

	// // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
	// if (o4 == 0 && onSegment(p2, q1, q2)) return true; 

	return false; // Doesn't fall in any of the above cases 
} 

// Returns true if the point p lies inside the polygon[] with n vertices 
bool isInside(Point polygon[], int n, Point p) 
{ 
	// There must be at least 3 vertices in polygon[] 
	if (n < 3) return false; 

	// Create a point for line segment from p to infinite 
	Point extreme = {INF, p.y}; 

	// Count intersections of the above line with sides of polygon 
	int count = 0, i = 0; 
	do
	{ 
		int next = (i+1)%n; 

		// Check if the line segment from 'p' to 'extreme' intersects 
		// with the line segment from 'polygon[i]' to 'polygon[next]' 
		if (doIntersect(polygon[i], polygon[next], p, extreme)) 
		{ 
			// If the point 'p' is colinear with line segment 'i-next', 
			// then check if it lies on segment. If it lies, return true, 
			// otherwise false 
			if (orientation(polygon[i], p, polygon[next]) == 0) 
			return onSegment(polygon[i], p, polygon[next]); 

			count++; 
		} 
		i = next; 
	} while (i != 0); 
    // cout<<count<<endl;
	// Return true if count is odd, false otherwise 
	return count%2; // Same as (count%2 == 1) 
} 

int fact(int n) {
   if (n == 0 || n == 1)
      return 1;
   else
      return n * fact(n - 1);
}


// Driver program to test above functions 
int main() 
{ 
    int n,m;
    double x,y;
    double count = 0;
    cin>>n>>m;
    Point polygon1[n];
    Point points[m];
    Point inside[m];
    Point outside[m];
    
    for(int i = 0; i<n;i++){
        cin>>x>>y;
        polygon1[i]={x,y};
    }
    
    for(int i = 0; i<m;i++){
        cin>>x>>y;
        points[i]={x+0.0003f,y+0.0003f};
    }
    
	n = sizeof(polygon1)/sizeof(polygon1[0]); 
    int numInside=0;
    int numOutside = 0;
	int curr = -1;
	int othercurr = -1;
	for(int i =0; i<m; i++){
	    if(isInside(polygon1, n, points[i])){
	        inside[++curr]=points[i];
	        numInside++;
	    }
	    else{
	        outside[++othercurr]=points[i];
	    }
	}
	numOutside= m- numInside;
    count += fact(numInside) / (fact(2) * fact(numInside-2));
    // cout<<count<<endl;    
    int flag = 0;
   
   
    for(int i =0; i<numOutside; i++){
        for(int j=i+1; j<numOutside;j++){
            flag = 0;
            for(int k = 0; k<n; k++){
                if((k+1<n) && (j<numOutside)&&doIntersect(outside[i],outside[j],polygon1[k],polygon1[k+1])){
                    flag=1;  
                    // cout<<"First point "<<outside[i].x<<","<<outside[i].y<<"  "<<i<<endl;
                    // cout<<"Second point "<<outside[j].x<<","<<outside[j].y<<"  "<<j<<endl<<endl;
                    break;
                }
            }
            if(flag==0)
                count++;
        }    
    }
    cout<<floor(count);
	return 0; 
}


