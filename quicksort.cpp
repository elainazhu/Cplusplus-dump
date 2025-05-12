#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
ll number_of_integers, list_of_integers[100000],sorted_list_of_integers[100000],target;
ll random_list[110],average;
//Q1: function to perform quicksort
void quicksort(ll list_of_integers[]){
	sort(list_of_integers,list_of_integers+number_of_integers);
	for(int i=0; i<=number_of_integers; i++){
		sorted_list_of_integers[i]=list_of_integers[i];
	}
	// sorted array is stored in b
}

/*
A sorting algorithm that sorts in nlogn (merge sort):
1. split the list into 2
2. sort the list using the algorithm
3. combine the list by comparing each pair of numbers in the 2 lists(O(n))
4. repeat steps 1-3 log(n) times until there is only 1 number in each array, then combine them 
this will take n*log(n) time complexity
*/

/*
testcases for quicksort:
5
3 2 4 1 5

4 
2 3 1 4

7 
1 2 3 4 5 6 7

5 
2 3 3 4 5
*/

//Q2: function to perform binary search
ll binarysearch(ll sorted_list_of_integers[], ll target){
	// s is start, e is end, s exclusive, e inclusive
	int s = -1, e = number_of_integers, m; 
	int number_of_comparisons=0;
	while (m = (s+e)/2, e-s > 1) {
		//guessed number is too low
      	if ( sorted_list_of_integers[m]<target ) s = m;
      	//guessed number is too high
		else e = m;
		//counting number of comparisons
		number_of_comparisons++;
	}
	if(sorted_list_of_integers[e]==target) cout<<"Found"<<endl;
	else cout<<"Not Found"<<endl;
	return number_of_comparisons;
}

/*
Testcases for binary search:
5 4
1 2 3 4 5

5 4
1 2 2 2 5

6 1
1 2 3 4 4 6

5 1
0 0 0 0 0
*/

int main(){
	//faster input output
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//open input output files on my laptop
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // input
    cin>>number_of_integers>>target;
    for(int i=0; i<number_of_integers; i++){
    	cin>>list_of_integers[i];
    }

	//Q1: function to perform quicksort
   	quicksort(list_of_integers);
    for(int i=0; i<number_of_integers; i++){
    	cout<<sorted_list_of_integers[i]<<" ";
    }
    cout<<endl;

	//Q2: function to perform binary search
    cout<<binarysearch(sorted_list_of_integers,target)<<endl;

    //Q3(a): generating a list of 100 random numbers
    for(int i=0; i<100; i++){
    	random_list[i]=rand()%200+1;
    }
    number_of_integers=100;
    //Q3(b)
    quicksort(random_list);
    //Q3(c),(d)
    for(int i=0; i<20; i++){
    	average+=binarysearch(sorted_list_of_integers, rand()%200+1);
    }
    //Q3(e)
    average/=20;
    cout<<average;
    // average is around log2(100), as binary search takes log2(n) time
}