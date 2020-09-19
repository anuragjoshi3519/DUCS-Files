# Plotting Location History Data On Map

import pandas as pd
import matplotlib.pyplot as plt

# importing locations list from csv file
locationsTrail = pd.read_csv('locationHistory.csv')

# defining bounding box for all travelled locations
# Note: You can change the bounding box coordinates if they are not working out for you
BoundingBox=(72.673,89.912,21.657,31.541)  # (min longitude , max longitude , min latitude, max latitude)

# reading image of map
mapImage = plt.imread('Images/mapImage.png')

# plotting locations on the map

fig, ax = plt.subplots(figsize = (16,20))
ax.scatter(locationsTrail.longitude, locationsTrail.latitude, zorder=1, alpha= 0.01, c='b', s=30)
ax.set_title('Plotting Location History Data')
ax.set_xlim(BoundingBox[0],BoundingBox[1])
ax.set_ylim(BoundingBox[2],BoundingBox[3])
ax.imshow(mapImage, zorder=0, extent = BoundingBox, aspect= 'equal')
plt.show()

