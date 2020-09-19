import pandas as pd

def insertion_sort(index_table):
    '''
    Input: list of (index,city_name) of Meteorological data records (sorted on time)
    Output: list of (index,city_name) of Meteorological data records (sorted on city name)
    '''
    index_table = index_table.copy()
    for index in range(1,len(index_table)):
        
        key = index_table[index]
        j=index-1
        
        while(j>=0 and index_table[j]['city']>key['city']):
            index_table[j+1] = index_table[j]
            j-=1
        index_table[j+1] = key
        
    return index_table

def main():
    
    # reading unsorted meteorological data csv file
    meteorological_data_unsorted = pd.read_csv('data_unsorted.csv')

    # creating index table from the meteorological data & saving the table to a csv file
    index_table_unsorted = meteorological_data_unsorted[['index','city']].to_dict(orient='records')
    pd.DataFrame(index_table_unsorted).set_index('index').to_csv('index_table_unsorted.csv')

    # sorting the records in index table using insertion sort & saving the table to a csv file
    index_table_sorted = insertion_sort(index_table_unsorted)
    pd.DataFrame(index_table_sorted).set_index('index').to_csv('index_table_sorted.csv')
    
    # Using indices of sorted index table to arrange the original meteorological data in sorted order
    sorted_indices = list(pd.DataFrame(index_table_sorted)['index'])
    meteorological_data_sorted = meteorological_data_unsorted.set_index('index').iloc[sorted_indices]

    # saving sorted meteorological data to a csv file
    meteorological_data_sorted.to_csv('data_sorted.csv')
    
if __name__=='__main__':
    main()