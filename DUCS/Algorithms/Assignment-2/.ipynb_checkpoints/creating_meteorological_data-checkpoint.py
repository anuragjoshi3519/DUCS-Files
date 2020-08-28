import numpy as np
import pandas as pd
np.random.seed(14)

def main():
    
    city = ['Delhi','Bangalore','Mumbai','Hyderabad','Pune','Gujrat','Prayagraj']
    time = []
    for i in range(0,24):
        for j in range(0,60,5):
            time.append(f'{i:02}:{j:02}')
    temperature = [*range(20,35)]
    humidity = [*range(60,90)]
    rainfall = [eval(f'{i:.2f}') for i in [*np.linspace(150,200,60)]]

    data = {
        'index':[*range(80)],
        'time':time[50:130],
        'city':np.random.choice(city,80),
        'temperature':np.random.choice(temperature,80),
        'humidity':np.random.choice(humidity,80),
        'rainfall':np.random.choice(rainfall,80),
    }
    meteorological_data = pd.DataFrame(data)
    meteorological_data.to_csv('data_unsorted.csv',index=False)

if __name__=='__main__':
    main()