import random
import matplotlib.pyplot as plt
import seaborn as sns


def linear_search(arr,item):
    '''
    Objective: To find the position of given input 'item' in the given array 'arr'
    Input: arr   - an array of numbers
           item  - item to be found in the array 'arr'
    Return value: Position of the element (if found), otherwise array_length +1 ( return value 
                  could also be deemed as the number of key comparisons to search 'item' in 'arr')
    '''

    for i in range(len(arr)):
        if arr[i]==item:
            return i+1

    return len(arr)+1  


def plot_linear_search():
    '''
    Objective : Plots the graph between array_size and key comparisons to find element in array (of array_size) 
    in best_case, average_case & worst_case
    '''
    best_case = []
    average_case = []
    worst_case = []
    
    array_sizes = list(range(10,101,5))
    
    for size in array_sizes:
        comparisons = []
        
        arr = list(range(size))

        for i in range(len(arr)+1):
            if i == len(arr):
                pos = linear_search(arr,len(arr))
                worst_case.append(pos)
                comparisons.append(pos)
            else:
                pos = linear_search(arr,arr[i])
                if i==0:
                    best_case.append(pos)
                comparisons.append(pos)

        average_case.append(sum(comparisons)/len(comparisons)) 
        
    sns.set(style="darkgrid")    
    ax = sns.lineplot(array_sizes,average_case)
    sns.lineplot(array_sizes,best_case)
    sns.lineplot(array_sizes,worst_case)
    ax.set_xlabel("Array Size")
    ax.set_ylabel("Key Comparisons")
    ax.legend(['Average Case','Best Case','Worst Case'])
    ax.set_title("Array Size v/s Key-Comparisons")
    ax.figure.set_size_inches(11,7)
    sns.despine() 
    plt.show()
    
if __name__=='__main__':

    plot_linear_search()
