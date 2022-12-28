//Declare an array of type int
int array[50];

//Initialize a variable to store the size of the array
int size = 0;
int i =0;
int j =0;

//Iterate through the array
for(int i = 0; i < 50; i++)
{
    // Get the current element
    int currentElement = array[i];
 
    // Iterate through the array again
    for(int j = i+1; j < size; j++)
    {
        // Check if the current element is equal to the next element
        if(array[j] == currentElement)
        {
            // If they are equal, remove the element
            for(int k = j; k < size-1; k++)
            {
                array[k] = array[k+1];
            }
 
            // Decrement the size of the array
            size--;
        }
    }
}

return array;