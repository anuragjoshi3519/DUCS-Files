# Loading, Preprocessing and Saving location history data as CSV file 

## uncomment the command below to install pandas
#!pip install pandas

import json
import pandas as pd
from datetime import datetime

# loading location history data
with open('Location History.json','r') as f:
    locationHistory = json.load(f)
    
print(f'Total number of location entries found: {len(locationHistory["locations"])}')

# initializing dictionary
locationList = {
    'timestamp': [],
    'latitude' : [],
    'longitude': [],
}

# getting information from locationHistory object
for location in locationHistory['locations']:
    
    # getting location info for locations having accuracy less than 1000
    if location['accuracy']<1000:
        lon = location['longitudeE7']/float(1e7)
        lat = location['latitudeE7']/float(1e7)
        
        # removing wrong location data
        if lon>68.18 and lat>8.0 and lon<97.4 and lat<35.5:
            locationList['timestamp'].append(location['timestampMs'])
            locationList['latitude'].append(lat)
            locationList['longitude'].append(lon)
      
# creating DataFrame object
locationDf = pd.DataFrame(locationList)

# creating new datetime field using timestamps
dates=[datetime.fromtimestamp(int(timestamp)/1000).strftime("%d/%m/%Y %H:%M:%S")        for timestamp in locationDf['timestamp']]
locationDf['datetime'] = dates

# converting location list to csv
locationDf.to_csv('locationHistory.csv',index=False)

print('Successfully stored data in csv file.')      
print(f'Total number of location entries saved: {len(locationList["latitude"])}')    

