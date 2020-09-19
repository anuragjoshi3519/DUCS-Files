import pandas as pd

def insertion_sort(meteorological_data):
    '''
    Input: list of Meteorological data records (sorted on time)
    Output: list of Meteorological data records (sorted on city name)
    '''
    for index in range(1,len(meteorological_data)):
        
        key = meteorological_data[index]
        j=index-1
        
        while(j>=0 and meteorological_data[j]['city']>key['city']):
            meteorological_data[j+1] = meteorological_data[j]
            j-=1
        meteorological_data[j+1] = key
        
    return meteorological_data


def main():
    
    # reading unsorted meteo data csv file
    meteorological_data_unsorted = pd.read_csv('data_unsorted.csv').to_dict(orient='records')

    # sorting meteorological data records with respect to city name
    meteorological_data_sorted = insertion_sort(meteorological_data_unsorted)

    # saving sorted meteorological data to a csv file
    pd.DataFrame(meteorological_data_sorted).to_csv('data_sorted.csv',index=False)
    
if __name__=='__main__':
    main()