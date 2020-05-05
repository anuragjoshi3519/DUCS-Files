Steps to follow:

1) Either download or clone the repository.
2) Using terminal go to the cloned repo directory and run : `pip install -r requirements.txt` 
3) Download your location history data in JSON format from [here](https://takeout.google.com/).
4) Put the downloaded 'Location History.Json' file into the cloned repository's DCN-Assignment-2 folder.
5) Now using terminal head to DCN-Assignment-2 folder and run : `python getLocationHistory.py`

 _Now you will have a file by the name 'locationHistory.csv' which consists the list of the location trail of your device in CSV format._
 
6) To plot the locations on a map, run : `python plotLocations.py`

**Note:**

If you face `ModuleNotFoundError: No module named '_tkinter'` error due to `matplotlib.pyplot` library.

do this:

```bash
pip uninstall matplotlib
python -m pip install --upgrade pip
pip install matplotlib
```

