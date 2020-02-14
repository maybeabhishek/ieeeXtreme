#include <cmath>
#include <iostream>
using namespace std;

// Driver program
int main() {
  long long n, a, b;
	long long tempN;
	long long count;
  cin >> n >> a >> b;

  long long ub = 0;

  // decrement b while its not in range
  for (int i = b; i >= a; i--) {
    bool valid = false;
		count = 0;
		tempN = n;
    while (tempN > 0) {
      if (tempN >= a && tempN <= b) {
        valid = true;
        break;
      }
			count++;
      tempN -= i;
    }

    if (valid) {
      ub = i;
      break;
    }
    // while ((n % i > b || n % ub < a) && ub >= a){
    // 	cout<<n%ub<<" "<<ub+(n%ub)<<endl;
    // 	if((ub+(n%ub)) >= a && (ub+(n%ub)) <= b) break;
    // 	ub--;
    // }
  }

//   cout << ub << " " << tempN <<" "<<count<< endl;
  if (ub < a) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    if (a < ub) {
      cout << tempN << " ";

      for (int i = 0; i < count-1; i++) {
        cout << ub << " ";
      }
      cout<<ub;
    } else {
      for (int i = 0; i < count; i++) {
        cout << ub << " ";
      }
      cout << tempN;
    }
  }

  return 0;
}
