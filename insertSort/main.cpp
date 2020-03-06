#include <iostream>


/* Funtion to insert element at position. shifts array up or down */
void insert(const int &a, const int &b, int *arr){

  int copy = arr[a];
  
  if (a == b)
    return;

  if(a < b){
    int innercopy = arr[a+1];
    for(int i = a; i < b; ++i){
      int copy1 = arr[a+2];
      arr[i] = innercopy;
      innercopy = copy1;
    }
    arr[b] = copy;
    
  }

  
  if(a > b){
    int innercopy = arr[a -1];
    for(int i = a; i > b; --i){
       int copy1 = arr[i -2];
       arr[i] = innercopy;
       innercopy = copy1;
			       
    }
    arr[b+1] = copy;
    
  }

}


/*Print Array function*/
void pa(int size,int *arr){
  std::cout<<"{";
  for (int i= 0; i < size; i++){ 
    std::cout << arr[i];
    if(i < (size -1)){
      std::cout <<",";
   }
  }
    std::cout<<"}\n";
     
}

/* Actual insert Sort method */

void insertSort(int AS,int *arr){
for(int i = 1; i <= AS; ++i){
    for(int j = i-1; j >=0; --j){
      if(arr[i] >= arr[j]){
	break;
      }else{
	if((arr[i] < arr[j] && arr[i] >= arr[j-1]) ||(j-1) == -1){
	  insert(i,j-1,arr);
	  break;
	}
      }
    }

  }
}
  
int main(){
  const int AS = 8;//Array Size
  int arr[AS] = {6,5,3,1,8,7,2,4}; //Test Array
  pa(AS,arr);

  insertSort(AS,arr);
  pa(AS,arr);
  return 0;
}



