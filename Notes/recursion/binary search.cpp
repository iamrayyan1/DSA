// we have learnt this using loops


// linear search through recursion

bool linearsearch(int arr[], int x, int index, int n){
    if(index==n){
        return 0;
    }
    if(arr[index]==x){
        return 1;
    }
    return linearsearch(arr, x, index+1, n);
}

// returning index
int returnIndex(int arr[], int x, int index, int n){
    if(index==n){
        return -1;
    }
    if(arr[index]==x){
        return index;
    }
    return returnIndex(arr, x, index+1, n);
}



// binary search 
// start, mid, end


bool  binarySearch(int arr[], int start, int end, int x){
    if(start>end){
        return 0;
    }

    int mid = (start+end)/2;
    
    if(arr[mid]==x){
        return 1;
    }
    else if(arr[mid]>x){
        return binarySearch(arr, mid+1, end, x);
    }
    else
        return binarySearch(arr, start, mid-1, x);
}